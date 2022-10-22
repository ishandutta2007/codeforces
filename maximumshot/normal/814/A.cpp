#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()

typedef long long ll;
typedef long double ld;
typedef pair< int, int > pii;
typedef pair< ll, ll > pll;

int const inf = 1000 * 1000 * 1000;
ll const inf64 = 1ll * inf * inf;

int main() {

#ifdef maximumSHOT
    freopen("input.txt", "r", stdin);
#endif

    int n, k;

    cin >> n >> k;

    vec< int > a(n);

    for(int i = 0;i < n;i++) {
        cin >> a[i];
    }

    vec< int > b(k);

    for(int i = 0;i < k;i++) cin >> b[i];

    sort(b.rbegin(), b.rend());

    for(int i = 0, j = 0;j < k;j++) {
        while(i < n && a[i]) i++;
        a[i] = b[j];
    }

    int ok = 1;

    for(int i = 1;i < n;i++) {
        if(a[i] <= a[i - 1]) {
            ok = 0;
            break;
        }
    }

    if(ok) {
        puts("No");
    }else {
        puts("Yes");
    }

    return 0;
}