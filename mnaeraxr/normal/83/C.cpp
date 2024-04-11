#include <bits/stdc++.h>

using namespace std;

typedef long long int64;
typedef vector<int> vi;
typedef pair<int,int> pii;

const int oo = 0x3f3f3f3f;
const double eps = 1e-9;
const int maxn = 100;

int n, m;
char mp[maxn][maxn];
int mat[2][maxn][maxn];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
bool exist[26];
bool valid[26];

int totPareto[2];
pii pareto[2][maxn * maxn];
set<pii> seen;

pii p1, p2;
string best = "$";

bool bfs(pii b, pii e, int id){
	memset(mat[id], oo, sizeof mat[id]);
	queue<pii> q;
	q.push(b);
	mat[id][b.first][b.second] = 0;
	while (!q.empty()){
		pii cur = q.front(); q.pop();
		for (int k = 0; k < 4; ++k){
			int x = cur.first + dx[k];
			int y = cur.second + dy[k];
			if (0 <= x && x < n && 0 <= y && y < m && mat[id][x][y] == oo && (mp[x][y] == 'T' || mp[x][y] == 'S' || valid[mp[x][y] - 'a'])){
				mat[id][x][y] = mat[id][cur.first][cur.second] + 1;
				q.push({x, y});
			}
		}
	}
	return mat[id][e.first][e.second] < oo;
}

string getBest(){
	string ans = "";
	int d = mat[0][p2.first][p2.second];

//	for (int i = 0; i < n; ++i)
//		for (int j = 0; j < m; ++j)
//			cout << mat[0][i][j] << " \n"[j + 1 == m];

	totPareto[0] = 1;
	totPareto[1] = 0;
	pareto[0][0] = p1;
	int cur = 0, nxt = 1;

	while (pareto[cur][0] != p2){
//		cout << "step" << endl;
//		cout << p.first << " " << p.second << endl;
		char c = (char)('z' + 1);

		totPareto[nxt] = 0;

		for (int i = 0; i < totPareto[cur]; ++i){
			pii p = pareto[cur][i];

			for (int k = 0; k < 4; ++k){
				int x = p.first + dx[k];
				int y = p.second + dy[k];
				if (0 <= x && x < n && 0 <= y && y < m && mat[0][x][y] + mat[1][x][y] == d && mat[0][x][y] == mat[0][p.first][p.second] + 1){
					if (mp[x][y] < c){
						c = mp[x][y];
						totPareto[nxt] = 0;
						seen.clear();
					}
					if (mp[x][y] == c){
						if (!seen.count(pii(x, y))){
							pareto[nxt][totPareto[nxt]++] = {x, y};
							seen.insert({x, y});
//							cout << totPareto[nxt] << endl;
						}
					}
				}
			}
		}

//		cout << nxt.first << " " << nxt.second << endl;
//		cout << c << endl;
//
//		exit(0);

		if (c != 'T')
			ans += c;

		swap(cur, nxt);
	}

//	cout << "answer: " << ans << endl;
	return ans;
}

void bt(int t, int k, int c){
	if (c == k){
//		cout << "HERE" << endl;
		if (bfs(p1, p2, 0) && bfs(p2, p1, 1)){
//			cout << "INSIDE" << endl;
			if (best == "$" || mat[0][p2.first][p2.second] - 1 <= (int)best.length()){
				string cur = getBest();
				if (best == "$") best = cur;
				if (cur.length() < best.length()) best = cur;
				else if (cur < best) best = cur;
			}
		}
//		cout << "END" << endl;
	}
	else{

		for (int i = t; i < 26; ++i){
//			if (exist[i]){
				valid[i] = true;
				bt(i + 1, k, c + 1);
				valid[i] = false;
//			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int k;
	cin >> n >> m >> k;

	for (int i = 0; i < n; ++i){
		cin >> mp[i];
		for (int j = 0; j < m; ++j){
			if (mp[i][j] == 'S') p1 = pii(i, j);
			if (mp[i][j] == 'T') p2 = pii(i, j);
			exist[mp[i][j] - 'a'] = true;
		}
	}

	// Empty sequence

	bt(0, k, 0);

	if (best == "$") cout << -1 << endl;
	else cout << best << endl;

	return 0;
}