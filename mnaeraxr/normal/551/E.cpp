#include <iostream>
#include <algorithm>

using namespace std;

#define endl '\n'
#define DB(x) cout << #x << " = " << x << endl << flush;
#define SZ(x) (int)((x).size())
#define MP make_pair

typedef long long int64;
typedef pair<int64, int64> pii;

const int64 oo = 0x3f3f3f3f3f3f3f3f;
const double EPS = 1e-9;

const int MAXN = (int)5e5 + 10;
const int MAGIC = 710;

int64 BLOCK[MAXN / MAGIC + 1][MAGIC];
pii MBLCK[MAXN / MAGIC + 1][MAGIC];
int64 C[MAXN / MAGIC + 1];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, q;
	cin >> n >> q;

	int pnt = 0, blc = 0;
	for (int i = 0; i < n; ++i, ++pnt){

		if (pnt == MAGIC){
			sort(MBLCK[blc], MBLCK[blc] + MAGIC);
			++blc;
			pnt = 0;
		}

		cin >> BLOCK[blc][pnt];
		MBLCK[blc][pnt] = MP(BLOCK[blc][pnt], i);
	}

	sort(MBLCK[blc], MBLCK[blc] + pnt);


	while (q--){
		int t; cin >> t;

		if (t == 1){
			int u, v;
			int64 x;
			cin >> u >> v >> x;
			u--; v--;
			int bu = u / MAGIC;
			int pu = u % MAGIC;
			int bv = v / MAGIC;
			int pv = v % MAGIC;

			if (bu == bv){
				int top = bv == blc ? pnt : MAGIC;
				for (int i = 0; i < top; ++i){
					BLOCK[bu][i] += C[bu] + ((pu <= i && i <= pv) ? x : 0);
					MBLCK[bu][i] = MP(BLOCK[bu][i], bu * MAGIC + i);
				}
				sort(MBLCK[bu], MBLCK[bu] + top);
				C[bu] = 0;
			}
			else{
				for (int i = 0; i < MAGIC; ++i){
					BLOCK[bu][i] += C[bu] + ((pu <= i) ? x : 0);
					MBLCK[bu][i] = MP(BLOCK[bu][i], bu * MAGIC + i);
				}
				sort(MBLCK[bu], MBLCK[bu] + MAGIC);
				C[bu] = 0;

				int top = bv == blc ? pnt : MAGIC;
				for (int i = 0; i < top; ++i){
					BLOCK[bv][i] += C[bv] + ((i <= pv) ? x : 0);
					MBLCK[bv][i] = MP(BLOCK[bv][i], bv * MAGIC + i);
				}
				sort(MBLCK[bv], MBLCK[bv] + top);
				C[bv] = 0;

				for (int i = bu + 1; i < bv; ++i)
					C[i] += x;
			}
		}
		else{
			int64 v; cin >> v;
			pii ans = MP(-1, -1);
			for (int i = 0; i <= blc; ++i){

				int top = i == blc ? pnt : MAGIC;

				int pos = lower_bound(MBLCK[i], MBLCK[i] + top, MP(v - C[i], -oo)) - MBLCK[i];
				if (pos == top || MBLCK[i][pos].first + C[i] != v)
					continue;
				if (ans.first == -1) ans = MP(MBLCK[i][pos].second, MBLCK[i][pos].second);
				else{
					ans.first = min(ans.first, MBLCK[i][pos].second);
					ans.second = max(ans.second, MBLCK[i][pos].second);
				}

				pos = upper_bound(MBLCK[i], MBLCK[i] + top, MP(v - C[i] + 1, -oo)) - MBLCK[i];
				pos--;
				ans.first = min(ans.first, MBLCK[i][pos].second);
				ans.second = max(ans.second, MBLCK[i][pos].second);
			}

			if (ans.first == -1) cout << -1 << endl;
			else cout << ans.second - ans.first << endl;
		}
	}

	return 0;
}