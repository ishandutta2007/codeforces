#include<bits/stdc++.h>
 
using namespace std;

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
		vector <int> a(n);
		int XOR = 0;
		for(int i = 0; i < n; i++)
		{
			cin >> a[i];
			XOR = XOR ^ a[i];
		}
		if(XOR == 0)
		{
			cout << "DRAW\n";
			continue;
		}
		int t1 = 0;
		for(int i = 0; i < 30; i++)
		{
			if((1 << i) & XOR)
			{
				t1 = i;
			}
		}
		int cnt0 = 0;
		for(int i = 0; i < n; i++)
		{
			if((a[i] & (1 << t1)) == 0)
			{
				cnt0++;
			}
		}
		int cnt1 = n - cnt0;
		cnt1 = (cnt1 + 1) / 2;
		if(cnt0 == 0)
		{
			if(cnt1 % 2 == 1)
			{
				cout << "WIN\n";
			}
			else
			{
				cout << "LOSE\n";
			}
		}
		else if(cnt0 % 2 == 0)
		{
			if(cnt1 % 2 == 1)
			{
				cout << "WIN\n";
			}
			else
			{
				cout << "LOSE\n";
			}
		}
		else
		{
			cout << "WIN\n";
		}
	}
	return 0;
}