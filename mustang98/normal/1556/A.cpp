#include <bits/stdc++.h>

#define F first
#define S second
#define MP make_pair
#define PB push_back

using namespace std;

typedef long long ll;
typedef long double ld;

const int max_n = -1, inf = 1000111222;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int t;
    cin >> t;
    while (t--) {
        int c, d;
        cin >> c >> d;
        if (c == d && d == 0) {
            puts("0");
        } else if (c == d) {
            puts("1");
        } else if ((c - d) % 2) {
            puts("-1");
        } else {
            puts("2");
        }
    }

    return 0;
}