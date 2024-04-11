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

const int MX = 100;
int n, m, a, b;
map<string, int> small, big;
vector<string> suffix;
string ans;

void program() {
	cin>>n; m = n/2;
	ans.resize(n);
	if(n <= 3) {
		RE1(i,n) {
			cout<<"? "<<i<<" "<<i<<endl;
			cout.flush();
			cin>>ans[i-1];
		}
	} else {
		a = (n*(n-1))/2;
		b = (n*(n+1))/2;

		cout<<"? 1 "<<n-1<<endl;
		cout.flush();
		RE(i,a) {
			string s;
			cin>>s;
			sort(s.begin(), s.end());
			small[s]++;
		}

		cout<<"? 1 "<<n<<endl;
		cout.flush();
		RE(i,b) {
			string s;
			cin>>s;
			sort(s.begin(), s.end());
			big[s]++;
		}
		for(auto p : big) {
			if(small[p.fi] != p.se) {
				suffix.push_back(p.fi);
			}
		}
		sort(suffix.begin(), suffix.end(), [](string& a, string& b) {
			return a.size() < b.size();
		});
		RE(i,suffix.size()) {
			int c=-1;
			RE(j,i) if(suffix[i-1][j] != suffix[i][j]) {
				c = j; break;
			}
			if(c == -1) c = i;
			ans[n-i-1] = suffix[i][c];
		}
	}
	cout<<"! "<<ans<<endl;
}