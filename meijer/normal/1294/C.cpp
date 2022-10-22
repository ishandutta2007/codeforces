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
int t, n;

vi primeFact(ll a) {
	vi ans;
	for(ll i=2; i*i<=a; i++) {
		while(a%i == 0) {
			a /= i;
			ans.pb(i);
		}
	}
	if(a != 1) ans.pb(a);
	return ans;
}

void program() {
	cin>>t;
	while(t--) {
		cin>>n;
		vi pf = primeFact(n);
		int ans[]={1,1,1};
		RE(i,pf.size()) {
			if(ans[2] != 1) {
				ans[2] *= pf[i];
			} else if(ans[0] != pf[i] && ans[1] != pf[i]) {
					 if(ans[0] == 1) ans[0] = pf[i];
				else if(ans[1] == 1) ans[1] = pf[i];
				else if(ans[2] == 1) ans[2] = pf[i];
			} else {
				if(i+1 != pf.size())
					pf[i+1] *= pf[i];
			}
		}
		if(ans[2] == 1) {
			cout<<"NO"<<endl;
		} else {
			cout<<"YES"<<endl;
			cout<<ans[0]<<" "<<ans[1]<<" "<<ans[2]<<endl;
		}
	}
}