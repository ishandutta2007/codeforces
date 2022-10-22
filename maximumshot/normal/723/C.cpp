#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()
#define mp make_pair

typedef pair< int, int > pii;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int const inf = 1000 * 1000 * 1000;
ll const inf64 = 1ll * inf * inf;

int const N = 2005;

int n, m;
int a[N];
int b[N];

bool solve() {

    cin >> n >> m;

    for(int i = 0;i < n;i++) {
        cin >> a[i];
        a[i]--;
        if(a[i] < m) b[a[i]]++;
    }

    cout << n / m << ' ';

    int need = 0;
    for(int i = 0;i < m;i++) {
        if(b[i] < n / m) need += n / m - b[i];
    }

    cout << need << '\n';

    for(int j = 0;j < n && need;j++) {
        if(a[j] >= m) {
            a[j] = -1;
            need--;
        }
    }

    for(int j = 0;j < n && need;j++) {
        if(a[j] < m && b[a[j]] > n / m) {
            need--;
            b[a[j]]--;
            a[j] = -1;
        }
    }

    for(int i = 0;i < m;i++) {
        if(b[i] >= n / m) continue;
        int want = n / m - b[i];
        for(int j = 0;j < n && want;j++) {
            if(a[j] == -1) {
                a[j] = i;
                want--;
            }
        }
    }

    for(int i = 0;i < n;i++)
        cout << a[i] + 1 << ' ';
    cout << '\n';

    return true;
}

int main() {

#ifdef MY
    while(solve());
#else
    solve();
#endif

    return 0;
}