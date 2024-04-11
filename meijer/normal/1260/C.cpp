#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<iii> viii;
typedef vector<ll> vll;
#define REP(a,b,c) for(int a=int(b); a<int(c); a++)
#define RE(a,c) REP(a,0,c)
#define RE1(a,c) REP(a,1,c+1)
#define REI(a,b,c) REP(a,b,c+1)
#define REV(a,b,c) for(int a=int(c-1); a>=int(b); a--)
#define INF 1e9
#define pb push_back
#define fi first
#define se second

const int MX=4e5, MOD=1e9+7;
ll T, r, b, k;

ll gcd(ll x, ll y) {return y==0 ? x : gcd(y,x%y);}
ll lcm(ll x, ll y) {return x * (y/gcd(x,y));}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>T;
    while(T--) {
    	cin>>r>>b>>k;
    	if(b < r) swap(b,r);
    	bool rebel = 0;
    	ll longest = b/r;
    	if(b%r == 0) longest--;
    	else {
    		ll LCM = lcm(r,b);
    		ll regions = LCM/b;
    		ll values  = LCM/r - 1;
    		longest = values/regions;
    		if(values%regions) longest++;
    	}
    	if(longest >= k) rebel = 1;
    	cout<<(rebel?"REBEL":"OBEY")<<endl;
    }
}