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
int t, n, x;
string s;

void program() {
	cin>>t;
	while(t--) {
		cin>>n>>x>>s;
		int dif=count(s.begin(), s.end(), '0')-count(s.begin(), s.end(), '1');
		int ans=0;
		int cur=0;
		RE(i,n+1) {
			if(dif == 0) {
				if(cur == x) ans = -1;
			} else {
				int change = x - cur;
				if((change % dif) == 0 && change/dif >= 0) ans++;
				if(i+1 == n) break;
			}
			if(i != n) cur += (s[i]=='0' ? 1 : -1);
		}
		cout<<ans<<endl;
	}
}