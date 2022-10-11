#include <iostream>
#include <vector>
using namespace std;
int sum[100001];

int main()
{
	int n, k; cin >> n >> k;
	for (int i = 1; i <= n; ++i)
	{
		int a; cin >> a;
		sum[i] = sum[i - 1] + a;
	}
	if (sum[n] % k)
	{
		cout << "No";
		return 0;
	}
	int len = sum[n] / k, prv = 0;
	vector<int> ans;
	for (int i = 1; i <= n; ++i)
	{
		int diff = sum[i] - sum[prv];
		if (diff > len)
		{
			cout << "No";
			return 0;
		}
		else if (diff == len)
		{
			ans.push_back(i - prv);
			prv = i;
		}
	}
	if (prv == n)
	{
		cout << "Yes" << endl;
		for (int i : ans)
			cout << i << ' ';
	}
	return 0;
}