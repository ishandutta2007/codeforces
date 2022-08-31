#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <cmath>
#include <string>
#include <cstring>
#include <ctime>
#include <cassert>
#include <queue>
#include <stack>
#include <bitset>
#define y1 y11
#define fs first
#define sc second
#define mp make_pair
#define pb push_back
#define mt make_tuple
#define NAME ""

using namespace std;
	
typedef long long ll;
typedef long double ld;

const ld PI = acos(-1.0);

const int MAXN = 200001;

int n, k;
int t[MAXN];
ll s[MAXN];
ld f[MAXN];
ld sp[MAXN];
ld s2[MAXN];
int st[MAXN], b[MAXN];
int stc;
const ld e = 1e-10;

inline ld g(int l, int r)
{
	return (sp[r] - sp[l]) - (ld)(s[l]) * (s2[r] - s2[l]);
}

inline int bt(int i1, int i2)
{
	ld vl = f[i2] - f[i1] - g(i1, i2);
	if (vl < e) return i2 + 1;
	ld nd = (vl / (ld)(s[i2] - s[i1]));
	return upper_bound(s2, s2 + n + 1, nd +s2[i2]) - s2;
}

int main()
{
	cin >> n >> k;
	s[0] = 0;
	for (int i = 0; i < n; i++) 
	{
		cin >> t[i];
		s[i + 1] = s[i] + t[i];
	}
	sp[0] = 0;
	ld cur = 0;
	for (int i = 0; i < n; i++)
	{
    	cur += t[i];
		sp[i + 1] = sp[i] + cur / (ld)t[i];
	}
	s2[0] = 0;
	for (int i = 0; i < n; i++)
	{
		s2[i + 1] = s2[i] + 1.0 / (ld)t[i];
	}
	f[0] = 0;
	for (int i = 1; i <= n; i++) f[i] = 1e+20;
	for (int iter = 0; iter < k; iter++)
	{
		stc = 0;
		b[0] = 1;
		for (int i = 0; i < n; i++)
		{
			int db = 1;
			while (stc > 0)
			{
				db = bt(st[stc - 1], i);
				if (db > b[stc - 1]) break;
				stc--;
			}
			b[stc] = db;
			st[stc++] = i;
		}
		b[stc] = n + 1;
		for (int i = stc - 1; i >= 0; i--)
		{
			for (int j = b[i]; j < b[i + 1]; j++)
			{
				f[j] = f[st[i]] + g(st[i], j);
			}
		}
	}
	cout.setf(ios::fixed);
	cout.precision(20);
	cout << f[n] << endl;
	return 0;
}