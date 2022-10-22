#include <bits/stdc++.h>
//#include "optimization.h"

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()

typedef pair< int, int > pii;
typedef long long ll;

const int inf = 1e9;
ll const inf64 = 1ll * inf * inf;

void print(vec< int > a) {
    int n = (int)a.size() - 1;
    while(!a[n]) n--;
    cout << n << "\n";
    for(int i = 0;i <= n;i++) {
        cout << a[i] << " \n"[i == n];
    }
}

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    int n;

    cin >> n;

    vec< int > a(n + 1), b(n + 1);

    a[0] = 1;
    b[1] = 1;

    for(int i = 2;i <= n;i++) {
        vec< int > c(n + 1);
        for(int i = 1;i <= n;i++) {
            c[i] = b[i - 1];
        }
        for(int i = 0;i <= n;i++) {
            c[i] = (c[i] + a[i]) % 2;
        }
        a = b;
        b = c;
    }

    print(b);
    print(a);

    return 0;
}