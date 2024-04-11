#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

typedef long long ll;

ll n;

int main()
{
	cin >> n;
	if (n == 1 || n == 2) printf("-1\n");
	else {
		ll got = 1;
		while (n % 2 == 0) { got *= 2; n /= 2; }
		if (n == 1) {
			cout << got * got / 4 - 1 << " " << got * got / 4 + 1 << endl;
		} else {
			cout << (n * n - 1) / 2 * got << " " << (n * n + 1) / 2 * got << endl; 
		}
	}
	return 0;
}