#include <bits/stdc++.h>

using namespace std;

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

int d[1000100];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m, dx, dy;
	cin >> n >> m >> dx >> dy;	
	for (int i = 0, cur = 0; i < n; ++i, cur -= dx){
		if (cur < 0) cur += n;
		d[cur] = i;
	}

	map<int64,int> M;
	int64 ans = 0;
	int64 bx, by;

	for (int i = 0; i < m; ++i){
		int64 x, y;
		cin >> x >> y;
		int64 r = (y + 1LL * d[x] * dy % n) % n;
		int v = ++M[r];
		if (v > ans){
			ans = v;
			bx = x, by = y;
		}
	}

	cout << bx << " " << by << endl;

	return 0;
}