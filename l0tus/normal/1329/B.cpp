#include <bits/stdc++.h>
#define va first
#define vb second
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;
typedef pair<pii,int> ppi;
const int MN = 40;
int T,D,M,K;
ll A[MN],C[MN],F[MN],ans;

ll add(ll X, ll Y)
{
    return (X%M+Y%M)%M;
}

int main()
{
    ios_base::sync_with_stdio(0),cin.tie(0);
    A[0] = 1;
    for(int i=1; i<=30; i++){
        A[i] = A[i-1]*2;
    }
    cin >> T;
    while(T--){
        cin >> D >> M;
        ans = 0;
        fill(C,C+31,0);
        for(int i=0; i<=30; i++){
            if(A[i]>D) break;
            if(A[i+1]>D) C[i] = D-A[i]+1;
            else C[i] = A[i];
            ans = add(ans,C[i]);
            K = i;
        }
        while(K--){
            ll cnt = 0, tmp = C[K+1];
            for(int i=K; i>=0; i--){
                cnt += tmp;
                tmp = C[i];
                C[i] = A[i]*cnt%M;
                ans = add(ans,C[i]);
            }
        }
        cout << ans << '\n';
    }

}