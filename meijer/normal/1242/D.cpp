#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
#define REP(a,b,c) for(int a=int(b); a<int(c); a++)
#define RE(a,c) REP(a,0,c)
#define REV(a,b,c) for(int a=int(c-1); a>=int(b); a--)
#define INF 1e9
#define pb push_back
#define fi first
#define se second

const int MX=1e5, MOD=1e9+7;;
ll t, n, k;

ll f(ll i, ll b);
ll x(ll i) {
	if(i == 0) {
		return (k*(k+1))/2;
	} else {
		return f(i/k, i%k);
	}
}
ll g(ll i, ll b) {
	ll H = x(i);
	ll beg = (k*k+1)*i + b*k + 1;
	ll end = (k*k+1)*i + b*k + k;
	if(H < beg) return k;
	if(H > end) return 0;
	return end-H+1;
}
ll f(ll i, ll b) {
	return (k*i+b)*(k*k+1) - b + (k*(k+1))/2 + g(i, b);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>t;
    while(t--) {
    	cin>>n>>k;
    	ll i = (n-1)/(k*k+1);
    	ll u = x(i);
    	if(u == n) {
    		cout<<(k+1)*(i+1)<<endl;
    	} else if(u < n) {
    		cout<<(n-i-1) + (n-i-2)/k<<endl;
    	} else {
    		cout<<(n-i) + (n-i-1)/k<<endl;
    	}
    }
}