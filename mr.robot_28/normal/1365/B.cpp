#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		vector <int> a(n), b(n);
		for(int i = 0; i < n; i++){
			cin >> a[i];
		}
		bool flag1 = true;
		bool flag2 = 0, flag3 = 0;
		for(int i = 0; i < n; i++){
			cin >> b[i];
			if(b[i] == 0)
			{
				flag2 = true;
			}
			if(b[i] == 1)
			{
				flag3 = true;
			}
		}
		for(int i = 0; i < n - 1; i++)
		{
			if(a[i + 1] < a[i])
			{
				flag1 = false;
			}
		}
		if((!flag2 || !flag3) && !flag1)
		{
			cout << "No\n";
		}
		else
		{
			cout << "Yes\n";
		}
    }
	return 0;
}