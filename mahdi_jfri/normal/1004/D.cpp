#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

const int maxm = 1e6 + 20;

int t[maxm] , tmp[maxm];

int main()
{
	int n;
	scanf("%d", &n);

	int mx = 0;
	for(int i = 0; i < n; i++)
	{
		int x;
		scanf("%d", &x);
		t[x]++;

		mx = max(mx , x);
	}

	if(t[0] != 1)
		return cout << -1 << endl , 0;

	for(int i = 1; i * i <= n; i++)
		if(n % i == 0)
		{
			int m = i , k = n / i;

			for(int j = 0; j < m; j++)
			{
				int x = j , y = mx - j;

				if(max(m - x - 1 , x) + max(y , k - y - 1) > mx || y >= k)
					continue;

				memset(tmp , 0 , sizeof tmp);

				for(int l = 0; l < m; l++)
				{
					int tm = abs(l - x);
					tmp[tm]++;
					tmp[tm + k - y]--;

					tmp[tm]++;
					tmp[tm + y + 1]--;

					tmp[tm]--;
					tmp[tm + 1]++;
				}

				bool f = 1;
				for(int l = 0; l < m + k; l++)
				{
					if(l)
						tmp[l] += tmp[l - 1];

					if(tmp[l] != t[l])
					{
						f = 0;
						break;
					}
				}

				fill(tmp , tmp + m + k , 0);

				if(f)
				{
					cout << m << " " << k << endl;
					cout << x + 1 << " " << y + 1 << endl;
					return 0;
				}
			}
		}

	cout << -1 << endl;
}