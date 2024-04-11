#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll n;

int main()
{
	cin >> n; n++;
	if (n == 1) cout << 0 << endl;
	else if (n % 2) cout << n << endl;
	else cout << n / 2 << endl;
	return 0;
}