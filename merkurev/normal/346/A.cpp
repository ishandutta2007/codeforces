#include <iostream>
using namespace std;

int gcd(int a, int b)
{
	return b ? gcd(b, a % b) : a;
}

int a[1005];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n;
	scanf("%d", &n);

	int mx = 0, g = 0; 
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[i] );
		g = gcd(a[i], g);
		mx = max(a[i], mx);
	}

	int cnt = mx / g;
	cnt -= n;

	if (cnt % 2 == 0)
		printf("Bob");
	else
		printf("Alice");




	return 0;
}