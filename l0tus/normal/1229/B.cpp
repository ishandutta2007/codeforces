#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
#define va first
#define vb second
const int MN = 1e5+5;
const int MOD = 1e9+7;
ll N,X[MN],ans;
vector<pll> V[MN];
vector<ll> T[MN];

ll gcd(ll a, ll b)
{
    if(a<b) swap(a,b);
    if(b==0) return a;
    return gcd(b,a%b);
}

void sum(ll x, ll p)
{
    ll cnt = X[x], val;
    V[x].emplace_back(X[x],1);
    for(pll par : V[p]){
        val = gcd(X[x],par.va);
        if(cnt==val) V[x].pop_back();
        V[x].emplace_back(val,par.vb+1);
        cnt = val;
    }
    ll pos = 0;
    for(pll par : V[x]){
        ans += par.va*(par.vb-pos);
        ans %= MOD;
        pos = par.vb;
    }
    for(ll next : T[x]){
        if(next==p) continue;
        sum(next,x);
    }
}

int main()
{
    ios_base::sync_with_stdio(0),cin.tie(0);
    cin >> N;
    for(int i=1; i<=N; i++) cin >> X[i];
    ll a,b;
    for(int i=1; i<N; i++){
        cin >> a >> b;
        T[a].push_back(b);
        T[b].push_back(a);
    }
    sum(1,0);
    cout << ans;
}