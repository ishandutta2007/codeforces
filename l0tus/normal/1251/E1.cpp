#include <bits/stdc++.h>
#define va first
#define vb second
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
const int MN = 2e5+5;
const ll INF = 1e18;
ll D[5005][5005];
pll A[5005];

bool cmp(pll A, pll B)
{
    if(A.va==B.va) return A.vb>B.vb;
    return A.va<B.va;
}

int main()
{
    ios_base::sync_with_stdio(0),cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int N;
        cin >> N;
        for(int i=1; i<=N; i++) cin >> A[i].va >> A[i].vb;
        sort(A+1,A+N+1,cmp);
        for(int i=0; i<=N; i++){
            for(int j=0; j<=N; j++){
                D[i][j] = INF;
            }
        }
        D[N][0] = 0;
        for(int i=N; i>=1; i--){
            for(int j=N-i; j>=0; j--){
                //cout << D[i][j] << '\n';
                if(i-1+j>=A[i].va) D[i-1][j] = min(D[i-1][j],D[i][j]);
                D[i-1][j+1] = min(D[i-1][j+1],D[i][j]+A[i].vb);
            }
        }
        ll ans = 1e18;
        for(int i=N; i>=0; i--) ans = min(ans,D[0][i]);
        cout << ans << '\n';
    }
}