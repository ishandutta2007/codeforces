#include <iostream>
#include <algorithm>
#include <set>
#include <stdio.h>
#define INTMAX 922337203685477580LL
#define ll long
using namespace std;

int main() {
	ll n;
	cin >> n;
	if (n <= 3) {
		cout << "NO" << endl;
		return 0;
	}
	else if (n % 2 == 0) {
		cout << "YES" << endl;
		cout << "1 * 2 = 2" << endl;
		cout << "3 * 4 = 12" << endl;
		cout << "2 * 12 = 24" << endl;
		for (ll i = 6; i <= n; i+= 2) {
			printf("%ld - %ld = 1\n", i, i-1);
			printf("24 * 1 = 24\n");
		}
		return 0;
	}
	else if (n % 2 != 0) {
		cout << "YES" << endl;
		cout << "1 + 5 = 6" << endl;
		cout << "4 * 6 = 24" << endl;
		cout << "3 - 2 = 1" << endl;
		cout << "24 * 1 = 24" <<endl;
		for (ll i = 7; i <= n; i+= 2) {
			printf("%ld - %ld = 1\n", i, i-1);
			printf("24 * 1 = 24\n");
		}
		return 0;
	}
	return 0;
}