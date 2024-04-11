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

const int MX = 1e5+1e4, MX2=1e6+1e5;
int n, l[MX], lowest[MX];
vi s[MX];
bitset<MX> a;
int cntBig[MX2];

void program() {
	cin>>n;
	a.reset();
	RE(i,n) {
		cin>>l[i];
		s[i].resize(l[i]);
		int mx=0;
		lowest[i] = INF;
		RE(j,l[i]) {
			cin>>s[i][j];
			if(s[i][j] > lowest[i]) a[i] = 1;
			lowest[i] = min(lowest[i], s[i][j]);
			mx = max(mx, s[i][j]);
		}
		if(!a[i]) cntBig[mx]++;
	}
	REV(i,0,1e6+1) {
		cntBig[i] += cntBig[i+1];
	}
	ll ans=0;
	RE(i,n) if(!a[i]) {
		ans += cntBig[lowest[i]+1];
	}
	ll cnt = a.count();
	ans += cnt*cnt + cnt*(n-cnt) + (n-cnt)*cnt;
	cout<<ans<<endl;
}