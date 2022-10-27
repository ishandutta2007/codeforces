#include<bits/stdc++.h>
using namespace std;
#define X first
#define Y second
#define sz(a) (int)a.size()
#define ll long long
#define int long long
const int mod = 998244353;

signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int m, k;
	cin >> m >> k;
	vector <vector <int> > matrix(k, vector <int> (m));
	vector <int> sum(k), sum2(k);
	for(int i = 0; i < k; i++)
	{
		for(int j = 0; j < m; j++)
		{
			cin >> matrix[i][j];
			sum[i] += matrix[i][j];
			sum2[i] += matrix[i][j] * matrix[i][j];
		}
	}
	int sum_v_2 = 0;
	int y = -1;
	map <int, int> mp;
	for(int i = 1; i < k; i++)
	{
		int ds = (sum[i] - sum[0]);
		if(ds % i != 0)
		{
			y = i;
		}
		else
		{
			mp[ds/i]++;
		}
	}
	for(int i = 1; i < k; i++)
	{
		int ds = sum[i] - sum[0];
		if(ds % i == 0 && mp[ds / i] == 1)
		{
			y = i;
		}
	}
	if(y + 3 < k)
	{
		sum_v_2 = sum2[y + 1] + sum2[y + 3] - 2 * sum2[y + 2];
	}
	else
	{
		sum_v_2 = sum2[0] + sum2[2] - 2 * sum2[1];
	}
		int eval_sum = (sum[y - 1] + sum[y + 1]) / 2;
		int delta_sum = eval_sum - sum[y];
		int eval_sum_2 = (sum2[y - 1] + sum2[y + 1] - sum_v_2) / 2;
		for(int i = 0; i < m; i++)
		{
			int s1 = sum2[y] - matrix[y][i] * matrix[y][i];
			s1 += (matrix[y][i] + delta_sum) * (matrix[y][i] + delta_sum);
			if(s1 == eval_sum_2)
			{
				cout << y << " " << matrix[y][i] + delta_sum;
				return 0;
			}
		}
		cout << endl;
	return 0;
}