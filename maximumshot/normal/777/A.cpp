#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()

typedef pair< int, int > pii;
typedef long long ll;

int const inf = 1000 * 1000 * 1000;
ll const inf64 = 1ll * inf * inf;

int main() {

    int n, x;

    cin >> n >> x;

    n %= 6;

    vec< int > a = {0, 1, 2};

    for(int i = 1;i <= n;i++) {
        if(i % 2) {
            swap(a[0], a[1]);
        }else {
            swap(a[1], a[2]);
        }
    }

    cout << a[x] << "\n";

    return 0;
}