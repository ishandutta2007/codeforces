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

    int n;

    cin >> n;

    vec< int > a(n), b(n);

    int ok = 1;

    for(int i = 0;i < n;i++) {
        cin >> a[i] >> b[i];
        if(a[i] != b[i]) {
            cout << "rated\n";
            return 0;
        }
        if(i > 0 && a[i] > a[i - 1]) {
            ok = 0;
        }
    }

    if(ok) {
        cout << "maybe\n";
    }else {
        cout << "unrated\n";
    }

    return 0;
}