#include <iostream>

using namespace std;

double prob[2010][2010];

int main()
{
	int n, t;
	double p;
	cin >> n >> p >> t;

	prob[0][0] = 1;
	for (int i = 1; i <= t; ++i)
	{
		for (int j = 0; j <= n; ++j)
		{
			if (j == 0)
			{
				prob[i][j] = prob[i - 1][j] * (1 - p);
			}
			else if (j == n)
			{
				prob[i][j] = prob[i - 1][j - 1] * p + prob[i - 1][j];
			}
			else
			{
				prob[i][j] = prob[i - 1][j - 1] * p  + prob[i - 1][j] * (1 - p);
			}
			//cout << prob[i][j] << " ";
		}
		//cout << endl;
	}
	double ans = 0;
	for (int i = 0; i <= n; ++i)
	{
		ans += i * prob[t][i];
	}
	cout.precision(7);
	cout << fixed << ans << endl;
}