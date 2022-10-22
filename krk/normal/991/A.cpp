#include <bits/stdc++.h>
using namespace std;

int a, b, c, n;

int main()
{
	cin >> a >> b >> c >> n;
	if (a > n || b > n || c > a || c > b) printf("-1\n");
	else {
		int lft = n - a - b + c;
		if (lft <= 0) printf("-1\n");
		else printf("%d\n", lft);
	}
	return 0;
}