#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

const int maxn = 1e2 + 20;

int a[maxn] , b[maxn] , t[maxn][maxn][maxn];

int main()
{
	int n , m;
	cin >> n >> m;
	
	for(int i = 0; i < n; i++)
	{
		cin >> a[i];
		a[i]--;
		t[i][i][a[i]] = 1;
	}

	for(int i = 0; i < m; i++)
		cin >> b[i];

	for(int len = 1; len <= n; len++)
		for(int l = 0; l + len <= n; l++)
		{
			int r = l + len - 1;

			if(len > 1)
				for(int k = 0; k < m; k++)
					t[l][r][k] = t[l][r - 1][k] + (a[r] == k);

			bool f = 1;
			for(int k = 0; k < m; k++)
				if(t[l][r][k] != b[k])
					f = 0;

			if(f)
				return cout << "YES" << endl , 0;
		}

	cout << "NO" << endl;
}