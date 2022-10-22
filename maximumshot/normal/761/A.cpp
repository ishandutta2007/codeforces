#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()
#define mp make_pair
#define mt make_tuple

typedef pair< int, int > pii;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int const inf = 1000 * 1000 * 1000;
ll const inf64 = 1ll * inf * inf;

int main() {

    int a, b;

    cin >> a >> b;

    if(a + b > 0 && abs(a - b) <= 1) {
        cout << "YES\n";
    }else {
        cout << "NO\n";
    }

    return 0;
}