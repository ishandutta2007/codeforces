/* In the name of Allah */
#include <bits/stdc++.h>

using namespace std;

#define sz(x) (((int) x.size()))
typedef long long ll;

const int maxN = 200 + 10;
const int maxM = maxN*maxN;
const int INF = 1e9;

int head[maxN];
int to[maxM], cap[maxM], nex[maxM];
int mcnt;
int source,sink;

int pointer[maxN];

int h[maxN];
int que[maxN];
int mark[maxN];

void addEdge( int u , int v , int c ) { 
	to[mcnt] = v , cap[mcnt] = c , nex[mcnt] = head[u] , head[u] = mcnt++;
	to[mcnt] = u , cap[mcnt] = 0 , nex[mcnt] = head[v] , head[v] = mcnt++;
}

int dfs( int s , int mx = INF ) { 
	if( s == sink ) return mx;

	int ret = 0;
	for( int & e = pointer[s] ; e != -1 ; e = nex[e] ) { 
		if( cap[e] == 0 || h[to[e]] != h[s] + 1 ) continue;
		int tmp = dfs( to[e] , min(mx,cap[e]) );
		if( tmp ) { 
			ret += tmp;
			cap[e] -= tmp ;
			cap[e^1] += tmp;
			mx -= tmp;
		}
		if( mx == 0 ) 
			break;
	}
	return ret;
}
void bfs() { 
	memset(h,-1,sizeof h);
	int st = 0, en = 1;
	que[0] = source;
	h[0] = 0;
	while( st < en ) {
		int s = que[st++];
		for( int e = head[s] ; e != -1 ; e = nex[e] ) 
			if( h[to[e]] == -1 && cap[e] > 0 ) {
				h[to[e]] = h[s] + 1;
				que[en++] = to[e];
			}
	}
}

int getMaxFlow() { 
	int flow = 0;
	while( 1 ) {
		bfs();
		for( int i = 0 ; i < maxN ; i++ ) pointer[i] = head[i];
		int tmp = dfs(source);
		if( tmp == 0 ) break;
		flow += tmp;
	}
	return flow;
}

const int maxH = 20000 + 10;
int p[maxH];

int a[maxN];

vector<vector<int>> ans; 

void findAns( int s  ) { 
//	cout << s << endl;
	mark[s] = true;
	ans.back().push_back(s);
	int x = a[s] & 1;
	for( int e = head[s] ; e != -1 ; e = nex[e] ) { 
		if( to[e] == source || to[e] == sink ) continue;
		if( cap[e] == x &&  !mark[to[e]] ) 
			findAns( to[e] ) ;
	}
}

int main() { 
	memset(head,-1,sizeof head);
	for( int i = 2 ; i < maxH ; i++ ) 
		for( int j = i + i ; j < maxH ; j += i ) 
			p[j] = 1;
	int n;
	cin >> n;
	for( int i = 1 ; i <= n; i++ ) 
		cin >> a[i];

	
	source = 0, sink = n + 1;
	int sum = 0;
	for( int i = 1 ; i <= n ; i++ ) 
		if( a[i] & 1 ) addEdge( i , sink , 2 ) ; 
		else { 
			sum++;
			addEdge( source , i , 2 ) ; 
			for( int j = 1 ; j <= n ; j++ ) 
				if( p[a[i]+a[j]] == 0 ) 
					addEdge( i , j , 1 ) ; 
		}
	if( sum != n - sum || getMaxFlow() < 2*sum  ) { 
		cout << "Impossible" << endl; 
		return 0;
	}

	memset(mark,0,sizeof mark);
	for( int i = 1 ; i <= n ; i++ ) 
		if( !mark[i] ) {
			ans.push_back(vector<int>());
			findAns(i) ; 
		}
	cout << ans.size() << endl;
	for( int i = 0 ; i < sz(ans) ; i++ ) {
		cout << sz(ans[i]) ;
		for( int j = 0 ; j < sz(ans[i]) ; j++ ) 
			cout << ' ' << ans[i][j] ;
		cout << endl;
	}
}