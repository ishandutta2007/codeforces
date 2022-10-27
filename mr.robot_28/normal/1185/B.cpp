#include<bits/stdc++.h> 

using namespace std; 
#define int long long
main() { 
	int n;
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		string s, s1;
		cin >> s >> s1;
		bool flag = true;
		int k = 0, k1 = 0;
		for(int j = 0; j < s.size(); j++)
		{
			if(j == 0 || s[j] != s[j - 1])
			{
				k++;
			}
		}
		for(int j = 0; j < s1.size(); j++)
		{
			if(j == 0 || s1[j] != s1[j - 1])
			{
				k1++;
			}
		}
		int j = 0, j1 = 0;
		while(j < s.size() && j1 < s1.size())
		{
			int cnt = 1, cnt1 = 1;
			while(j < s.size() -1 && s[j] == s[j + 1])
			{
				j++;
				cnt++;
			}
			while(j1 < s1.size() - 1 && s1[j1] == s1[j1 + 1])
			{
				j1++;
				cnt1++;
			}
			if(s[j] != s1[j1] || cnt1 < cnt)
			{
			//	cout << s[j] << " " << s1[j1] << endl;
			//	cout << cnt << "  " << cnt1 << endl;
				flag = false;
				break;
			}
			j++;
			j1++;
		}
		if(flag && k == k1)
		{
			cout << "YES" << endl;
		}
		else
		{
			cout << "NO" << endl;
		}
	}
	return 0;
}