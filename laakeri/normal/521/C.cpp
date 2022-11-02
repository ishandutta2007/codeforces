#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef long long ll;

ll mod=1e9+7;

ll pot(ll a, ll p){
    if (p==0) return 1;
    if (p%2==1) return (a*pot(a, p-1))%mod;
    a=pot(a, p/2);
    return (a*a)%mod;
}

ll inv (ll a){
    return pot(a, mod-2);
}

ll fa[100011];

ll ncr(ll n, ll k){
    ll re=fa[n];
    return (re*inv((fa[k]*fa[n-k])%mod))%mod;
}

ll lol[100001];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    if (k==0){
        ll v=0;
        ll asd=1;
        for (ll i=n-1;i>=0;i--){
            v+=(ll)(s[i]-'0')*asd;
            v%=mod;
            asd*=10ll;
            asd%=mod;
        }
        cout<<v<<endl;
    }
    else{
        fa[0]=1;
        for (ll i=1;i<=n;i++){
            fa[i]=fa[i-1]*i;
            fa[i]%=mod;
        }
        ll kk=ncr(n-1, k);
        ll asd=1;
        ll v=0;
        for (ll i=n-1;i>=0;i--){
            //cout<<kk<<endl;
            v+=(ll)(s[i]-'0')*kk;
            v%=mod;
            if (i>k-1){
                kk-=(ncr(i-1, k)*asd)%mod;
                kk+=mod;
                asd*=10ll;
                asd%=mod;
                kk+=(ncr(i-1, k)*asd)%mod;
                kk%=mod;
                //cout<<ncr(i-1, k)<<" "<<i-1<<" "<<k<<endl;
            }
        }
        cout<<v<<endl;
    }
}