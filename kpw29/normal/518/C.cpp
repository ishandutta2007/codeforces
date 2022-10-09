#include <bits/stdc++.h>
#define maxn 1000100
using namespace std;

int pozycje[maxn];
typedef long long ll;
int t[maxn];

int main()
{
	ll wyn =0;
	int n,R,zap;
	int a;
	scanf("%d%d%d", &n, &zap, &R);
	for (int i=1; i<=n; ++i) 
	{
		scanf("%d", &t[i]);
		pozycje[t[i]] = i;
	}
	while (zap--)
	{
		scanf("%d", &a);
		int poz = pozycje[a];
		wyn++;
		poz--;
		wyn += (poz / R);
		++poz;
		if (poz != 1)
		{
			swap(t[poz], t[poz-1]);
			pozycje[t[poz]] = poz;
			pozycje[t[poz-1]] = poz-1;
		} 
	}
	printf("%I64d", wyn);
}