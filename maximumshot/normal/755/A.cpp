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

int const MAX_VAL = 1000005;

bool prime[MAX_VAL];

int main() {

    for(int i = 2;i < MAX_VAL;i++) prime[i] = 1;

    for(int i = 2;i * i < MAX_VAL;i++) {
        if(!prime[i]) continue;
        for(int j = i * i;j < MAX_VAL;j += i) {
            prime[j] = 0;
        }
    }

    int n;
    cin >> n;

    for(int m = 1;m <= 1000;m++) {
        if(!prime[n * m + 1]) {
            cout << m << "\n";
            return 0;
        }
    }

    return 0;
}