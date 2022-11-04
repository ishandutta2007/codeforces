#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define first fi
#define second se
#define SET(p,n) memset(p, n, sizeof(p));

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;

int n, m, k;
char v[1005][1005];
int dist[1005][1005];

set<int> col[1005], fil[1005];
int arr[1005][1005], aba[1005][1005], izq[1005][1005], der[1005][1005];

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n >> m >> k;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			cin >> v[i][j];

			if (v[i][j] == '.') {
				fil[i].insert(j);
				col[j].insert(i);
			}
		}

	for (int i = 0; i < n; i++) {
		int ant = -1;
		for (int j = 0; j < m; j++)
			if (v[i][j] == '.')
				izq[i][j] = ant;
			else
				ant = j;

		ant = m;
		for (int j = m-1; j >= 0; j--)
			if (v[i][j] == '.')
				der[i][j] = ant;
			else
				ant = j;
	}

	for (int j = 0; j < m; j++) {
		int ant = -1;
		for (int i = 0; i < n; i++)
			if (v[i][j] == '.')
				arr[i][j] = ant;
			else
				ant = i;

		ant = n;
		for (int i = n-1; i >= 0; i--)
			if (v[i][j] == '.')
				aba[i][j] = ant;
			else
				ant = i;
	}

	int a, b, c, d;

	cin >> a >> b >> c >> d;
	a--, b--, c--, d--;

	queue<ii> q;
	q.emplace(a, b);
	fil[a].erase(b);
	col[b].erase(a);
	dist[a][b] = 0;

	while (q.size()) {
		tie (a, b) = q.front(); q.pop();

		if (a == c && b == d) {
			cout << dist[a][b] << endl;
			return 0;
		}

		int ini = max(izq[a][b]+1, b-k), fin = min(der[a][b]-1, b+k);
		for (auto it = fil[a].lower_bound(ini); it != fil[a].end() && *it <= fin; it) {
			dist[a][*it] = dist[a][b] + 1;
			q.emplace(a, *it);

			auto ant = it;
			col[*it].erase(a);
			it++;
			fil[a].erase(ant);
		}

		ini = max(arr[a][b]+1, a-k), fin = min(aba[a][b]-1, a+k);
		for (auto it = col[b].lower_bound(ini); it != col[b].end() && *it <= fin; it) {
			dist[*it][b] = dist[a][b] + 1;
			q.emplace(*it, b);

			auto ant = it;
			fil[*it].erase(b);
			it++;
			col[b].erase(ant);
		}
	}

	cout << -1 << endl;

	return 0;
}