#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <set>
#include <map>
#include <cmath>
using namespace std;

typedef long long int int64;

int64 gcd(int64 a, int64 b)
{
	if (b == 0)
		return a;
	return gcd(b, a % b);
}

struct Frac
{
	int64 up, down;
	Frac() : up(0), down(0) {}
	Frac(int64 _up, int64 _down) : up(_up), down(_down) {}

	bool operator < (Frac o) const
	{
		long double A = ( (long double) up * o.down);
		long double B = ( (long double) down * o.up);
		if (fabs(A - B) > 1e5)
			return A < B;
		long long Al = up * o.down;
		long long Bl = down * o.up;

		if (Al < 0 || Bl < 0)
		{
			Al += (long long) 1e9;
			Bl += (long long) 1e9;
		}

		return Al < Bl;
	}
};

struct Oper
{
	int ind, type;
	Frac coef;
	Oper() : ind(), type(), coef() {}
	Oper(int _ind, int _type, Frac _coef) : ind(_ind), type(_type), coef(_coef) {}
};

const int N = (int)3e5;

int k, n, m;
int64 start_val[N];
int t[N], ind[N], b[N];
int max_set[N];

bool cmp_by_b(Oper o1, Oper o2)
{
	return b[o1.ind] < b[o2.ind];
}

bool cmp_by_coef(Oper o1, Oper o2)
{
	return o1.coef < o2.coef;
}

bool cmp_by_type(Oper o1, Oper o2)
{
	return o1.type < o2.type;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif

	scanf("%d%d%d", &k, &n, &m);
	for (int i = 0; i < k; i++)
		scanf("%I64d", &start_val[i]);

	for (int i = 0; i < n; i++)
	{
		scanf("%d%d%d", &t[i], &ind[i], &b[i]);
		ind[i]--;
	}

	for (int i = 0; i < k; i++)
		max_set[i] = -1;

	for (int i = 0; i < n; i++)
	{
		if (t[i] == 1)
		{
			if (max_set[ind[i]] == -1 || b[max_set[ind[i]]] < b[i])
				max_set[ind[i]] = i;
		}
	}

	vector<Oper> list;
	for (int i = 0; i < n; i++)
	{
		if (t[i] == 1)
			continue;
		list.push_back(Oper(i, t[i], Frac()));
	}

	for (int i = 0; i < k; i++)
	{
		int cur = max_set[i];
		if (cur != -1 && start_val[ind[cur]] < b[cur])
		{
			b[cur] = b[cur] - start_val[ind[cur]];
			list.push_back(Oper(cur, 1, Frac()));
		}
	}

	sort(list.rbegin(), list.rend(), cmp_by_b);
	
	for (int i = 0; i < (int)list.size(); i++)
	{
		int cur = list[i].ind;
		if (list[i].type == 3)
		{
			list[i].coef = Frac(b[cur], 1);
			continue;
		}

		Frac f = Frac(start_val[ind[cur]] + b[cur], start_val[ind[cur]]);
		start_val[ind[cur]] += b[cur];
		list[i].coef = f;
	}

	sort(list.rbegin(), list.rend(), cmp_by_coef);
	
	list.resize(min((int)list.size(), m));

	sort(list.begin(), list.end(), cmp_by_type);

	printf("%d\n", (int)list.size());
	for (auto o : list)
		printf("%d ", o.ind + 1);

	return 0;
}