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
        ll a;
        cin >> a;
        ll all = 0;
        ll c2 = 0;
        while(a % 2 == 0) {
            a /= 2;
            ++c2;
        }
        while (a % 3 == 0) {
            a /= 3;
            ++all;
            ++c2;
        }
        while (a % 5 == 0) {
            a /= 5;
            ++all;
            c2 += 2;
        }
        if (a != 1) {
            cout << -1 << endl;
        } else {
            cout << all + c2 << endl;
        }
    }

    return 0;
}