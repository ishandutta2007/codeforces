#include <bits/stdc++.h>

using namespace std;

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

struct t{
	int hp, atk, def;
	t(){
		cin >> hp >> atk >> def;
	}
};

const int it = 210;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("data.in", "r", stdin);
	// freopen("data.out", "w", stdout);
#endif

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	t y, m, p;
	int ans = -1;

	for (int i = 0; i < it; ++i){
		for (int j = 0; j < it; ++j){
			for (int k = 0; k < it; ++k){
				int dy = max(0, y.atk + i - m.def);
				int dm = max(0, m.atk - (y.def + j));
				int pr = i * p.atk + j * p.def;
				if (dy == 0) continue;
				if (dm == 0) ans = ans == -1 ? pr : min(ans, pr);
				else{
					int ty = (m.hp + dy - 1) / dy;
					int tm = (y.hp + dm - 1) / dm;
					if (ty < tm) ans = ans == -1 ? pr : min(ans, pr);
					else{
						int lo = 0, hi = 1;
						while ( ty >= (y.hp + dm - 1 + hi) / dm )
							hi *= 2;
						while (lo + 1 < hi){
							int mid = (lo + hi) / 2;
							tm = (y.hp + dm - 1 + mid) / dm;
							if (ty >= tm) lo = mid;
							else hi = mid;
						}
						pr += p.hp * hi;
						ans = ans == -1 ? pr : min(ans, pr);
					}
				}
			}
		}
	}

	cout << ans << endl;

	return 0;
}