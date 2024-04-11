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

const int MX = 1e6;
int n, m, M;
int x[MX], y[MX];
set<int> used;
queue<ii> q;

void program() {
	cin>>n>>m;
	RE(i,n) cin>>x[i];
	sort(x, x+n);
	RE(i,n) used.insert(x[i]);
	RE(i,n) {
		if(!used.count(x[i]-1)) q.push({1,x[i]-1});
		if(!used.count(x[i]+1)) q.push({1,x[i]+1});
	}
	ll res=0;
	while(M != m) {
		ii p = q.front(); q.pop();
		if(used.count(p.se)) continue;
		res += p.fi;
		used.insert(p.se);
		y[M++] = p.se;

		if(!used.count(p.se-1)) q.push({p.fi+1, p.se-1});
		if(!used.count(p.se+1)) q.push({p.fi+1, p.se+1});
	}
	cout<<res<<endl;
	RE(i,m) cout<<(i==0?"":" ")<<y[i]; cout<<endl;
}