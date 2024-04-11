#include <bits/stdc++.h>
#define va firsst
#define vb second
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<int,pii> pip;
const int INF = 1e9;
const int MN = 1e5+5;
int N,M,A[MN],B[MN],I[MN],num[MN],par[MN],dis[1000][1000],ans;
vector<int> T[MN];

int fnd(int x)
{
    return par[x]==x ? par[x] : par[x] = fnd(par[x]);
}

int main()
{
    ios_base::sync_with_stdio(0),cin.tie(0);
    cin >> N >> M;
    int u,v;
    for(int i=1; i<=M; i++){
        cin >> A[i] >> B[i];
        T[A[i]].push_back(B[i]);
        T[B[i]].push_back(A[i]);
        I[A[i]]++;
        I[B[i]]++;
    }
    int x = 1, cnt = 1;
    for(int i=2; i<=N; i++) if(I[x]>I[i]) x=i;
    for(int i=1; i<=N; i++) num[i] = 1;
    for(int e : T[x]) num[e] = ++cnt;
    for(int i=1; i<=M; i++){
        u = num[A[i]];
        v = num[B[i]];
        dis[u][v]++;
        dis[v][u]++;
    }
    ans = cnt-1;
    for(int i=1; i<=cnt; i++) par[i] = i;
    for(int i=1; i<=cnt; i++)
        for(int j=i+1; j<=cnt; j++){
            if(i==1){
                if(dis[i][j]==N-cnt+1) continue;
            }
            else if(dis[i][j]) continue;
            u = fnd(i), v = fnd(j);
            if(u==v) continue;
            par[u] = v;
            ans--;
        }
    cout << ans;
}