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
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

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
	cout.tie(NULL);
	program();
}


//===================//
//   begin program   //
//===================//

const int MX = 5001;
int t, n;
string s;
bool isPal[MX][MX];

void program() {
	cin>>t;
	while(t--) {
		cin>>s; n=s.size();
		RE(i,n) RE(j,n) isPal[i][j] = 0;
		REV(i,0,n) REP(j,i,n) {
			if(i == j) isPal[i][j] = 1;
			else if(i+1 == j) isPal[i][j] = (s[i]==s[j]);
			else isPal[i][j] = (s[i]==s[j] && isPal[i+1][j-1]);
		}
		string ans=s.substr(0,1);
		RE(i,n/2) {
			REP(j,i,n-i) {
				if(j+i+1 < ans.size()) continue;
				if(isPal[i][j]) {
					string t;
					t += s.substr(0,j+1);
					t += s.substr(n-i,i);
					ans=t;
				}
				if(isPal[n-j-1][n-i-1]) {
					string t;
					t += s.substr(0,i);
					t += s.substr(n-j-1,j+1);
					ans=t;
				}
			}
			if(i*2 > ans.size()) {
				string t;
				t += s.substr(0,i);
				t += s.substr(n-i,i);
				ans=t;
			}
			if(s[i] != s[n-i-1]) break;
		}
		cout<<ans<<endl;
	}
}