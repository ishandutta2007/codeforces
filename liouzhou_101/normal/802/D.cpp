#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<ld,ld> pdd;

#define X first
#define Y second

int a[333];

int main()
{
	
	int T;
	scanf("%d", &T);
	while (T --)
	{
		int n = 250;
		ld s = 0;
		ld t = 0;
		for (int i = 1; i <= n; ++ i)
		{
			scanf("%d", &a[i]);
			s += a[i];
			t += a[i]*a[i];
		}
		ld e = s/n;
		ld e2 = t/n;
		ld d = e2 - e*e;
		if (d/e >= 2)
			puts("uniform");
		else
			puts("poisson");
	}
	
	return 0;
}