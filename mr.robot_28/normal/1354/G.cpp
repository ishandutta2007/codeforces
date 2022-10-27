#include <bits/stdc++.h>
 
using namespace std;
int lst;

signed main()
{
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//	cout.tie(NULL);
	int t;
	cin >> t;
	lst = t;
	while(t--)
	{
		int n, k;
		cin >> n >> k;
		int ans = -1;
		mt19937 rnd(lst ^ (n * 1024 + k));
		for(int i = 0; i < 30; i++)
		{
			int cur = 1 + rnd() % (n - 1);
			cout << "? " << 1 << " " << 1 << endl;
			cout << 1 << endl;
			cout << cur + 1 << endl;
			fflush(stdout);
			string s;
			cin >> s;
			if(s == "SECOND")
			{
				ans = 1;
			}
		}
		if(ans == 1)
		{
			cout << "! " << ans << endl;
			fflush(stdout);
			continue;
		}
		int ind1 = 2;
		int t = 0;
		for(int j = 0; pow(2, j) * 2 <= n; j++)
		{
			cout << "? " << pow(2, j) << " " << pow(2, j) << endl;
			for(int i = 0; i < pow(2, j); i++)
			{
				cout << i + 1 << " ";
			}
			cout << endl;
			for(int i = 0; i < pow(2, j); i++)
			{
				cout << i + 1 + pow(2, j) << " ";
			}
			cout << endl;
			fflush(stdout);
			string s;
			cin >> s;
			if(s != "EQUAL")
			{
				t = j;
				break;
			}
			t = j + 1;
		}
		int l = pow(2, t) - 1,r = min(n, int(pow(2, t + 1))) - 1;
		while(r - l > 1)
		{
			int midd = (r + l) / 2;
			cout << "? " << midd - pow(2, t) + 1 << " " << midd - pow(2, t) +1  << endl;
			for(int i = pow(2, t); i <= midd; i++)
			{
				cout << i + 1 << " ";
			}
			cout << endl;
			for(int i = 0; i <= midd - pow(2, t); i++)
			{
				cout << i + 1 << " ";  
			}
			cout << endl;
			fflush(stdout);
			string s;
			cin >> s;
			if(s == "EQUAL")
			{
				l = midd;
			}
			else
			{
				r = midd;
			}
		}
		cout << "! " << r + 1 << endl;
		fflush(stdout);
	}
    return 0;
}