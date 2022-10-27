#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, s;
	cin >> n >> s;
	if(s < 2 * n)
	{
		cout << "NO";
		return 0;
	}
	vector <int> a(n);
	cout << "YES\n";
	for(int i = 0; i < n; i++)
	{
		if(i < n - 1)
		{
			a[i] = 2;
			s -= 2;
		}
		else
		{
			a[i] = s;
		}
		cout << a[i] << " ";
	}
	cout << "\n";
	cout << 1;
    return 0;
}