//In the name of Allah
#include <bits/stdc++.h>
using namespace std;

#define __sz(x) ((int)(x).size())
typedef long long ll;
typedef double ld; 
const int maxN = 50 + 10; 
const int maxM = 500 * 2 * 2 + 10; 
int head[maxN]; 
int nex[maxM], to[maxM], cap[maxM], ecnt; 

int so,si; 
void add_edge( int u , int v , int c ) { 
	to[ecnt] = v , nex[ecnt] = head[u] , head[u] = ecnt , cap[ecnt++] = c;
	to[ecnt] = u , nex[ecnt] = head[v] , head[v] = ecnt , cap[ecnt++] = 0;
}

struct edge { 
	int u,v,w; 
} e[maxM]; 

int par[maxN], mn[maxN]; 
const int inf = 1e9; 
int que[maxN] , en; 
int bfs() { 
	memset( par , -1 , sizeof par ) ; 
	mn[so] = inf;
	par[so] = -2; 
	en = 0;
	que[en++] = so; 
	for( int i = 0 ; i < en ; i++ ) { 
		int s = que[i]; 
		for( int e = head[s] ; e != -1 ; e = nex[e] ) { 
			if( cap[e] && par[to[e]] == -1 ) { 
				mn[to[e]] = min( mn[s] , cap[e] );  
				par[to[e]] = e; 
				que[en++] = to[e]; 
			}
		}
	}
	if( par[si] == -1 ) return 0; 
	int ret = mn[si]; 
	for( int s = si ; s != so ; s = to[par[s]^1] ) {
		cap[par[s]] -= ret; 
		cap[par[s]^1] += ret;
	}
	return ret; 
}

int getMaxFlow() { 
	int ret = 0,tmp; 
	while( ( ret += tmp = bfs() , tmp) ); 
	return ret; 
}

int n,m,x;


inline bool canDo( ld v ) { 
	memset( head , -1 , sizeof head ); 
	ecnt = 0; 
	so = 0 , si = n - 1; 
	for( int i = 0 ; i < m ; i++ )
		add_edge( e[i].u , e[i].v , int(min( (ld)e[i].w , v * (x+1) )  / v) ) ; 
	int ret = getMaxFlow();
	return ret >= x; 
}

int main() { 
	 cin >> n >> m >> x; 
	for( int i = 0 ; i < m ; i++ ) { 
		cin >> e[i].u >> e[i].v >> e[i].w; 
		e[i].u--; e[i].v--; 
	}
	ld s = 0 , e = 1e14; 
	for( int t = 0 ; t < 200; t++ ) { 
		ld m = (s+e)/2; 
		if( canDo(m) ) 
			s = m; 
		else
			e = m; 
	}
	cout << fixed << setprecision(6) << x*s << endl;
}