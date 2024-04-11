#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	int n,i,ans[]={0,0,0},a=0;
	cin >> n;
	pair <int,int> s[3];
	for (i=0;i<3;i++)
	{
		cin >> s[i].first >> s[i].second;
		a+=s[i].first;
		ans[i]=s[i].first;
	}
	for (i=0;i<3 && a!=n;i++)
	{
		ans[i]+=min(s[i].second-s[i].first,n-a);
		a+=min(s[i].second-s[i].first,n-a);
	}
	cout << ans[0] << " " << ans[1] << " " << ans[2];
}