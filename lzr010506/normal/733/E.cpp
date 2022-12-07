#include <bits/stdc++.h>
#define pb push_back
#define FOR(i, x, y) for(int (i) = (x); (i) <= (y); (i) ++)
#define ll long long
using namespace std;
const int N = 1000005;
int n;
char ch[N];
int a[N], tl[N], tr[N];
ll res[N];

void Init()
{
	scanf("%d", &n);
	scanf("%s", ch + 1);
	FOR(i, 1, n) a[i] = a[i - 1] + (ch[i] == 'U');
}

void Work()
{
	FOR(i, 1, n)
	{
		int L = a[i - 1], R = n - i - (a[n] - a[i]);
		if (ch[i] == 'D')
			if (L <= R) res[i] += i, tl[i] = L, tr[i] = L;
			else res[i] += n + 1 - i, tl[i] = R + 1, tr[i] = R;
		else if (R <= L) res[i] += n + 1 - i, tl[i] = R, tr[i] = R; 
			 else res[i] += i, tl[i] = L, tr[i] = L + 1;
	}
	vector <ll> s; 
	s.pb(0);
	FOR(i, 1, n)
	{
		res[i] += 2ll * ((ll)(i) * tl[i] - (s.back() - s[s.size() - 1 - tl[i]]));
		if (ch[i] == 'U') s.pb(s.back() + i);
	}
	s.clear(); 
	s.pb(0);
	for (int i = n; i >= 1; i --) 
	{
		res[i] += 2ll * ((s.back() - s[s.size() - 1 - tr[i]]) - (ll)(i) * tr[i]);
		if (ch[i] == 'D') s.pb(s.back() + i);
	}
}

void Out()
{
	FOR(i, 1, n)
		printf("%I64d%c", res[i], i + 1 <= n? ' ': '\n');
}

int main()
{
	Init();
	Work();
	Out();
	return 0;
}