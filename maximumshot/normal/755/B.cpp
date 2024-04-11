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

    int n, m;

    cin >> n >> m;

    vec< string > a(n), b(m);

    for(int i = 0;i < n;i++) cin >> a[i];
    for(int i = 0;i < m;i++) cin >> b[i];

    sort(ALL(a));
    sort(ALL(b));

    int cnt = 0;

    for(int i = 0, j = 0;i < n && j < m;) {
        if(a[i] < b[j]) i++;
        else if(a[i] > b[j]) j++;
        else {
            cnt++;
            i++;
            j++;
        }
    }

    int x = n - cnt;
    int y = m - cnt;

    if(cnt % 2 == 0) {
        if(x > y) {
            cout << "YES\n";
        }else {
            cout << "NO";
        }
    }else {
        if(x >= y) {
            cout << "YES\n";
        }else {
            cout << "NO\n";
        }
    }

    return 0;
}