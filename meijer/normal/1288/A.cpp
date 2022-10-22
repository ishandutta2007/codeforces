#include <bits/stdc++.h>
using namespace std;

//macros
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

//===================//
//  Added libraries  //
//===================//

//===================//
//end added libraries//
//===================//

void program();
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	program();
}



//===================//
//   begin program   //
//===================//

const int MX = 5e5;
ll T, n, d;

ll sqrt(ll a) {
	ll lb=0, ub=1e5;
	while(lb != ub) {
		ll mid=(lb+ub)/2;
		if(mid*mid >= a) ub=mid;
		else lb = mid+1;
	}
	return lb;
}

void program() {
	cin>>T;
	while(T--) {
		cin>>n>>d;
		ll s = sqrt(d);
		bool pos=0;
		for(ll x=s-3; x!=s+3; x++) {
			if(x < 0) continue;
			ll days = (d+x)/(x+1);
			days += x;
			if(days <= n) pos=1;
		}
		cout<<(pos?"YES":"NO")<<endl;
	}
}