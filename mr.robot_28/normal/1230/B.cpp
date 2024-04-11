#include <bits/stdc++.h>
using namespace std;
int main() {
	int n, k;
	cin >> n >> k;
	string s;
	cin >> s;
	if(s.size() == 1 && s[0] > '0' && k > 0)
	{
		s[0] = '0';
		k--;
	}
	else if(s[0] > '1' && k > 0)
	{
		s[0] = '1';
		k--;
	}
	for(int i = 1; i < s.size(); i++)
	{
		if(s[i] > '0' && k > 0)
		{
			s[i] = '0';
			k--;
		}
		if(k == 0)
		{
			break;
		}
	}
	cout << s;
    return 0;
}