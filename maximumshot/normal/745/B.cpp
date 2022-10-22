#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()
#define mp make_pair
#define mt make_tuple

typedef pair< int, int > pii;
typedef long long ll;
typedef pair< ll, ll > pll;
typedef unsigned long long ull;
typedef long double ld;

int const inf = 1000 * 1000 * 1000;
ll const inf64 = 1ll * inf * inf;

int main() {

    int n, m;

    cin >> n >> m;

    int li = n;
    int ri = 0;
    int lj = m;
    int rj = 0;
    int cnt = 0;

    for(int i = 0;i < n;i++) {
        for(int j = 0;j < m;j++) {
            char c;
            cin >> c;
            if(c == 'X') {
                li = min(li, i);
                ri = max(ri, i);
                lj = min(lj, j);
                rj = max(rj, j);
                cnt++;
            }
        }
    }

    if((ri - li + 1) * (rj - lj + 1) == cnt) {
        cout << "YES\n";
    }else {
        cout << "NO\n";
    }

    return 0;
}