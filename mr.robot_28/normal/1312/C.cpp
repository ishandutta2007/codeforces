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
		int n, k;
		cin >> n >> k;
		vector <int> a(n);
		bool flag = true;
		set <int> t;
		for(int i = 0; i < n; i++)
		{
			cin >> a[i];
			int cnt = 0;
			while(a[i] > 0){
				if(a[i] % k > 1)
				{
					flag = false;
					break;
				}
				if(a[i] % k == 1)
				{
					if(t.find(cnt) != t.end())
					{
						flag = false;
					}
					t.insert(cnt);
				}
				cnt++;
				a[i] = a[i] / k;
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