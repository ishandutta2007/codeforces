#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;
int main()
{
	int n,d,cnt=0,ans=0;
	cin >> n >> d;
	string s[d];
	for (int i=0;i<d;i++)
	cin >> s[i];
	for (int i=0;i<d;i++)
	{
		if (count(s[i].begin(),s[i].end(),'1')!=s[i].size())
		cnt++;
		else
		{
			ans=max(ans,cnt);
			cnt=0;
		}
	}
	ans=max(ans,cnt);
	cout << ans;
}