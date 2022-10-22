#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()

typedef long long ll;
typedef long double ld;
typedef pair< int, int > pii;
typedef pair< long long, long long > pll;

int const inf = 1000 * 1000 * 1000;
ll const inf64 = 1ll * inf * inf;

char f(char x) {
    if(x == 'v') {
        return 0;
    }else if(x == '<') {
        return 1;
    }else if(x == '^') {
        return 2;
    }else if(x == '>') {
        return 3;
    }
}

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    char a, b;

    cin >> a >> b;

    a = f(a);
    b = f(b);

    int x, y, n;

    cin >> n;

    x = (a + n) % 4 == b;
    y = ((a - n) % 4 + 4) % 4 == b;

    if(x ^ y) {
        cout << (x ? "cw" : "ccw") << "\n";
    }else {
        cout << "undefined\n";
    }

    return 0;
}