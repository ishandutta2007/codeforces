#include <iostream>
#include <vector>
using namespace std;
vector<int> v[105];
int main()
{
	int n,ans;
	cin >> n;
	ans=n-1;
	for (int i=1;i<n;i++)
	{
		v[i].push_back(i+1);
		for (int x=i+3;x<=n;x+=2)
		{
			v[i].push_back(x);
			ans++;
		}
	}
	cout << ans << endl;
	for (int i=1;i<=n;i++)
	{
		for (int x=0;x<v[i].size();x++)
		cout << i << ' ' << v[i][x] << endl;
	}
}