#include <iostream>
#include <vector>
using namespace std;
vector<vector<int> > ans;
int main()
{
	int n;
	cin >> n;
	while (n>4)
	{
		ans.push_back({n,n-1,n-2});
		ans.push_back({n,n-1,n-2});
		for (int i=1;i<n-2;i++)
		ans.push_back({i,n-1,(i+1)%(n-2)+(i+1==n-2),n});
		n-=2;
	}
	if (n==4)
	{
		ans.push_back({1,2,3});
		ans.push_back({1,2,4});
		ans.push_back({1,3,4});
		ans.push_back({2,3,4});
	}
	else if (n==3)
	{
		ans.push_back({1,2,3});
		ans.push_back({1,2,3});
	}
	else
	{
		cout << -1;
		return 0;
	}
	cout << ans.size() << endl;
	for (int i=0;i<ans.size();i++)
	{
		cout << ans[i].size() << ' ';
		for (int x=0;x<ans[i].size();x++)
		cout << ans[i][x] << ' ';
		cout << endl;
	}
}