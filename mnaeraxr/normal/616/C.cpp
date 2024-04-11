#include <bits/stdc++.h>

using namespace std;

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int oo = 0x3f3f3f3f;
const double eps = 1e-9;
const int maxn = 1010;

vector<int> total;
string board[maxn];
int mat[maxn][maxn];
int n, m;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

bool inside(int x, int y){
	return 0 <= x && x < n && 0 <= y && y < m;
}

void bfs(int x, int y, int name){
	queue<pii> q;
	q.push(pii(x, y));
	int answer = 1;
	mat[x][y] = name;

	while (!q.empty()){
		pii cur = q.front(); q.pop();
		x = cur.first, y = cur.second;

		for (int i = 0; i < 4; ++i){
			int cx = x + dx[i];
			int cy = y + dy[i];
			if (inside(cx, cy) && !mat[cx][cy] && board[cx][cy] == '.'){
				q.push(pii(cx, cy));
				++answer;
				mat[cx][cy] = name;
			}
		}
	}
	total.push_back(answer);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; ++i){
		cin >> board[i];
	}

	total.push_back(0);
	int tot = 1;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			if (mat[i][j] == 0 && board[i][j] == '.')
				bfs(i, j, tot++);

	for (int i = 0; i < n; ++i){
		for (int j = 0; j < m; ++j){
			if (board[i][j] == '.')
				cout << '.';
			else{
				int t = 1;
				set<int> s;
				for (int d = 0; d < 4; ++d){
					int cx = i + dx[d];
					int cy = j + dy[d];
					if (inside(cx, cy) && mat[cx][cy] && s.count(mat[cx][cy]) == 0){
						s.insert(mat[cx][cy]);
						t += total[mat[cx][cy]];
					}
				}
				t %= 10;
				cout << t;
			}
		}
		cout << endl;
	}

	return 0;
}