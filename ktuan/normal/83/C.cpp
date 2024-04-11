#include <iostream>
#include <sstream>
#include <cstdio>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <string>
#include <cstdlib>
using namespace std;

#define Rep(i,n) for(int i=0;i<(n);++i)
#define For(i,a,b) for(int i=(a);i<=(b);++i)
#define Ford(i,a,b) for(int i=(a);i>=(b);--i)
#define fi first
#define se second
#define pb push_back
#define MP make_pair

typedef pair<int,int> PII;
typedef vector<int> VI;

int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};

PII st, en;

int m, n, k;
char a[55][55];
bool b[55][55];
int d[55][55];
string Z[55][55];
bool inq[55][55];

int solve1() {
    queue<PII> q;
    q.push(st);
    memset(d,0x1f,sizeof(d));
    d[st.fi][st.se] = 0;
    while(!q.empty()) {
        int u = q.front().fi;
        int v = q.front().se;
        q.pop();
        Rep(h,4) {
            int x = u + dx[h];
            int y = v + dy[h];
            if(0<=x&&x<m&&0<=y&&y<n && b[x][y]) {
                if(d[x][y] > d[u][v] + 1) {
                    d[x][y] = d[u][v] + 1;
                    q.push(MP(x,y));    
                }
            }   
        }
    }   
    return d[en.fi][en.se];
}

string solve2() {
    queue<PII> q;
    memset(inq,0,sizeof(inq));
    q.push(st);
    inq[st.fi][st.se] = true;
    Z[st.fi][st.se] = "";
    while(!q.empty()) {
        int u = q.front().fi;
        int v = q.front().se;
        q.pop();
        Rep(h,4) {
            int x = u + dx[h];
            int y = v + dy[h];
            if(0<=x&&x<m&&0<=y&&y<n && b[x][y]) {
                if(d[x][y] == d[u][v] + 1) {
                    if(!inq[x][y]) {
                        q.push(MP(x,y));    
                        inq[x][y] = true;
                        Z[x][y] = Z[u][v] + a[x][y];
                    }
                    else if(Z[x][y] > Z[u][v] + a[x][y]) Z[x][y] = Z[u][v] + a[x][y];
                }
            }   
        }
    }   
    return Z[en.fi][en.se];
}

int main() {
    scanf("%d%d%d", &m, &n, &k);
    gets(a[0]);
    Rep(i,m) gets(a[i]);
    Rep(i,m) Rep(j,n) if(a[i][j] == 'S') st = MP(i,j); else if(a[i][j] == 'T') en = MP(i,j);
    int res = 50 * 50 * 50;
    Rep(c1,26) Rep(c2,c1+1) Rep(c3,c2+1) Rep(c4,c3+1) {
        set<int> se; se.insert(c1); se.insert(c2); se.insert(c3); se.insert(c4);
        if(se.size() == k) {
            memset(b,0,sizeof(b));
            Rep(i,m)Rep(j,n) if(a[i][j] == 'S' || a[i][j] == 'T' || se.count(a[i][j]-'a'))
                b[i][j] = true;
            int len = solve1();
            res = min( res, len);
        }   
    }
    if(res == 50 * 50 * 50) cout << -1 << endl;
    else {
    
    string beststr = "";
    
    Rep(c1,26) Rep(c2,c1+1) Rep(c3,c2+1) Rep(c4,c3+1) {
        set<int> se; se.insert(c1); se.insert(c2); se.insert(c3); se.insert(c4);
        if(se.size() == k) {
            memset(b,0,sizeof(b));
            Rep(i,m)Rep(j,n) if(a[i][j] == 'S' || a[i][j] == 'T' || se.count(a[i][j]-'a'))
                b[i][j] = true;
            int len = solve1();
            if(len == res) {
                string path = solve2(); 
                if(beststr == "" || beststr > path) beststr = path;
            }
        }   
    }
    
    beststr = beststr.substr(0,beststr.length()-1);
    cout << beststr << endl;
        
    }
    return 0;
}