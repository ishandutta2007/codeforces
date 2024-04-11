#include <bits/stdc++.h>
 
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	while(n--)
	{
		string a, b, c;
		cin >> a >> b >> c;
		bool flag = true;
		for(int i = 0; i < a.size(); i++)
		{
			if(a[i] != c[i] && b[i] != c[i])
			{
				flag = false;
			}
		}
		if(flag)
		{
			cout << "YES\n";
		}
		else
		{
			cout << "NO\n";
		}
	}
    return 0;
}