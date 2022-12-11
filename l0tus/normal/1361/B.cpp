#include <bits/stdc++.h>
#define va first
#define vb second
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;
typedef pair<pii,int> ppi;
const int MN = 1e6+5;
const int MOD = 1e9+7;
int A[MN],S[MN],N,P;
ll ans;

ll pw(int x, int k)
{
    ll cur = x, res = 1;
    while(k){
        if(k%2) res = res*cur%MOD;
        k/=2;
        cur = cur*cur%MOD;
    }
    return res; 
}

void solve(int x)
{
    if(x==N) return;
    S[A[x]] = 1;
    int res = A[x];
    ans = (ans+pw(P,A[x]))%MOD;
    for(int i=x+1; i<N; i++){
        S[A[i]]--;
        ans = (ans-pw(P,A[i])+MOD)%MOD;
        int j = A[i];
        while(S[j]==-P){
            S[j]=0, S[j+1]--;
            if(j+1==res&&S[res]==0) res--;
            j++;
        }
        if(S[res]==0){
            solve(i+1);
            return;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0),cin.tie(0);
    int T;
    cin >> T;
    while(T--){
        cin >> N >> P;
        for(int i=0; i<N; i++) cin >> A[i];
        sort(A,A+N,greater<int>());
        if(P==1){
            cout << N%2 << '\n';
            continue;
        }
        ans = 0;
        solve(0);
        cout << ans << '\n';
        for(int i=0; i<N; i++){
            for(int j=0; j<=30; j++)
                if(A[i]+j<MN) S[A[i]+j] = 0;
        }
    }

}