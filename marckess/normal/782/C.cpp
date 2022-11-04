#include <bits/stdc++.h>

#define ll long long
#define vi vector<int>
#define vb vector<bool>
#define ii pair<int, int>
#define vii vector<ii>
#define fi first
#define se second
#define endl '\n'

#define isOn(S, j) (S & (1 << j) )
#define setBit(S, j) (S |= (1 << j ) )
#define LSB(S) (S & (-S))

using namespace std;

vector<vi> adj;
vi color(200005,0);
int n, a, b, x;

int colorear(int prim){
	int mx = 0;

	queue<ii> q;
	q.push (ii(prim,0));
	color[prim] = 1;

	while ( q.size() ){
		int u = q.front().fi, p = q.front().se; q.pop();

		for(int i = 0, j = 1; i < adj[u].size(); i++){
			int v = adj[u][i];
			if ( color[v] )
				continue;
			while ( j == color[u] || j == p ) 
				j++;

			color[v] = j++;
			q.push(ii(v, color[u]));
		}

		mx = max ( mx, (int)adj[u].size() + 1 );
	}

	return mx;
}

int main(){
	//ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	adj.assign(n+3,vi(0,0));

	for(int i = 1; i < n; i++){
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	int i = 1;
	while ( adj[i].size() != 1 )
		i++;

	cout << colorear(i) << endl;
	for(int i = 1; i <= n; i++)
		cout << color[i] << " ";
	cout << endl;

	return 0;
}