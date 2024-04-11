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

const int MX = 1100;
int n;
set<int> adj[MX];
bitset<MX> used;

void program() {
	cin>>n;
	RE(i,n-1) {
		int x, y; cin>>x>>y;
		adj[x].insert(y);
		adj[y].insert(x);
	}
	int curHighest = -1;
	queue<int> q;
	RE1(i,n) if(adj[i].size() == 1) q.push(i);
	while(1) {
		if(q.size() == 1) {
			cout<<"! "<<q.front()<<endl;
			return;
		}
		int u = q.front(); q.pop();
		int v = q.front(); q.pop();
		cout<<"? "<<u<<" "<<v<<endl;
		cout.flush();
		int w; cin>>w;
		if(u == w || v == w) {
			cout<<"! "<<w<<endl;
			return;
		}
		adj[*adj[u].begin()].erase(u);
		if(adj[*adj[u].begin()].size() == 1) q.push(*adj[u].begin());
		adj[*adj[v].begin()].erase(v);
		if(adj[*adj[v].begin()].size() == 1) q.push(*adj[v].begin());
	}
}