#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//	cout.tie(NULL);
	int n;
	cin >> n;
	vector <int> a1(n);
	vector <int> a(n), b(n);
	for(int i = 0; i < n; i++)
	{
		cin >> a[i];
		a1[i] = a[i];
	}
	sort(a1.begin(), a1.end());
	for(int i = 0; i < n; i++)
	{
		cin >> b[i];
	}
	vector <int> ans;
	int cnt = 0;
	int allcnt = 0;
	if(n == 2)
	{
		while(true){
			bool fl1 = true, fl2 = true, fl3 = true;
			for(int i = 0; i < n; i++)
			{
				if(a[i] != b[i])
				{
					fl3 = false;
				}
				if(i < n - 1 && b[i + 1] <= b[i])
				{	
					fl2 = false;
				}
				if(i < n - 1 && b[i + 1] >= b[i])
				{
					fl1 = false;
				}
			}	
			if(fl3)
			{
				break;
			}
			fl3 = true;
			for(int i = 0; i < n; i++)
			{
				if(a[i] != b[n - i - 1])
				{
					fl3 = false;
				}	
			}
			if(fl3)
			{	
				allcnt++;
				ans.push_back(1);
				break;
			}
			if(fl1){
				allcnt++;
				reverse(b.begin(), b.end());
				if(cnt <= 2e5)
				{
					ans.push_back(1);
				}
			}	
			fl3 = true;
			for(int i = 0; i < n; i++)
			{
				if(a[i] != b[i])
				{
					fl3 =false;
				}
			}
			if(fl3)
			{
				break;
			}
			fl3 = true;
			for(int i = 0; i < n; i++)
			{
				if(a1[i] > b[i])
				{
					cout << "IMPOSSIBLE";
					return 0;
				}
				if(a[i] != b[n - i - 1])
				{
					fl3 = false;
				}
			}
			if(fl3)
			{
				allcnt++;
				ans.push_back(1);
				break;
			}
			int r;
			b[1] -= (r = (b[1] - max(b[0], a1[1] + 1) + b[0]) / b[0]) * b[0];
			allcnt += r;
			while(cnt <= 2e5 && r > 0)
			{
				ans.push_back(2);
				cnt++;
				r--;
			}	
			cnt += r;
		}
	}
	else
	{
	while(true)
	{
		bool fl1 = true, fl2 = true, fl3 = true;
		for(int i = 0; i < n; i++)
		{
			if(a[i] != b[i])
			{
				fl3 = false;
			}
			if(i < n - 1 && b[i + 1] <= b[i])
			{
				fl2 = false;
			}
			if(i < n - 1 && b[i + 1] >= b[i])
			{
				fl1 = false;
			}
		}
		if(fl3)
		{
			break;
		}
		fl3 = true;
		for(int i = 0; i < n; i++)
		{
			if(a[i] != b[n - i - 1])
			{
				fl3 = false;
			}
		}
		if(fl3)
		{
			allcnt++;
			ans.push_back(1);
			break;
		}
		if(!fl1 && !fl2)
		{
			cout << "IMPOSSIBLE";
				return 0;
		}
		if(fl1){
			allcnt++;
			reverse(b.begin(), b.end());
			if(cnt <= 2e5)
			{
				ans.push_back(1);
			}
		}
		fl3 = true;
		for(int i = 0; i < n; i++)
		{
			if(a1[i] > b[i])
			{
				cout << "IMPOSSIBLE";
				return 0;
			}
			if(a[i] != b[i])
			{
				fl3 =false;
			}
		}
		if(fl3)
		{
			break;
		}
		fl3 = true;
		for(int i = 0; i < n; i++)
		{
			if(a[i] != b[n - i - 1])
			{
				fl3 = false;
			}
		}
		if(fl3)
		{
			allcnt++;
			ans.push_back(1);
			break;
		}
		for(int i = n -1 ; i > 0; i--)
		{
			b[i] = b[i] - b[i - 1];
		}
		allcnt++;
		cnt++;
		if(cnt <= 2e5)
		{
			ans.push_back(2);
		}
		if(n == 1)
		{
			cout << "IMPOSSIBLE";
			return 0;
		}
	}
	}
	if(cnt > 2e5)
	{
		cout << "BIG\n";
		cout << cnt;
	}
	else
	{
		reverse(ans.begin(), ans.end());
		cout << "SMALL\n";
		cout << allcnt << "\n";
		for(int i = 0; i < ans.size(); i++)
		{
			if(ans[i] == 1){
				cout << "R";
			}
			else
			{
				cout << "P";
			}
		}
	}
    return 0;
}