#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair< int, int > pii;
typedef pair< ll, ll > pll;
typedef long double ld;

int const inf = 1000 * 1000 * 1000;
ll const inf64 = 1ll * inf * inf;

int main() {

    int n, m, k;

    cin >> n >> m >> k;

    for(int last = 0, i = 1;i <= n;i++) {
        // last + 1 .. last + 2 * m
        if(last + 1 <= k && k <= last + 2 * m) {
            cout << i << " ";
            char type = (k % 2 ? 'L' : 'R');
            k -= (last + 1);
            cout << k / 2 + 1 << " " << type << "\n";
            return 0;
        }
        last += 2 * m;
    }

    return 0;
}