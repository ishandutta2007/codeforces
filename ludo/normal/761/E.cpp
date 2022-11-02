#include<bits/stdc++.h>

#define x first
#define y second
#define pb push_back

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<ll, ll> pii;

const int maxn = 30;

vi E[maxn];
bool vis[maxn];
pii coord[maxn];

int N;
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };

void rec(int i, pii loc, ll sz, int noDir)
{
	vis[i] = true;
	coord[i] = loc;
	int curDir = (noDir + 1) % 4;

	for (int j : E[i]) {
		if (vis[j]) continue;

		pii nloc(coord[i].x + sz * dx[curDir], coord[i].y + sz * dy[curDir]);
		rec(j, nloc, sz / 2, (curDir + 2) % 4);
		curDir = (curDir + 1) % 4;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	for (int i = N; --i; ) {
		int u, v;
		cin >> u >> v;
		E[u-1].pb(v-1);
		E[v-1].pb(u-1);
	}

	for (int i = 0; i < N; i++) {
		if (E[i].size() > 4) {
			cout << "NO" << endl;
			return 0;
		}
	}

	rec(0, pii(0, 0), 1LL << 32, 0);
	cout << "YES" << endl;
	for (int i = 0; i < N; i++) {
		cout << coord[i].x << " " << coord[i].y << endl;
	}
	return 0;
}