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

int toUp(int u, int v) {
    if(v < 0) {
        v = -v;
        u = -u;
    }
    // x > u / v
    // x * v > u
    int x = u / v - 10;
    while(x * v <= u) x++;
    return x;
}

int toDown(int u, int v) {
    if(v < 0) {
        v = -v;
        u = -u;
    }
    // x <= u / v
    int x = u / v + 10;
    while(x * v > u) x--;
    return x;
}

int const N = 125;

int n;
int a[N][5];
int ac[5];

int get_score(int time, int type) {
    if(time == -1) return 0;
    int score = 500 * (type + 1);
    return score - score * time / 250;
}

bool check(int cnt) {
    int diff = 0;

    for(int task = 0;task < 5;task++) {
        int mx = -inf;
        for(int i = 0;i < 5;i++) {
            int ql, qr;
            ql = 0;
            qr = cnt;
            ql = max(
                ql,
                toUp(
                    n + cnt - (1 << (i + 1)) * ac[task],
                    1 << (i + 1)
                )
            );
            qr = min(
                qr,
                toDown(
                    n + cnt - (1 << i) * ac[task],
                    1 << i
                )
            );
            if(a[0][task] == -1) qr = min(qr, 0);
            if(ql <= qr) {
                mx = max(
                    mx,
                    get_score(a[0][task], i) - get_score(a[1][task], i)
                );
            }
        }
        {
            int ql, qr;
            ql = 0;
            qr = cnt;
            qr = min(
                qr,
                toDown(
                    n + cnt - 32 * ac[task],
                    32
                )
            );
            if(a[0][task] == -1) qr = min(qr, 0);
            if(ql <= qr) {
                mx = max(
                    mx,
                    get_score(a[0][task], 5) - get_score(a[1][task], 5)
                );
            }
        }
        diff += mx;
    }
    return diff > 0;
}

int main() {

#ifdef maximumSHOT
    freopen("input.txt", "r", stdin);
#endif

    cin >> n;

    for(int i = 0;i < n;i++) {
        for(int j = 0;j < 5;j++) {
            cin >> a[i][j];
            if(a[i][j] != -1) {
                ac[j]++;
            }
        }
    }

    for(int cnt = 0;cnt <= 100000;cnt++) {
        if(check(cnt)) {
            cout << cnt << "\n";
            return 0;
        }
    }

    cout << "-1\n";

    return 0;
}