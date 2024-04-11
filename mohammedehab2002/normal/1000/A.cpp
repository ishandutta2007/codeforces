#include <iostream>
using namespace std;
string s[105];
bool used[105];
int main()
{
	int n;
	cin >> n;
	for (int i=0;i<n;i++)
	cin >> s[i];
	int ans=n;
	for (int i=0;i<n;i++)
	{
		string a;
		cin >> a;
		for (int x=0;x<n;x++)
		{
			if (used[x])
			continue;
			if (a==s[x])
			{
				used[x]=1;
				ans--;
				break;
			}
		}
	}
	cout << ans;
}