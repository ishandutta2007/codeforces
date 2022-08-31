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
    int T;
    cin >> T;
    while(T--) {
        ll n, a ,b;
        cin >> n >> a >> b;
        if (2 * a <= b) {
            cout << n * a << endl;
        } else {
            cout << (n / 2 * b + a * (n % 2)) << endl;
        }
    }

    return 0;
}