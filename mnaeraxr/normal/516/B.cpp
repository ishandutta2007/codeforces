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

char M[2010][2010];
int ID[2010][2010];

int n, m;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, 1, -1};
char V1[4] = {'v', '^', '<', '>'};
char V2[4] = {'^', 'v', '>', '<'};

bool inside(int x, int y){
	return 0 <= x && x < n && 0 <= y && y < m;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; ++i)
		cin >> M[i];

	queue<pii> Q;
	int tot = 0;

	for (int i = 0; i < n; ++i){
		for (int j = 0; j < m; ++j){
			if (M[i][j] != '.') continue;
			tot++;
			for (int k = 0; k < 4; ++k){
				int cx = i + dx[k], cy = j + dy[k];
				if (inside(cx, cy) && M[cx][cy] == '.'){
					ID[i][j]++;
				}
			}
			if (ID[i][j] == 1){
//				DB(i); DB(j);
				Q.push(MP(i,j));
			}
		}
	}

	while (!Q.empty()){
		pii cur = Q.front(); Q.pop();
		int x = cur.first, y = cur.second;
		if (M[x][y] != '.') continue;

		for (int k = 0; k < 4; ++k){
			int cx = x + dx[k], cy = y + dy[k];
			if (inside(cx, cy) && M[cx][cy] == '.'){
				M[x][y] = V1[k];
				M[cx][cy] = V2[k];

				for (int l = 0; l < 4; ++l){
					int ox = cx + dx[l], oy = cy + dy[l];
					if (inside(ox, oy) && M[ox][oy] == '.')
					{
						ID[ox][oy]--;
						if (ID[ox][oy] == 1) Q.push(MP(ox, oy));
					}
				}

				tot -= 2;
				break;
			}
		}
	}

	if (tot)
		cout << "Not unique" << endl;
	else{
		for (int i = 0; i < n; ++i)
			cout << M[i] << endl;
	}

	return 0;
}