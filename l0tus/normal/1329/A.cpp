#include <bits/stdc++.h>
#define va first
#define vb second
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;
typedef pair<pii,int> ppi;
const int MN = 2e5+5;
ll A[MN],S[MN],ans[MN];
int main()
{
    ios_base::sync_with_stdio(0),cin.tie(0);
    int N,M;
    cin >> N >> M;
    for(int i=1; i<=M; i++){
        cin >> A[i];
        S[i] = S[i-1]+A[i];
    }
    if(M==1){
        if(A[1]==N) cout << 1;
        else cout << -1;
        return 0;
    }
    ll pos = N-A[M];
    ans[M] = pos+1;
    for(int i=M-1; i>=1; i--){
        if(pos<1){
            cout << -1;
            return 0;
        }
        pos = min(pos,N-A[i]+1);
        if(S[i-1]+A[i]<pos){
            cout << -1;
            return 0;
        }
        pos = min(pos,S[i-1]+1);
        ans[i] = pos;
        pos--;
    }
    for(int i=1; i<=M; i++) cout << ans[i] << ' ';
}