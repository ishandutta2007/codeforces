#include <bits/stdc++.h>
#define ll long long
using namespace std;
char s[110];
ll a[110], f[110][110], r[110];
int main()
{
	for(int i = 0; i <= 100; i ++)
		for(int j = 0; j <= 100; j ++)
			f[i][j] = 1, f[i][j] <<= 60;
	int n,l;
	scanf("%d", &n);;
	scanf("%s", s);
	l = strlen(s);
	for(int i = 0; i < l; i ++)
		a[l - i] = s[i] - '0';
	a[0] = 0;
	f[0][0] = 0;
	r[1] = 1;
	for(int i = 2; i <= 60; i ++)
		r[i] = r[i - 1] * n;
	for(int i = 1; i <= l; i ++)
		for(int j = 1; j <= l; j ++)
		{
			if(r[j] < 0) break;
			int k = i;
			ll buf = a[i];
			while(buf < n && k)
			{
				ll ns = f[k - 1][j - 1] + r[j] * buf;
				if(ns >= 0 && ns < f[i][j]) f[i][j] = ns;
				if(a[i] == 0)break;
				k --;
				buf = buf * 10 + a[k];
			}
		}
	int j = 1;
	ll buf = 1;
	buf <<= 60;
	while(f[l][j] == buf) j ++;
	cout << f[l][j] << endl;
	return 0;
}