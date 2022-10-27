
#include <bits/stdc++.h>
 
using namespace std;
#define int long long
main() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	int cnt1 = 0, cnt2 = 0;
	for(int i = 0; i < s.size(); i++)
	{
		if(s[i] == 'z')
		{
			cnt1++;
		}
		else if(s[i] == 'n')
		{
			cnt2++;
		}
	}
	while(cnt2 > 0)
	{
		cout << 1 << " ";
		cnt2--;
	}
	while(cnt1 > 0)
	{
		cout << 0 << " ";
		cnt1--;
	}
    return 0;
}