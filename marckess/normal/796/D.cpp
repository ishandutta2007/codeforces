#include <bits/stdc++.h>

#define ll long long
#define vi vector<int>
#define vb vector<bool>
#define ii pair<int, int>
#define vii vector<ii>

#define isOn(S, j) (S & (1 << j) )
#define setBit(S, j) (S |= (1 << j ) )

using namespace std;

int c, d;
bitset<(int)3e5+5> police, road;
vector< vii > adj(3e5+5);
queue< ii > q;

void deleteRoad(){
	while ( q.size() ){
		ii u = q.front(); q.pop();
		for(int i = 0; i < adj[u.first].size(); i++){
			ii v = adj[u.first][i];
			if ( police[v.first] )
				continue;
			police[v.first] = 1;
			road[v.second] = 1;
			c--;
			if ( u.second < d )
				q.push((ii){v.first, u.second+1});
		}
	}
}

int main(){
	int n, k; cin >> n >> k >> d;
	int a, b, x;

	c = n - 1;
	while( k-- ){
		cin >> x;
		police[x] = true;
		q.push((ii){x,0});
	}

	for( int i = 1; i < n; i++){
		cin >> a >> b;
		adj[a].push_back((ii){b, i});
		adj[b].push_back((ii){a, i});
	}

	deleteRoad();
	cout << c << endl;
	for(int i = 1; i < n; i++)
		if ( !road[i] )
			cout << i << " ";

	return 0;
}