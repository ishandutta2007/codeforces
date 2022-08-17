#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza
#define MP make_pair
#define PB push_back

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 1, inf = 1000111222;

int c, m,  x;

bool check(int cnt) {
    int cc= c, mm = m, xx = x;
    if (cnt > cc || cnt > mm) {
        return false;
    }
    cc -= cnt;
    mm -= cnt;
    xx = xx + cc + mm;
    return xx >= cnt;
}

int main()
{
    //freopen("input.txt", "r", stdin);
    int q;
    cin >> q;
    while (q--) {
        cin >> c >> m >> x;
        if (c <= m && c <= x) {
            cout << c << "\n";
            continue;
        }
        if (m <= c && m <= x) {
            cout << m << "\n";
            continue;
        }
        int s = c + m + x;
        int l = 0, r = s + 2;
        while (l + 1 < r) {
            int mid = (l + r) / 2;
            if (check(mid)) {
                l = mid;
            } else {
                r = mid;
            }
        }
        cout << l << "\n";
    }

    return 0;
}