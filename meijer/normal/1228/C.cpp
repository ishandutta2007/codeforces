#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> ii;
typedef vector<ll> vi;
typedef vector<ii> vii;
#define REP(a,b,c) for(int a=int(b); a<int(c); a++)
#define RE(a,c) REP(a,0,c)
#define REV(a,b,c) for(int a=int(c-1); a>=int(b); a--)
#define INF 1e9

const ll MX=1e5, MOD=1e9 + 7;
ll x, n;
vi prime;

vi factors(ll i) {
    vi f;
    for(ll j=2; j*j <= i; j++) {
        if(i%j == 0)
            f.push_back(j);
        while(i%j == 0)
            i /= j;
    }
    if(i > 1) f.push_back(i);
    return f;
}
ll modPow(ll numb, ll pow) {
    if(pow == 1) return numb;
    ll halve = modPow(numb, pow/2);
    ll ans = (halve*halve)%MOD;
    if(pow % 2 == 1) {
        ans *= numb;
        ans %= MOD;
    }
    return ans;
}
ll g(ll numb, ll div) {
    ll cdiv = div;
    ll cans = 1;
    while(cdiv <= numb) {
        cans *= modPow(div, numb/cdiv);
        cans %= MOD;
        ll pdiv = cdiv;
        cdiv *= div;
        if((cdiv/div) != pdiv) return cans;
    }
    return cans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>x>>n;
    prime = factors(x);
    ll ans=1;
    for(ll a:prime) {
        ans *= g(n, a);
        ans %= MOD;
    }
    cout<<ans<<endl;
}