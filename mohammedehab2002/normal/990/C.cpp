#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<int> v[600005];
int main()
{
	int n;
	cin >> n;
	while (n--)
	{
		string s;
		cin >> s;
		int bal=0,mn=0;
		for (char i:s)
		{
			if (i=='(')
			bal++;
			else
			bal--;
			mn=min(mn,bal);
		}
		v[bal+300000].push_back(mn);
	}
	long long ans=0;
	for (int i=0;i<600005;i++)
	{
		sort(v[i].begin(),v[i].end());
		for (int x:v[i])
		{
			if (x<0)
			continue;
			int ind=lower_bound(v[600000-i].begin(),v[600000-i].end(),300000-i)-v[600000-i].begin();
			ans+=v[600000-i].size()-ind;
		}
	}
	cout << ans;
}