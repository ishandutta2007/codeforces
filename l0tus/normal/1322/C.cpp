#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MN = 5e5+5;
int par[MN];
ll C[MN],D[MN];
vector<int> V[MN];

ll GCD(ll x, ll y)
{
    if(x<y) swap(x,y);
    if(y==0) return x;
    return GCD(y,x%y);
}

bool cmp(int a, int b)
{
    return par[a]<par[b];
}

int main()
{
    ios_base::sync_with_stdio(0),cin.tie(0);
    int T,N,M;
    cin >> T;
    while(T--){
        cin >> N >> M;
        int cnt = 0, tmp;
        for(int i=1; i<=N; i++){
            cin >> C[i];
            par[i] = 0;
        }
        for(int i=0; i<M; i++){
            int a,b;
            cin >> a >> b;
            V[a].push_back(b);
        }
        for(int i=1; i<=N; i++){
            sort(V[i].begin(),V[i].end(),cmp);
            tmp = -1;
            for(int x:V[i]){
                if(par[x]!=tmp){
                    ++cnt;
                    tmp = par[x];
                }
                par[x] = cnt;
            }
        }
        for(int i=1; i<=N; i++) D[par[i]] += C[i];
        ll ans = 0;
        for(int i=1; i<=cnt; i++){
            ans = GCD(ans,D[i]);
            D[i] = 0;
        }
        for(int i=1; i<=N; i++) V[i].clear();
        cout << ans << '\n';
    }
}