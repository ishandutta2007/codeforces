#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;

// variables for find bridges
vector<int> ori[200002];
int px[200002], py[200002], brid[200002];

int chk[200002], up[200002];

int gety(int x, int e)
{
    return x == px[e] ? py[e] : px[e];
}

void dfs(int x, int l, int d)
{
    chk[x] = 1; up[x] = d;
    for (int i=0;i<ori[x].size();i++){
        int e = ori[x][i];
        if (e == l) continue;

        int y = gety(x,e);
        if (chk[y] == 0){
            dfs(y,e,d+1);
            if (up[y] > d) brid[e] = 1;
        }
        if (up[x] > up[y]) up[x] = up[y];
    }
}

// variables for make supernodes
vector<int> sup[200002];
int par[200002], grp[200002], pri[200002];

int find(int x)
{
    if (par[x] != x) par[x] = find(par[x]);
    return par[x];
}

// get answer
int in[200002], out[200002], erase[200002];
int dbl[200002][18], dep[200002];

void go(int x, int p)
{
    chk[x] = 1;
    dbl[x][0] = p; dep[x] = dep[p] + 1;
    for (int i=1;i<18;i++) dbl[x][i] = dbl[dbl[x][i-1]][i-1];
    for (int y : sup[x]) if (!chk[y]) go(y,x);
}

int lca(int x, int y)
{
    if (dep[x] > dep[y]) return lca(y,x);
    int dif = dep[y] - dep[x];
    for (int k=0;k<18;k++) if (dif & (1 << k)) y = dbl[y][k];
    if (x == y) return x;
    for (int k=17;k>=0;k--){
        int px = dbl[x][k];
        int py = dbl[y][k];
        if (px != py) x = px, y = py;
    }
    x = dbl[x][0]; y = dbl[y][0];
    return x;
}

int under(int x)
{
    chk[x] = 1;
    int pos = in[x], neg = out[x];
    for (int y : sup[x]) if (!chk[y]){
        int c = under(y);
        if (c > 0) pos += c;
        if (c < 0) neg -= c;
    }
    pos -= erase[x];
    neg -= erase[x];
    if (pos == 0) return -neg;
    if (neg == 0) return pos;
    return 100000000;
}

int main()
{
    // input
    int N,M,K;
    scanf ("%d %d %d",&N,&M,&K);
    for (int i=1;i<=M;i++){
        scanf ("%d %d",&px[i],&py[i]);
        ori[px[i]].push_back(i);
        ori[py[i]].push_back(i);
    }

    // find bridges
    for (int i=1;i<=N;i++) if (!chk[i]) dfs(i,0,0);

    // make supernodes
    for (int i=1;i<=N;i++) par[i] = i;
    for (int i=1;i<=M;i++) if (!brid[i]){
        int x = find(px[i]);
        int y = find(py[i]);
        if (x != y) par[x] = y;
    }
    int G = 0;
    for (int i=1;i<=N;i++)if (par[i] == i){
        grp[i] = ++G;
        pri[G] = i;
    }
    for (int i=1;i<=N;i++) grp[i] = grp[find(i)];
    for (int i=1;i<=M;i++){
        int x = grp[find(px[i])];
        int y = grp[find(py[i])];
        if (x != y){
            sup[x].push_back(y);
            sup[y].push_back(x);
        }
    }
    for (int i=1;i<=G;i++){
        sort(sup[i].begin(),sup[i].end());
        sup[i].erase(unique(sup[i].begin(),sup[i].end()),sup[i].end());
    }

    for (int i=1;i<=G;i++) chk[i] = 0;
    for (int i=1;i<=G;i++) if (!chk[i]) go(i,0);
    for (int i=0;i<K;i++){
        int x,y; scanf ("%d %d",&x,&y);
        x = grp[find(x)]; y = grp[find(y)];
        if (x != y){
            in[x]++; out[y]++;
            int z = lca(x,y);
            if (z == 0){
                puts("No");
                return 0;
            }
            erase[z]++;
        }
    }
    
    for (int i=1;i<=G;i++) chk[i] = 0;
    for (int i=1;i<=G;i++) if (!chk[i]){
        if (under(i) != 0){
            puts("No");
            return 0;
        }
    }

    puts("Yes");
    return 0;
}