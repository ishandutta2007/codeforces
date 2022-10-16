#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int oo = 0x3f3f3f3f;
const double eps = 1e-9;
const int maxn = 1002;

int dist[ maxn ][ maxn ][ 4 ];
char world[ maxn ][ maxn ];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

struct pos{
	int x, y, d;

	bool operator <(const pos &p) const{
		return false;
	}
};

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

#ifdef MARX
	freopen("data.in", "r", stdin);
	// freopen("data.out", "w", stdout);
#endif

	int n, m;
	cin >> n >> m;

	memset( dist, oo, sizeof dist );

	pii S, T;

	for (int i = 0; i < n; ++i){
		cin >> world[i];

		for (int j = 0; j < m; ++j){
			if (world[i][j] == 'S') S = pii(i, j);
			if (world[i][j] == 'T') T = pii(i, j);
		}
	}

	priority_queue< pair<int,pos> > q;

	for (int i = 0; i < 4; ++i){
		dist[ S.first ][ S.second ][ i ] = 0;
		pos cur = {S.first, S.second, i};
		q.push( make_pair(0, cur) );
	}

	while (!q.empty()){
		auto cur = q.top(); q.pop();
		
		int d = -cur.first;
		auto p = cur.second;
		int dir = p.d;

		if (d == 3) break;

		if (dist[ p.x ][ p.y ][ p.d ] < d)
			continue;

		for (int i = 0; i < 4; ++i){
			if ( dist[ p.x ][ p.y ][ i ] > d + 1 ){
				dist[ p.x ][ p.y ][ i ] = d + 1;
				q.push( { -(d + 1), {p.x, p.y, i} } );
			}
		}

		int nx = p.x + dx[ dir ], ny = p.y + dy[ dir ];
		if (0 <= nx && nx < n && 0 <= ny && ny < m && world[ nx ][ ny ] != '*'){
			if (dist[ nx ][ ny ][ dir ] > d ){
				dist[ nx ][ ny ][ dir ] = d;
				q.push( {-d, {nx, ny, dir} });
			}
		}
	}

	bool ok = false;

	for (int i = 0; i < 4; ++i)
		ok |= dist[ T.first ][ T.second ][i] <= 2;

	cout << (ok ? "YES" : "NO") << endl;

	return 0;
}