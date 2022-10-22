#include <bits/stdc++.h>
using namespace std;

//macros
typedef long long ll;
typedef pair<ll, ll> ii;
typedef tuple<int, int, int> iii;
typedef vector<ll> vi;
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
string s;

void program() {
	cin>>t;
	while(t--) {
		cin>>n>>s;
		string t;
		int ans=0;
		REP(k,1,n) {
			string u = s;
			RE(i,n-k+1) u[i] = s[i+k-1];
			if((n-k)%2) RE(i,k-1) u[n-i-1] = s[k-i-2];
			else	RE(i,k-1) u[n-i-1] = s[i];
			if(k == 1 || u < t) {
				t = u;
				ans = k;
			}
		}
		string u = s;
		reverse(u.begin(), u.end());
		if(n==1 || u < t) {
			t = u;
			ans = n;
		}
		cout<<t<<endl;
		cout<<ans<<endl;
	}
}