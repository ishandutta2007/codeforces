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

const int MX = 200;
int t, n;
string s;
int sm[MX];

void program() {
	cin>>t;
	while(t--) {
		cin>>s; n=s.size();
		RE(i,n) sm[i] = (i==0 ? 0 : sm[i-1]) + (s[i]=='0');
		int bg=-1, e=0;
		RE(i,n) if(s[i] == '1') e=i, bg = (bg==-1?i:bg);
		if(bg == -1) {
			cout<<0<<endl;
		} else {
			cout<<sm[e]-sm[bg]<<endl;
		}
	}
}