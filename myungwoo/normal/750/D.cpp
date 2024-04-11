#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define fr first
#define sc secondd
#define all(v) (v).begin(), (v).end()
typedef long long lld;
typedef pair<int, int> pii;

int yy[2][4] = {{-1, 0, 1, 0}, {-1, -1, 1, 1}};
int xx[2][4] = {{0, 1, 0, -1}, {-1, 1, 1, -1}};

int N, ans;
int A[31];
bool vis[301][301][31][6][4];
bool V[301][301];

void dfs(int y, int x, int t, int c, int d)
{
	if (vis[y][x][t][c][d]) return;
	vis[y][x][t][c][d] = 1;
	if (!V[y][x]){ V[y][x] = 1; ans++; }
	int type = !(t&1);
	vector <int> dirs = {d};
	if (c == 0){
		if (t == N) return;
		if (t&1) dirs = {d, (d+1)%4};
		else dirs = {d, (d+3)%4};
		type ^= 1;
		t++; c = A[t];
	}
	for (int nd: dirs){
		int ny = y+yy[type][nd], nx = x+xx[type][nd];
		dfs(ny, nx, t, c-1, nd);
	}
}

int main()
{
	cin >> N;
	for (int i=1;i<=N;i++) cin >> A[i];
	dfs(150, 150, 1, A[1]-1, 0);
	cout << ans << endl;
}