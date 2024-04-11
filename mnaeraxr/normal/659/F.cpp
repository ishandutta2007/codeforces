#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define MP make_pair
#define DB(x) cout << #x << "=" << x << endl

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int maxn = 1000000 + 10;

int f[maxn];
int c[maxn];
int mp[1010][1010];
int nmap[1010][1010];

int root(int u){
	return u == f[u] ? u : f[u] = root(f[u]);
}

void join(int u, int v){
	u = root(u), v = root(v);
	if (u == v) return;
	if (rand() & 1) swap(u, v);
	c[u] += c[v];
	f[v] = u;
}


int n, m;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

bool ins(int x, int n){
	return 0 <= x && x < n;
}

void dfs(pii pos, int &kk, int &v){
//	cout << pos.first << " " << pos.second << " " << kk << endl;

	if (kk == 0) return;

	int x = pos.first;
	int y = pos.second;

	nmap[x][y] = v;
	kk--;

	for (int k = 0; k < 4; ++k){
		int nx = x + dx[k];
		int ny = y + dy[k];
		if (ins(nx, n) && ins(ny, m) && nmap[nx][ny] == 0 && mp[nx][ny] >= v)
			dfs({nx, ny}, kk, v);
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int64 k;
	cin >> n >> m >> k;

	for (int i = 0; i < n * m; ++i){
		f[i] = i;
		c[i] = 1;
	}

	vector<pair<int,pii>> v(n * m);

	for (int i = 0; i < n; ++i){
		for (int j = 0; j < m; ++j){
			cin >> mp[i][j];
			v[i * m + j] = {mp[i][j], {i, j}};
		}
	}

	sort(v.begin(), v.end());
	reverse(v.begin(), v.end());

	for (int i = 0, j; i < n * m; i = j){

		for (j = i; j < n * m && v[j].first == v[i].first; ++j){
			pii cur = v[j].second;
//			cout << cur.first << " " << cur.second << " " << v[j].first << endl;
			for (int k = 0; k < 4; ++k){
				int nx = cur.first + dx[k];
				int ny = cur.second + dy[k];

				if (ins(nx, n) && ins(ny, m) && mp[nx][ny] >= v[j].first){
					join(cur.first * m + cur.second, nx * m + ny);
				}
			}
			int id = cur.first * m + cur.second;

//			cout << c[root(id)] << endl;

			if (k % v[j].first == 0 && c[root(id)] >= k / v[j].first){
				int tot = k / v[j].first;
				dfs(v[j].second, tot, v[j].first);

				cout << "YES" << endl;
				for (int i = 0; i < n; ++i)
					for (int j = 0; j < m; ++j)
						cout << nmap[i][j] << " \n"[j + 1 == m];
				exit(0);
			}
		}

	}

	cout << "NO" << endl;


	return 0;
}