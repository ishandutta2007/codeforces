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
int n, a[MX], b[MX];
vi adj[MX];

void program() {
	cin>>n;
	RE(i,n) cin>>a[i];
	RE(i,n) {
		int l=i-a[i], r=i+a[i];
		if(l >= 0) adj[l].pb(i);
		if(r <  n) adj[r].pb(i); 
	}

	//odd
	{
		vi dist(n,-1); queue<int> q;
		RE(i,n) if(a[i]%2 == 0) dist[i] = 0, q.push(i);
		while(!q.empty()) {
			int u=q.front(); q.pop();
			for(int v:adj[u])
				if(dist[v] == -1)
					dist[v] = dist[u]+1, q.push(v);
		}
		RE(i,n) if(a[i]%2 == 1) b[i] = dist[i];
	}
	//even
	{
		vi dist(n,-1); queue<int> q;
		RE(i,n) if(a[i]%2 == 1) dist[i] = 0, q.push(i);
		while(!q.empty()) {
			int u=q.front(); q.pop();
			for(int v:adj[u])
				if(dist[v] == -1)
					dist[v] = dist[u]+1, q.push(v);
		}
		RE(i,n) if(a[i]%2 == 0) b[i] = dist[i];
	}

	RE(i,n) cout<<(i==0?"":" ")<<b[i]; cout<<endl;
}