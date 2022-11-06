#include <bits/stdc++.h>
using namespace std;
int a[11],n;
int main()
{
	cin >> n; 
	int Max = 0;
	for(int i = 1; i <= n; i ++) 
		cin >> a[i], Max = max(Max, a[i]);
	cout << (a[n] ^ Max) << endl;
	return 0;
}