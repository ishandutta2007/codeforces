#include <bits/stdc++.h>
#define N 300000+5
using namespace std;
int a[N];
int main()
{
	int n;
	cin >> n;
	for(int i = 1; i <= n; i ++)cin >> a[i];
	sort(a + 1, a + n + 1);
	n = (n >> 1) + (n & 1);
	cout << a[n];
        return 0;
}