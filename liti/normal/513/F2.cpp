/* In the name of Allah */
#include <bits/stdc++.h>

using namespace std;

#define sz(x) (((int) x.size()))
typedef long long ll;

const int maxN = 5*500;
const int maxM = 1000*1000 + 100;
const int INF = 1e9;

int to[maxM], nex[maxM], cap[maxM], origCap[maxM];
ll wei[maxM];
int head[maxN];
int ptr[maxN];
int h[maxN];
int mcnt;
int source, sink;
int cnt;
ll limit;
int qq[maxN];

void add_edge( int u , int v , int c , ll w  = 0 ) { 
	to[mcnt] = v , nex[mcnt] = head[u] , head[u] = mcnt , origCap[mcnt] = cap[mcnt] = c , wei[mcnt++] =w ;
	to[mcnt] = u , nex[mcnt] = head[v] , head[v] = mcnt , origCap[mcnt] = cap[mcnt] = 0 , wei[mcnt++] =w ;
}

bool bfs() { 
	memset(h,-1,sizeof h);
	int st = 0 , en = 1; 
	h[source] = 0;
	qq[st] = source;
	while( st < en ) { 
		int s = qq[st++];
		for( int e = head[s] ; e != -1 ; e = nex[e] ) 
			if( cap[e] > 0 && h[to[e]] == -1 ) { 
				h[to[e]] = h[s] + 1;
				qq[en++] = to[e];
			}
	}
	return (h[sink] != -1);
}

int dfs( int s , int mx = INF ) { 
	if( s == sink ) 
		return mx;
	int ret = 0;
	for( auto& e = ptr[s] ; e != -1 ; e = nex[e] ) { 
		if( cap[e] == 0 || h[to[e]] != h[s] + 1) continue;
		int x = dfs(to[e], min(mx,cap[e]));
		ret += x;
		mx -= x;
		cap[e] -= x;
		cap[e^1] += x;
		if( mx == 0 ) 
			break;
	}
	return ret;
}

int getMaxFlow() { 
	for( int i = 0 ; i < mcnt ; i++ ) 
		cap[i] = (wei[i] <= limit ?origCap[i]:0) ;
	int flow = 0;
	while( bfs() ) { 
		for( int i = 0 ; i < maxN ; i++ ) 
			ptr[i] = head[i];
		flow += dfs(source);
	}
	return flow;
}

const int maxR = 25;
string a[maxR];
int con[maxR][maxR][2];
pair<int,int> que[maxR*maxR];
int dx[4] = { 0 , -1 , 0 , 1 } ;
int dy[4] = { -1 , 0 , 1 , 0 } ;
int dist[maxR][maxR];
int n,m;

bool isValid( int x , int y ) { 
	return( 0 <= x && x < n && 0 <= y && y < m && a[x][y] == '.' ) ;
}

void doJob( int x , int y , int t , int id ) { 
	int ind = cnt++;
	if( id == 0 ) 
		add_edge(source,ind,1);
	else
		add_edge(ind,sink,1);

	memset(dist,-1,sizeof dist);
	int st = 0, en = 1;
	que[st] = {x,y};
	dist[x][y] = 0;
	while( st < en ) { 
		auto s = que[st++];
		for( int k = 0 ; k < 4 ; k++ ) 
			if( isValid(s.first+dx[k],s.second+dy[k]) && dist[s.first+dx[k]][s.second+dy[k]] == -1 ) { 
				dist[s.first+dx[k]][s.second+dy[k]] = dist[s.first][s.second] + 1;
				que[en++] = {s.first+dx[k],s.second+dy[k]};
			}
	}

	for( int i = 0 ; i < n; i++ ) 
		for( int j = 0 ; j < m ; j++ ) if( a[i][j] == '.' && dist[i][j] != -1 ) {
			if( id == 0  ) 
				add_edge(ind,con[i][j][id],1,ll(t)*dist[i][j]);
			else
				add_edge(con[i][j][id],ind,1,ll(t)*dist[i][j]);
		}
}

int main() { 
	memset(head,-1,sizeof head);
	int female, male;
	cin >> n >> m >> male >> female;

	if( abs(male-female) != 1 ) { 
		cout << -1 << endl;
		return 0;
	}

	source = cnt++ ; 
	sink = cnt++;

	for( int i = 0 ; i < n ; i++ ) {
		cin >> a[i];
		for( int j = 0 ; j < m ; j++ ) if( a[i][j] == '.' ) {
			for( int k = 0 ; k < 2 ; k++ ) 
				con[i][j][k] = cnt++;
			add_edge(con[i][j][0],con[i][j][1],1);
		}
	}
		
	int x,y,t;
	cin >> x >> y >> t;
	x--; y--; 
	doJob( x , y , t , (female<male) ) ;
	for( int i = 0 ; i < male ; i++ ) {
		cin >> x >> y >> t;
		x--; y--;
		doJob( x , y , t , 0 );
	}
	for( int i = 0 ; i < female ; i++ ) { 
		cin >> x >> y >> t;
		x--; y--;
		doJob( x , y , t , 1 );
	}

	ll s = -1 , e = 1e14;
	int mx = max(male,female);
	while( e - s > 1 ) { 
//		cout << s << ' ' << e << endl;
		limit = (s+e)/2;
		if( getMaxFlow() == mx )
			e = limit;
		else
			s = limit;
	}
	if( e == ll(1e14) ) {
		cout << -1 << endl;
		return 0;
	}
	cout << e << endl;
}