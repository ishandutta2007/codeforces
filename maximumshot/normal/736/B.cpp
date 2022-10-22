#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair< int, int > pii;
typedef long double ld;

int const inf = 1000 * 1000 * 1000;
ll const inf64 = 1ll * inf * inf;

bool prime(int n) {
    for(int i = 2;i * i <= n;i++) {
        if(n % i == 0) return 0;
    }
    return 1;
}

int main() {

    int n;
    cin >> n;

    if(prime(n)) {
        cout << "1\n";
    }else {
        int const MAX_VAL = 10000;
        for(int x = 2;n - x >= 2 && x <= MAX_VAL;x++) {
            if(prime(x) && prime(n - x)) {
                cout << "2\n";
                return 0;
            }
        }
        cout << "3\n";
    }

    return 0;
}