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

    int n, k;

    cin >> n >> k;

    int time = 4 * 60 - k;
    int res = 0;

    for(int i = 1;i <= n;i++) {
        if(5 * i <= time) {
            time -= 5 * i;
            res++;
        }else {
            break;
        }
    }

    cout << res << "\n";

    return 0;
}