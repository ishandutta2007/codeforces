#include <iostream>

using namespace std;

typedef long long ll;

ll fib[100];

int main()
{
	ll a = 0, b = 1;
	for (int i = 0; i < 100; i++) {
		fib[i] = a;
		ll c = a + b;
		a = b;
		b = c;
	}

    ll n;
    cin >> n;
    int ans = 0;
    while (fib[ans + 1] <= n) ans++;
    // fib[ans + 1] > n
//    cerr << fib[ans] << " " << fib[ans + 1] << endl;
	cout << (ans - 2) << endl;
    return 0;
}