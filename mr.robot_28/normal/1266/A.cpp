#include<bits/stdc++.h> 
#include<fstream>
using namespace std;
#define int long long

main () {
	int n;
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		string s;
		cin >> s;
		int cnt = 0;
		bool flag2 = false;
		int sum = 0;
		for(int j = 0;  j < s.size(); j++)
		{
			sum += (s[j] - '0');
			if((s[j] - '0') % 2 == 0)
			{
				cnt++;
			}
			if((s[j] - '0') == 0)
			{
				flag2 = true;
			}
		}
		if(cnt > 1 && flag2 && sum % 3 == 0)
		{
			cout << "red\n";
		}
		else
		{
			cout << "cyan\n";
		}
	}
    return 0;
}