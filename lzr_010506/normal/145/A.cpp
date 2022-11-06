#include <bits/stdc++.h>
using namespace std;
int num[10];
int main()
{
	string a, b;
	cin >> a >> b;
	int n = a.size();
	for(int i = 0; i < n; i ++)
	{
		if(a[i] == b[i]) continue;
		num[a[i] - '0'] ++;
	}
	cout << max(num[4], num[7]);

	return 0;
}