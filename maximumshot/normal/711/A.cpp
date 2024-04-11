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

bool solve() {

    int n;
    cin >> n;

    vec< string > a(n);

    for(int i = 0;i < n;i++) {
        cin >> a[i];
    }

    int ok = 0;

    for(int i = 0;i < n;i++) {
        if(a[i][0] == 'O' && a[i][1] == 'O') {
            a[i][0] = a[i][1] = '+';
            ok = 1;
            break;
        }
        if(a[i][3] == 'O' && a[i][4] == 'O') {
            a[i][3] = a[i][4] = '+';
            ok = 1;
            break;
        }
    }

    if(ok) {
        cout << "YES\n";
        for (int i = 0; i < n; i++)
            cout << a[i] << '\n';
    }else {
        cout << "NO\n";
    }

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