#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()

typedef long long ll;
typedef unsigned int ui;
typedef pair< int, int > pii;
typedef pair< long long, long long > pll;

const int inf = 1e9;
const ll inf64 = 1ll * inf * inf;

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    int t;

    cin >> t;

    while(t--) {
        int n, k;
        cin >> n >> k;
        vec< int > res(n + 1, inf);
        for(int x, i = 0;i < k;i++) {
            cin >> x;
            for(int f, j = 1;j <= n;j++) {
                f = x + j - 1;

                if(1 <= f && f <= n) {
                    res[f] = min(res[f], j);
                }

                f = x - j + 1;

                if(1 <= f && f <= n) {
                    res[f] = min(res[f], j);
                }
            }
        }
        cout << *max_element(res.begin() + 1, res.end()) << "\n";
    }

    return 0;
}