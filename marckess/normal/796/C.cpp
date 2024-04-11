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

int n, a, b, x;
int v[300002];
vector<vi> adj;
map<int,int> m;

int mn = 2e9;
void obtieneMax(){
	for(int i = 1; i <= n; i++){
		//Decrementa
		int fi = v[i];
		m[fi]--;
		m[fi-2]++;
		for(int j = 0; j < adj[i].size(); j++){
			int u = adj[i][j];
			int fu = v[u];
			m[fu]--;
			m[fu-1]++;
		}

		//Compara
		map<int,int>::iterator it = m.end();
		--it;
		while( it->se == 0 )
			--it;
		mn = min(mn, it->fi);

		//Restaura
		m[fi]++;
		m[fi-2]--;
		for(int j = 0; j < adj[i].size(); j++){
			int u = adj[i][j];
			int fu = v[u];
			m[fu]++;
			m[fu-1]--;
		}
	}
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> v[i];
		v[i] += 2;
		m[v[i]]++;
	}

	adj.assign(n+1,vi(0,0));
	for(int i = 1; i < n; i++){
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a); 
	}
	
	obtieneMax();

	cout << mn << endl;
	return 0;
}