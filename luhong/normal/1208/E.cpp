#include <iostream>
#include <cstdio>
#define MN 1010000

typedef long long ll;

ll b[MN], s[MN];
int a[MN];
int q[MN], h = 0, t = -1;

int main()
{
	int n, w; scanf("%d%d", &n, &w);
	w += 2;
	for(int i = 1; i <= n; i++)
	{
		int l; scanf("%d", &l);
		for(int j = 2; j <= l + 1; j++) scanf("%d", &a[j]);
		a[1] = a[l + 2] = 0; l += 2;
		if(l * 2 >= w)
		{
			h = 0; t = -1;
			for(int j = 1; j <= w; j++)
			{
				if(j <= l)
				{
					while(h <= t && a[q[t]] < a[j]) t--;
					q[++t] = j;
				}
				if(w - j + 1 < l)
				{
					if(h <= t && q[h] == l - (w - j + 1)) h++;
				}
				b[j] += a[q[h]];
			}
		}
		else
		{
			int Max = 0;
			for(int j = 1; j <= l; j++) 
			{
				Max = std::max(Max, a[j]);
				b[j] += Max;
			}
			Max = 0;
			for(int j = w; j >= w - l + 1; j--)
			{
				Max = std::max(Max, a[l - (w - j)]);
				b[j] += Max;
			}
			s[l + 1] += Max; s[w - l + 1] -= Max;
		}
	}
	for(int i = 1; i <= w; i++)
	{
		s[i] += s[i - 1];
		b[i] += s[i];
		if(2 <= i && i <= w - 1) printf("%lld ", b[i]);
	}
}