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

const int MX=4e5;
ll t, a, b;

void program() {
	cin>>t;
	while(t--) {
		cin>>a>>b;
		ll ans=0;
		if(a > b) swap(a,b);
		ll lb=0, ub=b;
		while(lb != ub) {
			ll mid=(lb+ub+1)/2;
			ll added=(mid*(mid+1))/2;
			if(a + added <= b) lb=mid;
			else ub=mid-1;
		}
		ans = lb;
		a += (ans*(ans+1))/2;
		if(a != b) {
			ans++;
			while(1) {
				a += ans;
				if((a+b)%2) ans++;
				else break;
			}
		}
		cout<<ans<<endl;
	}
}