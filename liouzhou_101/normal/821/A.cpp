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

int n, a[55][55];

int main()
{
	
	cin >> n;
	for (int i = 1; i <= n; ++ i)
		for (int j = 1; j <= n; ++ j)
			cin >> a[i][j];
	
	for (int i = 1; i <= n; ++ i)
		for (int j = 1; j <= n; ++ j)
			if (a[i][j] != 1)
			{
				int flag = 0;
				for (int x = 1; x <= n; ++ x)
					for (int y = 1; y <= n; ++ y)
						if (a[i][x]+a[y][j]==a[i][j]) flag = 1;
				if (!flag)
				{
					puts("NO");
					return 0;
				}
			}
	puts("YES");
	
	return 0;
}