#include <bits/stdc++.h>
#define va first
#define vb second
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<pii,int> ppi;
typedef pair<int,pii> pip;

const int MN = 5e5+5;
const int MOD = 1e9+7;
const int INF = 1e9;

int N,M,A[MN],C[MN],ans[MN];
vector<int> G[MN],V;

bool solve(int s)
{
    for(int e:G[s]){
        V.push_back(C[e]);
    }
    sort(all(V));
    V.erase(unique(V.begin(),V.end()),V.end());
    int tmp = 0, res = 0;
    for(int x:V){
        if(x==tmp+1) res = x;
        else break;
        tmp++;
    }
    V.clear();
    return res+1==C[s];
}

int main()
{
    ios_base::sync_with_stdio(0),cin.tie(0);
    cin >> N >> M;
    int u,v;
    for(int i=0; i<M; i++){
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    vector<pii> S;
    for(int i=1; i<=N; i++){
        cin >> C[i];
        S.emplace_back(C[i],i);
    }
    for(int i=1; i<=N; i++){
        if(!solve(i)){
            cout << -1;
            return 0;
        }
    }
    sort(all(S));
    for(int i=1; i<=N; i++){
        ans[i] = S[i-1].vb;
    }
    for(int i=1; i<=N; i++){
        cout << ans[i] << ' ';
    }
}