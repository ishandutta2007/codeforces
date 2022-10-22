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
string s;
int n;
int cntR[MX];
vector<vector<int>> ans;

void program() {
	cin>>s; n=s.size();
	while(true) {
		n=s.size();
		cntR[n] = 0;
		REV(i,0,n) cntR[i] = cntR[i+1]+(s[i]==')'?1:0);
		int mx=0, cnt=0;
		RE(i,n) {
			if(cntR[i] < cnt) break;
			mx = max(mx, cnt);
			if(s[i] == '(') cnt++;
		}
		if(mx == 0) break;
		vector<int> add;
		int l=mx;
		RE(i,n) {
			if(s[i] == '(') l--, add.pb(i+1);
			if(l == 0) break;
		}
		l=mx;
		REV(i,0,n) {
			if(s[i] == ')') l--, add.pb(i+1);
			if(l == 0) break;
		}
		sort(add.begin(), add.end());
		REV(i,0,add.size()) {
			s.erase(s.begin()+add[i]-1);
		}
		ans.pb(add);
	}
	cout<<ans.size()<<endl;
	RE(i,ans.size()) {
		cout<<ans[i].size()<<endl;
		RE(j,ans[i].size()) cout<<(j==0?"":" ")<<ans[i][j]; cout<<endl;
	}
}