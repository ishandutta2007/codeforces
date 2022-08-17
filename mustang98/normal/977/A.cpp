#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza
#define MP make_pair
#define PB push_back

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 1, inf = 1000111222;

int main()
{
    //freopen("input.txt", "r", stdin);
    ll n, k;
    cin >> n >> k;
    for (int i = 0; i < k; ++i) {
        if (n % 10 == 0) {
            n /= 10;
        } else {
            n--;
        }
    }
cout << n;
    return 0;
}