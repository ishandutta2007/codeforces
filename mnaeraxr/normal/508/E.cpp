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
const int MAXN = 1210;

int L[MAXN], R[MAXN];
int DIST[MAXN];

bool mk[MAXN][MAXN];
bool memo[MAXN][MAXN];
bool _close[MAXN];

bool solve(int b, int e){
	if (mk[b][e]) return memo[b][e];

	mk[b][e] = true;
	bool &val = memo[b][e];

	if (b == e){
		if (L[b] == 1){
			DIST[b] = 1;
			return val = true;
		}
		return val = false;
	}

	for (int i = (L[b] - 1) >> 1; 2 * i + 1 <= R[b]; ++i)
	{
		if (!i){
			if (solve(b, b) && solve(b + 1, e))
				return val = true;
		}
		else{
			if (b + i == e && solve(b + 1, e))
			{
				DIST[b] = 2 * i + 1;
				return val = true;
			}

			if (b + i + 1 > e) break;

			if (solve(b + 1, b + i) && solve(b + i + 1, e))
			{
				DIST[b] = 2 * i + 1;
				return val = true;
			}
		}
	}
	return val = false;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n; cin >> n;
	for (int i = 0 ; i < n; ++i){
		cin >> L[i] >> R[i];
		if (L[i]%2==0)++L[i];
		if (R[i]%2==0)--R[i];

		if (R[i]<L[i]){
			cout << "IMPOSSIBLE" << endl;
			return 0;
		}
	}

	if (solve(0, n - 1))
	{
		int pnt = 0;
		for (int i = 0; i < n; ++i){
			while (_close[pnt]){
				putchar(')');
				++pnt;
			}
			putchar('(');
			_close[pnt + DIST[i]] = true;
			pnt++;
		}
		while (pnt < 2 * n){
			putchar(')');
			++pnt;
		}
		putchar('\n');
	}
	else{
		cout << "IMPOSSIBLE" << endl;
	}

	return 0;
}