#include <bits/stdc++.h>
using namespace std;
int ans;
int main()
{
	int a, b, c;
	cin >> a >> b >> c;
	for(int i = a; i >= 1; i --)
		if(i * 2 <= b && i * 4 <= c) {ans = i * 7; break;}
	cout << ans;

	return 0; 
}