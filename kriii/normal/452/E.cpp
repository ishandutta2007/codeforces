#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAXN = 900030;
int N, gap, sa[MAXN], pos[MAXN], tmp[MAXN], lcp[MAXN], grp[MAXN]; char S[MAXN];
int ans[MAXN/3], minlcp[MAXN][20], poslcp[MAXN][20], grpcnt[MAXN][3], blockn[MAXN];

bool sufCmp(int i, int j)
{
    if (pos[i] != pos[j]) return pos[i] < pos[j];
    i += gap;
    j += gap;
    return (i < N && j < N) ? pos[i] < pos[j] : i > j;
}

int ml(int s, int e)
{
    int sz = e - s + 1, n = blockn[sz], dif = 1<<n;
    return min(minlcp[s][n],minlcp[e-dif+1][n]);
}

int pl(int s, int e)
{
    int sz = e - s + 1, n = blockn[sz], dif = 1<<n;
    if (minlcp[s][n] < minlcp[e-dif+1][n]) return poslcp[s][n];
    return poslcp[e-dif+1][n];
}

const long long mod = 1000000007;
long long gg(int s, int e)
{
    long long p = grpcnt[e+1][0] - grpcnt[s][0];
    long long q = grpcnt[e+1][1] - grpcnt[s][1];
    long long r = grpcnt[e+1][2] - grpcnt[s][2];
    return p * q * r % mod;
}

void go(int len, int s, int e)
{
    long long cnt;
    if ((cnt = gg(s,e)) == 0) return;
    int nl = ml(s,e-1), pos = pl(s,e-1);
    ans[nl] = (ans[nl] + mod - cnt) % mod;
    ans[len] = (ans[len] + cnt) % mod;
    go(nl,s,pos); go(nl,pos+1,e);
}

int main()
{
    char *ed = S; int l = 0x7fffffff;
    for (int i=0;i<3;i++){
        scanf ("%s",ed); int p = strlen(ed);
        if (l > p) l = p;
        ed += p;
        if (i == 0) *ed = '{';
        if (i == 1) *ed = '}';
        ed++;
    }
    int g = 1;
    for (int i=0;S[i];i++){
        if (S[i] == '{' || S[i] == '}') g *= 2;
        else grp[i] = g;
    }

    N = strlen(S);
    for (int i=0;i<N;i++) sa[i] = i, pos[i] = S[i];
    for (gap=1;;gap<<=1)
    {
        sort(sa, sa + N, sufCmp);
        for (int i=0;i<N-1;i++) tmp[i+1] = tmp[i] + sufCmp(sa[i],sa[i+1]);
        for (int i=0;i<N;i++) pos[sa[i]] = tmp[i];
        if (tmp[N-1] == N-1) break;
    }

    for (int i=0,k=0;i<N;i++) if (pos[i] != N - 1)
    {
        for (int j=sa[pos[i]+1];S[i+k]==S[j+k];) k++;
        lcp[pos[i]] = k;
        if (k) k--;
    }
    
    int b = 1, n = 0;
    for (int i=1;i<=N;i++){
        while (b <= i) b *= 2, n++; b /= 2; n--;
         blockn[i] = n;
    }
    for (int i=0;i<N;i++){
        minlcp[i][0] = lcp[i];
        poslcp[i][0] = i;
        if (grp[sa[i]] == 1) grpcnt[i+1][0]++;
        if (grp[sa[i]] == 2) grpcnt[i+1][1]++;
        if (grp[sa[i]] == 4) grpcnt[i+1][2]++;
        for (int k=0;k<3;k++) grpcnt[i+1][k] += grpcnt[i][k];
    }
    for (int b=2,g=1;b<N;b*=2,g++){
        for (int j=0;j<N-b+1;j++){
            if (minlcp[j][g-1] < minlcp[j+b/2][g-1]){
                minlcp[j][g] = minlcp[j][g-1];
                poslcp[j][g] = poslcp[j][g-1];
            }
            else{
                minlcp[j][g] = minlcp[j+b/2][g-1];
                poslcp[j][g] = poslcp[j+b/2][g-1];
            }
        }
    }

    go(0,0,N-1);

    long long a = 0;
    for (int i=0;i<l;i++){
        a += ans[i];
        if (a >= mod) a -= mod;
        printf ("%lld ",a);
    }

    return 0;
}