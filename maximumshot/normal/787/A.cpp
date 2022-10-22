#include <bits/stdc++.h>

using namespace std;

#define ALL(x) (x).begin(), (x).end()
#define vec vector

typedef pair< int, int > pii;
typedef long long ll;

int const inf = 1000 * 1000 * 1000;
ll const inf64 = 1ll * inf * inf;

int main() {

    int a, b;
    cin >> a >> b;

    int c, d;
    cin >> c >> d;

    for(int t1 = 0;t1 <= 1000000;t1++) {
        if((b + t1 * a - d) >= 0 && (b + t1 * a - d) % c == 0) {
            cout << b + t1 * a << "\n";
            return 0;
        }
    }

    cout << "-1\n";

    return 0;
}