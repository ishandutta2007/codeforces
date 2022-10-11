#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	int n,m,i,ans=0;
	cin >> n >> m;
	pair <int,int> s[m];
	for (i=0;i<m;i++)
	cin >> s[i].second >> s[i].first;
	sort (s,s+m);
	for (i=m-1;i>=0 && n;i--)
	{
		ans+=min(s[i].second,n)*s[i].first;
		n-=min(s[i].second,n);
	}
	cout << ans;
}