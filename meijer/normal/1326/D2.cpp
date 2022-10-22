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

const int MX = 4e6;
int t, n, m;
string s;
char S[MX];
int p[MX];

void program() {
	cin>>t;
	while(t--) {
		cin>>s;
		m=s.size();
		n=0;
		S[n++]='$';
		for(char c:s) {
			S[n++]='-';
			S[n++]=c;
		}
		S[n++]='-';
		S[n++]='#';

		int c=0, r=0;
		RE(i,n) p[i]=0;
		REP(i,1,n-1) {
			int mir=2*c-i;
			if(i<r) {
				p[i] = min(r-i, p[mir]);
			}
			while(S[i+1+p[i]] == S[i-(1+p[i])])
				p[i]++;
			if(i+p[i] > r) {
				c = i;
				r = i+p[i];
			}
		}

		int same=0;
		RE(i,m/2) {
			if(s[i] == s[m-i-1]) same++;
			else break;
		}

		int mx=0;
		string ans;
		RE(i,n) {
			int bg=(i-p[i])/2;
			int ed=bg+p[i];
			int minLen = min(bg, m-ed);
			if(minLen > same) continue;
			mx = max(mx,minLen*2+p[i]);
		}
		RE(i,n) {
			int bg=(i-p[i])/2;
			int ed=bg+p[i];
			int minLen = min(bg, m-ed);
			if(minLen > same) continue;
			if(minLen*2+p[i] == mx) {
				ans += s.substr(0,minLen);
				ans += s.substr(bg,p[i]);
				ans += s.substr(m-minLen, minLen);
				break;
			}
		}
		cout<<ans<<endl;
	}
}