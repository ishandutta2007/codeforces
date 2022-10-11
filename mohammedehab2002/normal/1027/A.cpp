#include <iostream>
using namespace std;
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		string s;
		cin >> n >> s;
		bool ok=1;
		for (int i=0;i<n/2;i++)
		{
			int tmp=abs(s[i]-s[n-i-1]);
			if (tmp && tmp!=2)
			ok=0;
		}
		printf(ok? "YES\n":"NO\n");
	}
}