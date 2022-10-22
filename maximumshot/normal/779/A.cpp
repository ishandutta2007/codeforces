#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair< int, int > pii;

int const inf = 1000 * 1000 * 1000;
ll const inf64 = 1ll * inf * inf;

int n;
int a[6];
int b[6];

int main() {

    cin >> n;

    for(int x, i = 0;i < n;i++) cin >> x, a[x]++;
    for(int x, i = 0;i < n;i++) cin >> x, b[x]++;

    int res = 0;

    for(int i = 1;i <= 5;i++) {
        int d = abs(a[i] - b[i]);
        if(d % 2) {
            cout << "-1\n";
            return 0;
        }else {
            res += d / 2;
        }
    }

    cout << res / 2 << "\n";

    return 0;
}