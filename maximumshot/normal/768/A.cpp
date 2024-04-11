#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()

typedef pair< int, int > pii;
typedef long long ll;

int const inf = 1000 * 1000 * 1000;
ll const inf64 = 1ll * inf * inf;

int main() {

    int n;
    cin >> n;

    vec< int > a(n);

    for(int i = 0;i < n;i++) cin >> a[i];

    sort(ALL(a));

    int res = 0;

    for(int i = 0;i < n;i++) {
        if(a[i] > a[0] && a[i] < a[n - 1]) {
            res++;
        }
    }

    cout << res << "\n";

    return 0;
}