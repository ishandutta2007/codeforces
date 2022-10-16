#include <bits/stdc++.h>

using namespace std;

typedef long long int64;
typedef vector<int> vi;
typedef pair<int,int> pii;

const int oo = 0x3f3f3f3f;
const double eps = 1e-9;
const int maxn = 100010;

struct event{
	int t, v;
	int x, y;

	void read(){
		cin >> t;
		if (t == 3) cin >> x >> y;
		cin >> v;
	}
};

int ans[110][110];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m, q;
	cin >> n >> m >> q;

	vector<event> query(q);

	for (int i = 0; i < q; ++i){
		query[i].read();
	}

	for (int i = q - 1; i >= 0; --i){
		if (query[i].t == 3) ans[query[i].x - 1][query[i].y - 1] = query[i].v;
		else if (query[i].t == 1){
			int x = query[i].v - 1;
			int l = ans[x][m - 1];
			for (int j = m - 1; j; --j)
				ans[x][j] = ans[x][j - 1];
			ans[x][0] = l;
		}
		else{
			int x = query[i].v - 1;
			int l = ans[n - 1][x];
			for (int j = n - 1; j; --j)
				ans[j][x] = ans[j - 1][x];
			ans[0][x] = l;
		}
	}

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			cout << ans[i][j] << " \n"[j + 1 == m];
	return 0;
}