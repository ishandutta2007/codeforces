#include <bits/stdc++.h>
#define va first
#define vb second
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;
typedef pair<pii,int> ppi;
const int MN = 1e3+5;
const ll INF = 1e18;
int C[MN][MN];
ll D[MN][MN];
int main()
{
    ios_base::sync_with_stdio(0),cin.tie(0);
    int N,M,T;
    cin >> N >> M >> T;
    for(int i=1; i<=N; i++){
        for(int j=1; j<=M; j++){
            char c;
            cin >> c;
            C[i][j] = c-'0';
        }
    }
    for(int i=1; i<=N; i++){
        for(int j=1; j<=M; j++){
            if(j<M&&C[i][j+1]==C[i][j]) continue;
            if(j>1&&C[i][j-1]==C[i][j]) continue;
            if(i<N&&C[i+1][j]==C[i][j]) continue;
            if(i>1&&C[i-1][j]==C[i][j]) continue;
            D[i][j] = INF;
        }
    }
    queue<pii> Q;
    for(int i=1; i<=N; i++){
        for(int j=1; j<=M; j++){   
            if(D[i][j]==0) Q.emplace(i,j);
        }
    }

    while(Q.size()){
        pii p = Q.front();
        Q.pop();
        ll d = D[p.va][p.vb];
        if(d+1<D[p.va][p.vb+1]){
            D[p.va][p.vb+1] = d+1;
            Q.emplace(p.va,p.vb+1);
        }
        if(d+1<D[p.va][p.vb-1]){
            D[p.va][p.vb-1] = d+1;
            Q.emplace(p.va,p.vb-1);
        }
        if(d+1<D[p.va+1][p.vb]){
            D[p.va+1][p.vb] = d+1;
            Q.emplace(p.va+1,p.vb);
        }
        if(d+1<D[p.va-1][p.vb]){
            D[p.va-1][p.vb] = d+1;
            Q.emplace(p.va-1,p.vb);
        }
    }

    int x,y;
    ll t;
    for(int i=0; i<T; i++){
        cin >> x >> y >> t;
        if(t<=D[x][y]) cout << C[x][y] << '\n';
        else{
            if((t-D[x][y])%2==0) cout << C[x][y] << '\n';
            else cout << 1-C[x][y] << '\n';
        }
    }
}