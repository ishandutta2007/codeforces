#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <set>
#include <map>
#include <cassert>
#include <numeric>
#include <string>
#include <cstring>
#include <cmath>
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 42
#endif

typedef long long int int64;


const int N = (int) 3e5 + 100;
int as[N];
int a[N];

const int LOG = 18;
const int LEVEL = (1 << LOG);
const int SZ = (LEVEL << 1);

struct tree
{
	int mx[SZ];
	tree() : mx() 
	{
		memset(mx, -1, sizeof mx);
	}
	void set(int pos, int val)
	{
		pos += LEVEL;
		mx[pos] = max(mx[pos], val);
		pos /= 2;
		while (pos >= 1)
		{
			mx[pos] = max(mx[2 * pos], mx[2 * pos + 1] );
			pos /= 2;
		}
	}
	int getMax(int v, int l, int r, int tl, int tr)
	{
		if (tr < l || r < tl) return -1;
		if (l <= tl && tr <= r) return mx[v];
		int tm = (tl + tr) / 2;
		return max(
				getMax(2 * v, l, r, tl, tm),
				getMax(2 * v + 1, l, r, tm + 1, tr)
				);
	}
	int getMax(int l, int r)
	{
		if (l > r) return -1;
		return getMax(1, l, r, 0, LEVEL - 1);
	}
	int getMaxVal(int vl, int vr, int k)
	{
		int l = lower_bound(as, as + k, vl) - as;
		int r = upper_bound(as, as + k, vr) - as;
		r--;
		return getMax(l, r);
	}

} tree;

vector <int> listD[N], listU[N];

void init(int n, int k)
{
	for (int i = 0; i < n; i++)
	{
//		int cnt = 0;
//		eprintf("init i = %d\n", i);
		int deltaUp = as[k - 1] - as[a[i] ];
		while (true)
		{
//			cnt++;
//			if (cnt > LOG * 2) throw;
			int mxPos = tree.getMaxVal(as[a[i] ], as[a[i] ] + deltaUp, k);
//			eprintf("deltaUp = %d, mxPos = %d\n", deltaUp, mxPos);
			if (mxPos == -1) break;
			listU[i].push_back(mxPos);
			deltaUp = as[a[mxPos] ] - as[a[i] ];
//			eprintf("deltaUp = %d\n", deltaUp);
			if (deltaUp == 0) break;
			deltaUp /= 2;
		}
		int deltaDown = as[a[i] ] - as[0];
//		cnt = 0;
		while (true)
		{
//			cnt++;
//			if (cnt > LOG * 2) throw;
//			eprintf("i = %d: %d ... %d\n", i, as[a[i] ] - deltaDown, as[a[i] ] );
			int mxPos = tree.getMaxVal(as[a[i] ] - deltaDown, as[a[i] ], k);
//			eprintf("deltaDown = %d, mxPos = %d\n", deltaDown, mxPos);
			if (mxPos == -1) break;
			listD[i].push_back(mxPos);
			deltaDown = as[a[i] ] - as[a[mxPos] ];
			if (deltaDown == 0) break;
			deltaDown /= 2;
		}
		tree.set(a[i], i);
	}

//	for (int x : listD[15] )
//		eprintf("%d ", x);
//	eprintf("\n");
}


vector <int> qsmall[N];
vector <int> qu[N];
int ans[N];
const int BL = 320; // TODO
//const int BL = 5;

/*
int solveSlow(int l, int r)
{
	int answ = abs(as[a[r] ] - as[a[l] ] );
	for (int i = l; i <= r; i++)
		for (int j = i + 1; j <= r; j++)
			answ = min(answ, abs(as[a[i] ] - as[a[j] ] ) );
	return answ;
}
*/

int l[N], r[N];
bool cmpR(int i, int j)
{
	return r[i] < r[j];
}

int val[N], slow[N];

void solve(int n, int k)
{
	for (int i = 0; i < n; i++)
	{
		slow[i] = as[k - 1] - as[0];
		val[i] = as[k - 1] - as[0];
	}

	for (int bs = 0; bs < n; bs += BL)
	{
		int be = min(bs + BL - 1, n - 1);
//		eprintf("bs = %d, be = %d\n", bs, be);
		vector <int> qs;
		for (int i = bs; i <= be; i++)
			for (int x : qu[i] )
				qs.push_back(x);
		sort(qs.begin(), qs.end(), cmpR);
	

		for (int cr = bs; cr <= be; cr++)
		{
			for (int cl = bs; cl < cr; cl++)
				slow[cl] = min(slow[cl], abs(as[a[cr] ] - as[a[cl] ] ));
			for (int cl = cr - 1; cl >= bs; cl--)
				slow[cl] = min(slow[cl], slow[cl + 1] );
			while (!qsmall[cr].empty() )
			{
				int id = qsmall[cr].back();
				qsmall[cr].pop_back();
				ans[id] = slow[l[id] ];
			}
		}

		for (int i = be - 1; i >= bs; i--)
		{
			slow[i] = slow[i + 1];
			for (int j = i + 1; j <= be; j++)
				slow[i] = min(slow[i], abs(as[a[i] ] - as[a[j] ] ) );
		}

		int ptr = 0;
		int mnR = as[k - 1] - as[0] + 1;
		for (int i = be + 1; i <= n; i++)
		{
			while (!listD[i].empty() && listD[i].back() <= be)
			{
				int x = listD[i].back();
				val[x] = min(val[x], as[a[i] ] - as[a[x] ] );
				listD[i].pop_back();
			}
			while (!listU[i].empty() && listU[i].back() <= be)
			{
				int x = listU[i].back();
				val[x] = min(val[x], as[a[x] ] - as[a[i] ] );
				listU[i].pop_back();
			}
			if (!listD[i].empty() )
			{
				int x = listD[i].back();
				mnR = min(mnR, as[a[i] ] - as[a[x] ] );
			}
			if (!listU[i].empty() )
			{
				int x = listU[i].back();
				mnR = min(mnR, as[a[x] ] - as[a[i] ] );
			}

			while (ptr != (int) qs.size() && r[qs[ptr] ] == i)
			{
				int id = qs[ptr++];

				int answ = min(mnR, slow[l[id] ] );
				for (int j = l[id]; j <= be; j++)
					answ = min(answ, val[j] );
				ans[id] = answ;
			}
		}
	}
}

int main(int,  char **)
{
#ifdef LOCAL
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[i] );
		as[i] = a[i];
	}
	sort(as, as + n);
	int k = unique(as, as + n) - as;
	for (int i = 0; i < n; i++)
		a[i] = lower_bound(as, as + k, a[i] ) - as;

//	for (int i = 0; i < k; i++)
//		eprintf("%d ", as[i] );
//	eprintf("\n");

	int m;
	scanf("%d", &m);
	for (int i = 0; i < m; i++)
	{
		scanf("%d%d", &l[i], &r[i] );
		l[i]--;
		r[i]--;
		if (r[i] / BL == l[i] / BL)
			qsmall[r[i] ].push_back(i);//ans[i] = solveSlow(l[i], r[i]);
		else
			qu[l[i] ].push_back(i);
	}
	init(n, k);
	solve(n, k);
	for (int i = 0; i < m; i++)
		printf("%d\n", ans[i] );

	return 0;
}