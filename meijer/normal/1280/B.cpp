#include <bits/stdc++.h>
using namespace std;

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

const int MX=100, MOD=1e9+7;

int t, r, c;
char gr[MX][MX];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>t;
	while(t--) {
		cin>>r>>c;
		RE(i,r) RE(j,c) cin>>gr[i][j];
		bool allP=1;
		RE(i,r) RE(j,c) {
			if(gr[i][j] != 'P')
				allP=0;
		}
		if(allP) {
			cout<<"MORTAL"<<endl;
			continue;
		}
		int ans=4;

		bool allA=1;
		RE(i,r) RE(j,c) {
			if(gr[i][j] != 'A')
				allA=0;
		}
		if(allA) ans = 0;
		allA=1;
		RE(i,r)
			if(gr[i][0] != 'A')
				allA=0;
		if(allA) ans = min(ans, 1);
		allA=1;
		RE(i,r)
			if(gr[i][c-1] != 'A')
				allA=0;
		if(allA) ans = min(ans, 1);
		allA=1;
		RE(i,c)
			if(gr[0][i] != 'A')
				allA=0;
		if(allA) ans = min(ans, 1);
		allA=1;
		RE(i,c)
			if(gr[r-1][i] != 'A')
				allA=0;
		if(allA) ans = min(ans, 1);

		RE(i,r) {
			allA=1;
			RE(j,c) 
				if(gr[i][j] != 'A')
					allA=0;
			if(allA) ans = min(ans, 2);
		}
		RE(j,c) {
			allA=1;
			RE(i,r) 
				if(gr[i][j] != 'A')
					allA=0;
			if(allA) ans = min(ans, 2);
		}
		allA=1;
		RE(i,c)
			if(gr[0][i] != 'A' && gr[r-1][i] != 'A')
				allA=0;
		if(allA) ans = min(ans, 2);
		allA=1;
		RE(i,r)
			if(gr[i][0] != 'A' && gr[i][c-1] != 'A')
				allA=0;
		if(allA) ans = min(ans, 2);

		if(gr[0][0]=='A' || gr[0][c-1]=='A' || gr[r-1][0]=='A' || gr[r-1][c-1]=='A')
			ans = min(ans, 2);

		RE(i,r) if(gr[i][0]=='A' || gr[i][c-1]=='A') ans = min(ans, 3);
		RE(j,c) if(gr[0][j]=='A' || gr[r-1][j]=='A') ans = min(ans, 3);
		cout<<ans<<endl;
	}
}