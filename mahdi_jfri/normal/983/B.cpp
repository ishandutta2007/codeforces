#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

const int maxn = 5e3 + 20;

int a[maxn] , ans[maxn][maxn] , mx[maxn][maxn];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	for(int i = 0; i < n; i++)
		cin >> a[i];

	for(int i = n - 1; i >= 0; i--)
		for(int j = i; j < n; j++)
		{
			int len = j - i + 1;
			if(len == 1)
				ans[i][j] = a[i];
			else if(len == 2)
				ans[i][j] = a[i] ^ a[j];
			else
				ans[i][j] = (ans[i][j - 1] ^ ans[i + 1][j]);

			mx[i][j] = max(mx[i + 1][j] , mx[i][j - 1]);
			mx[i][j] = max(mx[i][j] , ans[i][j]);
		}


	int q;
	cin >> q;

	while(q--)
	{
		int l , r;
		cin >> l >> r;
		l-- , r--;
		
		cout << mx[l][r] << endl;
	}

}