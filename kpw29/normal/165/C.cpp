#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define maxn 1000100
int k, n;
char s[maxn];
int t[maxn];
int main()
{
	scanf("%d%s", &k, s + 1);
	n = 1;
	while (s[n]) ++n; --n;
	for (int i=1; i<=n; ++i) t[i] = s[i] - '0';
	if (k == 0)
	{
		long long w = 0, akt = 0;
		for (int i=1; i<=n; ++i)
		  if (!t[i]) {
			  ++akt;
			  w += akt;
		  }
		  else akt = 0;
		cout << w;
		exit(0);
	}
	
	int j = 1, sum = t[1];
	long long wyn = 0;
	t[0] = 100, t[n + 1] = 100100110;
	for (int i=1; i<=n; ++i)
	{
		while (j <= n+1 && sum <= k) 
		{
			if (sum >= k) break;
			++j;
			sum += t[j];
		}

		if (sum > k) break;
		int p = i - 1, kon = j + 1;
		if (t[i]) {
			while (!t[p]) --p; ++p;
			while (!t[kon]) ++kon; --kon;
		}
		if (sum == k && t[i]) wyn += (ll)(i - p + 1) * (ll)(kon - j + 1);
		sum -= t[i];
		//cout << wyn << endl;
	}
	cout << wyn;
}