#include <bits/stdc++.h>

using namespace std;

#define REP(a,b,c) for(int a=int(b); a<int(c); a++)
#define RE(a,b) REP(a,0,b)
#define INF 1e9
#define pb push_back
#define fi first
#define se second
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<ll> vll;

const int MX = 3e5, MOD=1e9+7;
ll n, b[MX];
map<ll, ll> m;

int main() {
    cin>>n;
    RE(i,n) cin>>b[i];
    RE(i,n) {
        m[b[i]-i] += b[i];
    }
    ll ans=b[0];
    for(pair<ll, ll> p : m) {
        ans = max(ans, p.se);
    }
    cout<<ans<<endl;
    return 0;
}