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

const int MX = 105;
int n, m, a, b, c;
map<string, int> small;
multiset<string> big[MX];
vector<string> suffix;
string ans;

void removeCharString(string& s, char l) {
	s.erase(find(s.begin(), s.end(), l));
}
char getAddedCharString(string& s, string& t) {
	RE(i,t.size()) if(s[i] != t[i]) return s[i];
	return s.back();
}

void program() {
	cin>>n; m = (n+1)/2;
	ans.resize(n);
	if(n <= 3) {
		RE1(i,n) {
			cout<<"? "<<i<<" "<<i<<endl;
			cout.flush();
			cin>>ans[i-1];
		}
	} else {
		a = (m*(m-1))/2;
		b = (m*(m+1))/2;
		c = (n*(n+1))/2;

		cout<<"? 1 "<<m-1<<endl; cout.flush();
		RE(i,a) {
			string s; cin>>s; sort(s.begin(), s.end());
			small[s]++;
		}

		cout<<"? 1 "<<m<<endl; cout.flush();
		RE(i,b) {
			string s; cin>>s; sort(s.begin(), s.end());
			small[s]--;
		}

		cout<<"? 1 "<<n<<endl; cout.flush();
		RE(i,c) {
			string s; cin>>s; sort(s.begin(), s.end());
			big[s.size()].insert(s);
		}

		for(auto p : small) if(p.se == -1) suffix.push_back(p.fi);
		sort(suffix.begin(), suffix.end(), [](string& a, string& b) {return a.size() < b.size();});

		RE(i,suffix.size()) {
			int c=-1;
			RE(j,i) if(suffix[i-1][j] != suffix[i][j]) {
				c = j; break;
			}
			if(c == -1) c = i;
			ans[m-i-1] = suffix[i][c];
		}

		string tot = *big[n].begin();
		RE(i,n-m) {
			int sz	= n-i-1;
			int emp	= i+1;
			string s = tot;
			RE(j,emp) removeCharString(s, ans[j]);
			RE(j,emp) {
				big[sz].erase(big[sz].find(s));
				if(j+1 == emp) break;
				removeCharString(s, ans[n-j-1]);
				s += ans[emp-j-1];
				sort(s.begin(), s.end());
			}
			string t = *big[sz].begin();
			removeCharString(t, ans[0]);
			ans[n-i-1] = getAddedCharString(s, t);
		}
	}
	cout<<"! "<<ans<<endl;
}