#include <bits/stdc++.h>
#define ll long long
#define ls rt << 1
#define rs rt << 1 | 1
#define mp make_pair
#define pb push_back
#define pii pair<int, int>
#define X first
#define Y second
#define db double
#define pcc pair<char, char>
#define rep(i, x, y) for((i) = (x); (i) <= (y); (i) ++)
using namespace std;
const int N = 60;
const int M = 21;
inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}
char s[N][M];
db f[1 << M];
ll tn[1 << M];
db js(ll x)
{
	return (db)__builtin_popcount(int(x % (1 << 21))) + __builtin_popcount(int(x / (1 << 21)));
}
int main()
{
	int i, j;
	int n = read();
	rep(i, 0, n - 1)
		scanf("%s", s[i]);
	if(n == 1)
	{
		cout << 0 << endl;
		return 0;
	}

	int l = strlen(s[0]);
	tn[0] = (1ll << n) - 1;
	rep(i, 0, n - 1)
		rep(j, i + 1, n - 1)
		{
			int sav = 0;
			for(int k = 0; k < l; k ++)
				if(s[i][k] == s[j][k]) sav |= (1 << k);
			tn[sav] |= (1LL << i) | (1LL << j);

            //cout << sav << ":" << tn [sav] << endl;
		}
    for(int mask = (1 << l) - 1; mask >= 0; mask --)
		rep(i, 0, l - 1)
			if((mask >> i) & 1)
				tn[mask ^ (1 << i)] |= tn[mask];
	for(int mask = (1 << l) - 1; mask >= 0; mask --)
	{
		if(!tn[mask]) continue;
		int tot = 0;
        rep(i, 0, l - 1)
            if(!(mask & (1 << i)))
                tot ++;
        f[mask] = 1.0;
        rep(i, 0, l - 1)
            if(!(mask & (1 << i)))
                f[mask] += f[mask | (1 << i)] / tot * js(tn[mask | (1 << i)]) / js(tn[mask]);
        //printf("%d %.12lf\n", mask, f[mask]);
	}
	printf("%.10lf", f[0]);

	return 0;
}