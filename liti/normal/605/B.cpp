//In the name of Allah
#include <bits/stdc++.h>
using namespace std;

const int maxN = 1000*100 + 100; 
pair<pair<int,bool>,int> edge[maxN];

int par[maxN];
int dfind( int u ) { 
	return par[u] < 0 ? u : par[u] = dfind(par[u]); 
}
void merge( int u , int v ) { 
	u = dfind(u), v = dfind(v); 
	if( u == v ) return; 
	par[u] = v; 
}

pair<int,int> ans[maxN]; 

int main() { 
	ios::sync_with_stdio(false); cin.tie(0); 
	memset( par , -1 , sizeof par ); 
	
	int n,m; 
	cin >> n >> m;
	for( int i = 0; i < m ; i++ ) { 
		cin >> edge[i].first.first >> edge[i].first.second; 
		edge[i].first.second ^= 1 ;
		edge[i].second = i; 
	}
	sort( edge , edge + m ); 

	long long rem = 0; 
	int curr = 0; 

	int first = 1 , second = 2; 
	for( int i = 0 ; i < m ; i++ ) { 
		if( edge[i].first.second == 1 ) { 
			rem--; 
			ans[edge[i].second] = { first , second } ; 
			first++; 
			if( second == first )
				second++ , first = 1; 


			if( rem < 0 ) { 
				cout << -1 << endl; 
				return 0;
			}
		} else { 
			ans[edge[i].second] = { 0 , curr + 1 }; 
			curr++; 	
			rem += curr - 1; 
		}
	}
	for( int i = 0 ; i < m ; i++ ) 
		cout << ans[i].first + 1 << ' '<< ans[i].second + 1 << '\n';
}