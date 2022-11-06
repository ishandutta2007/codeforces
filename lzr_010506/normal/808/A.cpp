#include <bits/stdc++.h>
using namespace std;
int n;
int main()
{
	cin >> n;
	if(n < 10) {cout << 1; return 0;}
	string s = to_string(n);
	int now = 0;
	for(int i = 1; i < s.size(); i ++) now = now * 10 + s[i] - '0';
	int mx = 1;
	for(int i = 1; i < s.size(); i ++) mx = mx * 10;
	cout << mx - now;
	return 0;
}