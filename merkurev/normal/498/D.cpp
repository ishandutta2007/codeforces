#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;



const int ST = 18;
const int LEVEL = (1 << ST);
const int SIZE = (LEVEL << 1);

struct Tree
{
	int val[SIZE][60];
	void upd(int v)
	{
		int ch1 = 2 * v;
		int ch2 = 2 * v + 1;

		for (int i = 0; i < 60; i++)
		{
			int ni = (i + val[ch1][i] ) % 60; 
			val[v][i] = val[ch1][i] + val[ch2][ni];
		}
	}
	void init(int a[], int n)
	{
		for (int i = 0; i < 60; i++)
		{
			for (int v = 0; v < n; v++)
			{
				if (i % a[v] == 0)
					val[LEVEL + v][i] = 2;
				else
					val[LEVEL + v][i] = 1;
			}
		}
		for (int i = LEVEL - 1; i >= 1; i--)
		{
			upd(i);
		}
	}
	int getAns(int v, int l, int r, int tl, int tr, int ct)
	{
		if (tr <= l || tl >= r)
			return 0;
		if (l <= tl && tr <= r)
		{
			return val[v][ct % 60];
		}
		int tm = (tl + tr) / 2;
		int ans1 = getAns(2 * v, l, r, tl, tm, ct);
		int ans2 = getAns(2 * v + 1, l, r, tm, tr, ct + ans1);
		return ans1 + ans2;
	}
	void setVal(int pos, int x)
	{
		for (int i = 0; i < 60; i++)
		{
			if (i % x == 0)
				val[LEVEL + pos][i] = 2;
			else
				val[LEVEL + pos][i] = 1;
		}
		int v = pos + LEVEL;
		v /= 2;
		while (v)
		{
			upd(v);
			v /= 2;
		}
	}
};


int a[LEVEL];
Tree tf;

int getAns(int x, int y)
{
	return tf.getAns(1, x, y, 0, LEVEL, 0);
}
void setVal(int x, int val)
{
	tf.setVal(x, val);
}

int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[i] );
	}
	tf.init(a, n);

	int q;
	scanf("%d", &q);
	for (int i = 0; i < q; i++)
	{
		int x, y;
		char s[2];
		scanf("%s%d%d", s, &x, &y);
		if (s[0] == 'A')
		{
			x--;
			y--;
			int ans = getAns(x, y);
			printf("%d\n", ans);
		}
		else
		{
			x--;
			setVal(x, y);
		}
	}


	return 0;
}