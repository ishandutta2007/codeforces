#include<bits/stdc++.h> 
using namespace std;
int main () { 
	int n;
	cin >> n;
	string s;
	cin >> s;
	int cnt1 = 0, cnt2 = 0;
	for(int i = 0; i < n; i++)
	{
		if(s[i] == '0')
		{
			cnt1++;
		}
		else
		{
			cnt2++;
		}
	}
	if(cnt1 == cnt2)
	{
		cout << 2 << endl;
		cout << s[0] << " ";
		for(int i = 1; i < n; i++)
		{
			cout << s[i];
		}
	}
	else
	{
		cout << 1 << endl;
		cout << s;
	}
	return 0;
}