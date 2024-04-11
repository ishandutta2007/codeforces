#include <bits/stdc++.h>
using namespace std;

#define FAST ios_base::sync_with_stdio(false); \
			 cin.tie(nullptr);                 \
	         cout.tie(nullptr)

vector<long long> data;

long long a, b, k, x, y, n, m, tmp, ans = 0;



long long gcd (long long a, long long b) {
	while (b) {
		a %= b;
		swap (a, b);
	}
	return a;
}

int main()
    {
    FAST;


    cin >> a >> b >> x >> y;

    data.resize(n);

    long long GCD = gcd(x, y);
    x/= GCD;
    y/= GCD;

    tmp = a/x;

    tmp = min (tmp, b/y);





    cout << tmp;

    return 0;
    }