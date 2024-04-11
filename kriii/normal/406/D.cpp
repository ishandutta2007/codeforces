#include <stdio.h>
#include <vector>
#include <queue>
#include <deque>
using namespace std;

vector<int> G[100040];
int N,M,P[100040][18],Depth[100040]; bool chk[100040];
queue<int> Q;

int up(int x, int d)
{
    int i;
    for (i=17;i>=0;i--) if (d >= (1 << i)){
        x = P[x][i];
        d -= 1 << i;
    }
    return x;
}

int commonancestor(int x, int y)
{
    if (Depth[x] > Depth[y]) return commonancestor(y,x);
    if (Depth[x] < Depth[y]){
        y = up(y,Depth[y]-Depth[x]);
        return commonancestor(x,y);
    }
    if (x == y) return x;

    int i;
    for (i=17;i>=0;i--){
        if (P[x][i] != P[y][i]){
            x = P[x][i];
            y = P[y][i];
        }
    }

    return P[x][0];
}

long long X[100040],Y[100040];
deque<int> S; int sz;

int ccw(long long a, long long b, long long c, long long d, long long e, long long f)
{
    long long p = a * (d - f) + c * (f - b) + e * (b - d);
    if (p > 0) return 1;
    if (p < 0) return -1;
    return 0;
}

int main()
{
    int i,j,x,y,z,d;

    scanf ("%d",&N);
    for (i=1;i<=N;i++){
        scanf ("%lld %lld",&X[i],&Y[i]);
    }

    S.push_back(N); sz = 1;
    for (int i=N-1;i>=1;i--){
        while (sz >= 2 && ccw(X[i],Y[i],X[S[sz-1]],Y[S[sz-1]],X[S[sz-2]],Y[S[sz-2]]) > 0) S.pop_back(), sz--;
        G[S[sz-1]].push_back(i);
        S.push_back(i); sz++;
    }

    for (i=1;i<=N;i++){
        for (j=0;j<18;j++) P[i][j] = 0;
    }

    Q.push(N); chk[N] = 1;
    while (!Q.empty()){
        x = Q.front(); Q.pop();
        for (i=0;i<G[x].size();i++){
            y = G[x][i];
            if (chk[y] == 0){
                Q.push(y); chk[y] = 1;
                Depth[y] = Depth[x] + 1;

                P[y][0] = x;
                for (j=1;j<18;j++) if (P[y][j-1]){
                    P[y][j] = P[P[y][j-1]][j-1];
                }
            }
        }
    }

    scanf ("%d",&M);
    while (M--){
        scanf ("%d %d",&x,&y);
        z = commonancestor(x,y);
        printf ("%d ",z);
    }

    return 0;
}