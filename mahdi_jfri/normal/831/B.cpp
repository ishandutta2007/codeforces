#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const int maxn = 1e5 + 20;
map<char , char> mp;
int main()
{
	string a , b , s;
	cin >> a >> b >> s;
	for(int i = 0; i < b.size(); i++)
		mp[a[i]] = b[i] , mp[a[i] - 'a' + 'A'] = b[i] - 'a' + 'A' ;
	for(int i = 0; i < s.size(); i++)
	{
		if(s[i] >= '0' && s[i] <= '9')
			cout << s[i];
		else
			cout << mp[s[i]];
	}
}