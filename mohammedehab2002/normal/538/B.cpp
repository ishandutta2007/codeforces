#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector <int> v;
vector <int> dp[1000005];
void init(int i,int x)
{
	if (i<=1000000)
	v.push_back(i);
	else
	return;
	if (x<=1000000)
	v.push_back(x);
	else
	return;
	init(i*10,i*10+1);
	init(x*10,x*10+1);
}
int main()
{
	int n;
	cin >> n;
	v.push_back(1);
	init(10,11);
	dp[1].push_back(1);
	for (int i=2;i<=n;i++)
	{
		for (int x=0;x<v.size();x++)
		{
			if (i<v[x])
			continue;
			if (dp[i-v[x]].size()<dp[i].size()-1 || !dp[i].size())
			{
				dp[i]=dp[i-v[x]];
				dp[i].push_back(v[x]);
			}
		}
	}
	cout << dp[n].size() << endl;
	for (int i=0;i<dp[n].size();i++)
	cout << dp[n][i] << ' ';
}