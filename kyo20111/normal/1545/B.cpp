#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll mod = 998244353;
int n;
ll fac[200200], rev[200200];
string s;

ll pw(ll n, ll k){
    if(!k) return 1;
    ll re = pw(n, k/2) % mod;
    return re * re % mod * (k % 2 ? n : 1) % mod;
}

void solve(){
    cin >> n >> s;

    int cnt = 0, sum = 0;
    for(int i=0;i<n-1;i++) if(s[i] == s[i+1] && s[i] == '1') cnt++, i++;
    for(int i=0;i<n;i++) if(s[i] == '0') sum++;

    cout << fac[cnt+sum]*rev[cnt]%mod*rev[sum]%mod;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);

    fac[0] = rev[0] = 1;
    for(int i=1;i<=200000;i++) fac[i] = fac[i-1] * i % mod;
    for(int i=1;i<=200000;i++) rev[i] = pw(fac[i], mod-2);

    int tc = 1; cin >> tc;
    while(tc--) solve(), cout << "\n";
}