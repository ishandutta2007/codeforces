#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

const int maxn = 1e7 + 20;

bool check[maxn];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	ll res = 0;
	for(int j = 0; j <= n && j < 9; j++)
		for(int k = 0; j + k <= n && k < 9; k++)
		{
			if(j >= 5 && k)
				continue;
			res += (n - j - k + 1);
		}

	cout << res << endl;
}