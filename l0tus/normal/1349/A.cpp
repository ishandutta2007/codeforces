#include <bits/stdc++.h>
#define va first
#define vb second
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;
typedef pair<pii,int> ppi;
const int MN = 2e5+5;
ll A[MN];
bool ch[MN];
int main()
{
    ios_base::sync_with_stdio(0),cin.tie(0);
    ll N,ans=1;
    cin >> N;
    for(int i=1; i<=N; i++) cin >> A[i];
    for(int i=2; i<=200000; i++){
        if(ch[i]) continue;
        ll k = 1, cnt;
        while(1){
            k = k*i;
            cnt = 0;
            for(int j=1; j<=N; j++){
                if(A[j]%k!=0) cnt++;
                if(cnt>1) break;
            }
            if(cnt>1){
                ans *= k/i;
                break;
            }
        }
        for(int j=i; j<=200000; j+=i){
            ch[j] = 1;
        }
    }
    cout << ans;
}