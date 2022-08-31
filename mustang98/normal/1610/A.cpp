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
    //freopen("output.txt", "w", stdout);
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        if (n > m) {
            swap(n, m);
        }
        if (m == 1) {
            puts("0");
            continue;
        }
        if (n == 1) {
            puts("1");
            continue;
        }
        puts("2");
    }

    return 0;
}