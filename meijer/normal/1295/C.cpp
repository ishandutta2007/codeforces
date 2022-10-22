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

const int MX = 2e5;
int T, n;
string s, t;
int nxt[MX][26];

void program() {
	cin>>T;
	while(T--) {
		cin>>s>>t; n=s.size();
		RE(i,n) RE(j,26) nxt[i][j] = -1;
		REV(i,0,n-1) {
			RE(j,26) nxt[i][j] = nxt[i+1][j];
			nxt[i][s[i+1]-'a'] = i+1;
		}
		int ans=0, j=0;
		while(true) {
			ans++;
			int pJ = j;
			int i=0;
			if(s[i] != t[j]) i = nxt[i][t[j]-'a'];
			while(true) {
				if(i == -1) break;
				j++;
				if(j == t.size()) break;
				i = nxt[i][t[j]-'a'];
			}
			if(pJ == j) break;
			if(j == t.size())
				break;
		}
		if(j != t.size()) ans = -1;
		cout<<ans<<endl;
	}
}