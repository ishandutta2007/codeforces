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

typedef unsigned long long ull;
typedef long long int int64;


struct Edge
{
	int from, to, cost;
	Edge() : from(), to(), cost() {}
	Edge(int _from, int _to, int _cost) : from(_from), to(_to), cost(_cost) {}

	void read()
	{
		scanf("%d%d%d", &from, &to, &cost);
		from--;
		to--;
	}
	bool operator < (const Edge &A) const
	{
		return cost < A.cost;
	}
};

const int maxn = 155;
Edge edge[maxn];
int N;

int bit(ull x, int y)
{
	return ( (x >> y) & 1ULL);
}

struct Matr
{
	ull row[maxn][3], col[maxn][3];

	Matr() : row(), col() {}

	Matr(int a[] ) : row(), col()
	{
		for (int i = 0; i < N; i++)
		{
			if (a[i] )
			{
				row[0][i >> 6] |= (1ULL << (i & 63) );
				col[i][0] |= 1;
			}
		}
	}

	void set(int i, int j)
	{
		row[i][j >> 6] |= (1ULL << (j & 63) );
		col[j][i >> 6] |= (1ULL << (i & 63) );
	}

	Matr operator * (const Matr &A) const
	{
		Matr ans = Matr();
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
			{
				 if ( (row[i][0] & A.col[j][0] ) | (row[i][1] & A.col[j][1] ) | (row[i][2] & A.col[j][2] ) )
				 {
					 ans.row[i][j >> 6] |= (1ULL << (j & 63) );
					 ans.col[j][i >> 6] |= (1ULL << (i & 63) );
				 }
			}
		return ans;
	}

	int get(int x, int y)
	{
		return bit(row[x][y >> 6], y & 63);
	}

	void eprint()
	{
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
				eprintf("%d ", get(i, j) );
			eprintf("\n");
		}
		eprintf("\n");
	}
};

Matr ONE()
{
	Matr ans = Matr();
	for (int i = 0; i < N; i++)
	{
		ans.row[i][i >> 6] |= (1ULL << (i & 63) );
		ans.col[i][i >> 6] |= (1ULL << (i & 63) );
	}
	return ans;
}

Matr fpow(Matr X, int n)
{
	Matr ans = ONE();
	Matr A = X;
	
	while (n)
	{
		if (n & 1)
			ans = ans * A;
		A = A * A;
		n >>= 1;
	}

//	eprintf("end fpow:\n");
//	ans.eprint();
	return ans;
}

int starr[maxn];

void solve()
{
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++)
	{
		edge[i].read();
	}
	N = n;
	sort(edge, edge + m);

	starr[0] = 1;
	Matr st = Matr(starr);
	Matr turn = Matr();
	Matr turnStay = ONE();


	if (edge[0].cost != 0)
	{
		printf("Impossible\n");
		return;
	}

//	st.eprint();
//	turn.eprint();

	int curT = 0;
	for (int i = 0; i < m; i++)
	{
		int nT;
		if (i == m - 1)
			nT = curT + 200;
		else
			nT = edge[i + 1].cost;


		turn.set(edge[i].from, edge[i].to);
		turnStay.set(edge[i].from, edge[i].to);
		
		Matr nx = st * fpow(turnStay, nT - curT);

//		eprintf("i = %d, curT = %d, nT = %d\n", i, curT, nT);
//		turn.eprint();
//		nx.eprint();
		
		if (nx.get(0, n - 1) )
		{
			int l = curT;
			int r = nT;

			while (r - l > 1)
			{
				int mid = (r + l) / 2;
				Matr M = st * fpow(turnStay, mid - curT);
				
//				eprintf("mid = %d\n", mid);
//				st.eprint();
//				M.eprint();

				if (M.get(0, n - 1) )
					r = mid;
				else
					l = mid;
			}

			printf("%d\n", r);
			return;
		}

		st = st * fpow(turn, nT - curT);
		curT = nT;
	}

	printf("Impossible\n");
}


int main(int , char **)
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
	solve();

	return 0;
}