#include<bits/stdc++.h> 
#include<fstream>
using namespace std;
#define int long long
main () {
	int n, k;
	cin >> n >> k;
	string s;
	cin >> s;
	bool flag = true;
	for(int i = k; i < s.size(); i++)
	{
		if(s[i] > s[i % k])
		{
			flag = false;
			break;
		}
		if(s[i] < s[i % k])
		{
			break;
		}
	}
	if(flag)
	{
		cout << s.size() << "\n";
		for(int i = 0; i < s.size(); i++)
		{
			cout << s[i % k];
		}
	}
	else
	{
		string h = "";
		for(int i = k - 1; i >= 0; i--)
		{
			if(s[i] == '9')
			{
				s[i] = '0';
			}
			else
			{
				cout << s.size() << "\n";
				s[i]++;
				break;
			}
		}
		for(int i = 0; i <= k - 1; i++)
		{
			cout << s[i];
			h += s[i];
		}
		for(int i = k; i < s.size(); i++)
		{
			cout << h[i % k];
		}
	}
    return 0;
}