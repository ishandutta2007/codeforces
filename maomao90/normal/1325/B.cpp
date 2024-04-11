#include <iostream>
#include <bits/stdc++.h>
#include <cmath>
using namespace std;
int main()
{
	int t;
	cin >> t;
	while(t--)
	{
	int x,n;
	cin >> n;
	map <int,bool> mp;
	while(n--)
	{
		cin >> x;
		mp[x] = true;
}
cout << mp.size() << endl;
}
}