#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define DB(x) cout<<#x<<"="<<x<<endl;
#define SZ(x) (int)((x).size())
#define MP make_pair

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int oo = 0x3f3f3f3f;
const double EPS = 1e-9;
const int MAXN = (int)1e5 + 10;

char M[510][510];
char F[510][510];
int n, m;
pii last;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

bool dfs(pii cur)
{
	for (int i = 0; i < 4; ++i){
		int nxt_x = cur.first + dx[i], nxt_y = cur.second + dy[i];
		if (MP(nxt_x, nxt_y) == last) return true;
		if (nxt_x < 0 || nxt_x >= n || nxt_y < 0 || nxt_y >= m || M[nxt_x][nxt_y] == 'X')continue;
		M[nxt_x][nxt_y] = 'X';
		if (dfs(MP(nxt_x, nxt_y))) return true;
	}
	return false;
}



int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; ++i){
		cin >> M[i];
		for (int j = 0; j < m; ++j)
			F[i][j] = M[i][j];
	}

	pii start;
	cin >> start.first >> start.second;
	cin >> last.first >> last.second;
	start.first--; start.second--;
	last.first--; last.second--;

	if (!dfs(start))
		cout << "NO" << endl;
	else{
		if (M[last.first][last.second] == 'X')
			cout << "YES" << endl;
		else{
			int cnt = 0;
			for (int i = 0; i < 4; ++i)
			{
				int nxt_x = last.first + dx[i], nxt_y = last.second + dy[i];
				if (nxt_x < 0 || nxt_x >= n || nxt_y < 0 || nxt_y >= m || ((MP(nxt_x, nxt_y) != start) && F[nxt_x][nxt_y] == 'X'))continue;
				cnt++;
			}
			if (cnt >= 2)
				cout << "YES" << endl;
			else
				cout << "NO" << endl;
		}
	}

	return 0;
}