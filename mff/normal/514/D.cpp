#include <bits/stdc++.h>

using namespace std;

#define DB(x) cout<<#x<<"="<<x<<endl;
#define SZ(x) (int)((x).size())
#define MP make_pair

typedef long long int64;
typedef pair<int64,int64> pii;
typedef vector<int> vi;

const int oo = 0x3f3f3f3f;
const double EPS = 1e-9;
const int MAXN = (int)1e5 + 100;
const int LOG = 18;

int64 L[5][MAXN];
int64 R[5][LOG][MAXN];

void build(int n, int ind)
{
	for (int i = 0; i < n; ++i)	R[ind][0][i] = L[ind][i];
	for (int i = 1; (1 << i) <= n; ++i)
		for (int j = 0; j < n; ++j)
			R[ind][i][j] = max(R[ind][i - 1][j], R[ind][i - 1][min(n - 1, j + (1 << (i - 1)))]);
}

int64 query(int a, int b, int ind)
{
	if (b < a) swap(a, b);
	int l = __lg(b - a + 1);
	return max(R[ind][l][a], R[ind][l][b - (1 << l) + 1]);
}

int64 ANS[5];

int main()
{
	int n, m, k;
	cin >> n >> m >> k;
	for (int i = 0; i < n; ++i){
		for (int j = 0; j < m; ++j)
			cin >> L[j][i];
	}
	for (int i = 0; i < m; ++i)
		build(n, i);

	int best = 0;

	for (int i = 0; i < n; ++i){
		int64 sm = 0;
		for (int j = 0; j < m; ++j)
			sm += L[j][i];
		if (sm > k) continue;
		int lo = 0, hi = i;
		while (lo < hi){
			int mid = (lo + hi) >> 1;
			sm = 0;
			for (int j = 0; j < m; ++j){
				sm += query(mid, i, j);
			}
			if (sm <= k) hi = mid;
			else lo = mid + 1;
		}
		if (i - lo + 1 > best){
			best = i - lo + 1;
			for (int j = 0; j < m; ++j)
				ANS[j] = query(lo, i, j);
		}
	}

	for (int j = 0; j < m; ++j)
		cout << ANS[j] << " \n"[j == m - 1];
}