#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const int maxn = 5e2 + 20;
int a[maxn];
bool dp[maxn][maxn];
int main()
{
	int n , k;
	cin >> n >> k;
	for(int i = 0; i < n; i++)
		cin >> a[i];
	dp[0][0] = 1;
	for(int i = 0; i < n; i++)
		for(int j = k; j >= -1; j--)
			for(int z = j; z >= -1; z--)
			{
				if(j >= a[i])
				{
					dp[j][z] |= dp[j - a[i]][z];
					if(z  >= a[i])
						dp[j][z] |= dp[j - a[i]][z - a[i]];
				}
			//	if(dp[j][z] && j == 4 && z == 2)
			//		cout << i + 1 << " ";
			}
	vector<int> res;
	for(int i = 0; i <= k; i++)
		if(dp[k][i])
			res.pb(i);
	cout << res.size() << endl;
	for(auto x : res)
		cout << x << " ";
}