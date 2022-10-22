#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> ii;
typedef tuple<ll, ll, ll> iii;
typedef vector<ll> vi;
typedef vector<ii> vii;
typedef vector<iii> viii;
typedef vector<ll> vll;
#define REP(a,b,c) for(ll a=ll(b); a<ll(c); a++)
#define RE(a,c) REP(a,0,c)
#define REV(a,b,c) for(ll a=ll(c-1); a>=ll(b); a--)
#define INF 1e9
#define pb push_back
#define fi first
#define se second

const ll MX=4e5, MOD=1e9+7;
ll n, m, Y, a[MX];
ll x[MX];
vi y[MX];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>m;
    RE(i,n) cin>>a[i];
    sort(a,a+n);
    Y = (n/m) + 1;
    RE(i,m) {
    	y[i].resize(Y);
    	RE(j,Y) y[i][j] = 0;
    }
    RE(i,n) {
    	y[i%m][i/m] += a[i];
    }
    RE(i,m) {
    	REP(j,1,Y) y[i][j] += y[i][j-1];
    }
    RE(i,n) {
    	x[i] = y[i%m][i/m];
    	if(i != 0) x[i] += x[i-1];
    }
    RE(i,n) cout<<(i==0?"":" ")<<x[i]; cout<<endl;
}