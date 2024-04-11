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
		for(int i = 0; i  < n; i++)
		{
			cin >> a[i];
		}
		for(int i = 0; i < n; i++)
		{
			cin >> b[i];
		}
		bool flag = true;
		multiset <pair <int, int> > s;
		for(int i = 0; i < n / 2; i++)
		{
			s.insert({b[i], b[n - i - 1]});
		}
		for(int i = 0; i < n / 2; i++)
		{
			if(s.find({a[i], a[n - i - 1]}) != s.end())
			{
				s.erase(s.find({a[i], a[n - i - 1]}));
			}
			else if(s.find({a[n - i - 1], a[i]}) != s.end())
			{
				s.erase(s.find({a[n - i - 1], a[i]}));
			}
			else
			{
				flag = false;
			}
		}
		if(n % 2 == 1 && a[n / 2] != b[n / 2])
		{
			flag = false;
		}
		if(flag)
		{
			cout << "Yes\n";
		}
		else{
			cout << "No\n";
		}
	}
	return 0;
}