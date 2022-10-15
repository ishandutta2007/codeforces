#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	if (n % 10 >= 5)
		n += 10 - n % 10;
	else
		n -= n % 10;
	cout << n;
	return 0;
}