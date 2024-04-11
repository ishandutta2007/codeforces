#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

const int maxn = 5e3 + 20;

bool is[maxn][maxn];

int sum[maxn][maxn];

int main()
{
	string s;
	cin >> s;
	int n = s.size();

	for(int i = n - 1; i >= 0; i--)
		for(int j = i; j < n; j++)
		{
			if(i == j)
			{
				is[i][j] = 1;
				continue;
			}	
			if(s[i] == s[j] && (i + 1 == j || is[i + 1][j - 1]))
				is[i][j] = 1;
		}

	for(int i = n - 1; i >= 0; i--)
		for(int j = i; j < n; j++)
		{
			int tmp1 = 0 , tmp2 = 0;
			if(j)
				tmp1 = sum[i][j - 1] , tmp2 = sum[i + 1][j - 1];
			sum[i][j] = tmp1 + is[i][j] + sum[i + 1][j] - tmp2;
		}

	int q;
	scanf("%d", &q);
	while(q--)
	{
		int l , r;
		scanf("%d%d", &l, &r);
		l-- , r--;

		printf("%d\n", sum[l][r]);
	}
}