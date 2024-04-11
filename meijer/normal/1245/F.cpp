#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
#define REP(a,b,c) for(int a=int(b); a<int(c); a++)
#define RE(a,c) REP(a,0,c)
#define REV(a,b,c) for(int a=int(c-1); a>=int(b); a--)
#define INF 1e18
#define pb push_back
#define fi first
#define se second

const int MX=1e5, MOD=1e9+7;;

ll t;
ll ans=0;

ll LSB(ll i) {return i&-i;}
ll h(ll x, ll n) {
	ll L 	= n-LSB(n);
	if(L & x) return 0;
	ll bm	= LSB(n)-1;
	bm		= (bm&(~x));
	ll cnt 	= 0;
	RE(i,60) if(bm & (1LL<<i)) cnt++;
	return 1<<cnt;
}
ll g(ll x, ll n) {
	if(n == 0) return 0;
	return h(x,n) + g(x,n-LSB(n));
}
ll f(ll i, ll j) {
	if(i == j)
		return 0;
	if(i == 0)
		return 2*j - 1 + f(1, j);
	if(i&1)
		return f(i+1,j) + 2*(g(i,j)-g(i,i));
	if(j&1)
		return f(i,j-1) + 2*(g(j-1,j)-g(j-1,i));
	return 3*f(i/2,j/2);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>t;
    while(t--) {
    	ll l, r;
    	cin>>l>>r;
    	cout<<f(l,r+1)<<endl;
    }
}