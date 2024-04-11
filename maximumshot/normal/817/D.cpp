#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()

typedef long long ll;
typedef double ld;
typedef pair< int, int > pii;
typedef pair< ll, ll > pll;

int const inf = 1000 * 1000 * 1000;
ll const inf64 = 1ll * inf * inf;

int const N = 1e6 + 5;
int const LOG = 22;

int n;
int a[N];
vec< int > pos[N];
int _log[N];
int mn[LOG][N];
int mx[LOG][N];

void build() {
    _log[1] = 0;
    for(int i = 2;i < N;i++) {
        _log[i] = _log[i - 1];
        if((1 << (_log[i] + 1)) <= i) {
            _log[i]++;
        }
    }
    for(int i = 1;i <= n;i++) {
        mn[0][i] = mx[0][i] = a[i];
    }
    for(int j = 1;j < LOG;j++) {
        for(int i = 1;i + (1 << (j - 1)) <= n;i++) {
            mn[j][i] = min(mn[j - 1][i], mn[j - 1][i + (1 << (j - 1))]);
            mx[j][i] = max(mx[j - 1][i], mx[j - 1][i + (1 << (j - 1))]);
        }
    }
}

int getMin(int l, int r) {
    return min(
        mn[_log[r - l + 1]][l],
        mn[_log[r - l + 1]][r - (1 << _log[r - l + 1]) + 1]
    );
}

int getMax(int l, int r) {
    return max(
        mx[_log[r - l + 1]][l],
        mx[_log[r - l + 1]][r - (1 << _log[r - l + 1]) + 1]
    );
}

int main() {

#ifdef maximumSHOT
    freopen("input.txt", "r", stdin);
#endif

    scanf("%d", &n);

    for(int i = 1;i <= n;i++) {
        scanf("%d", &a[i]);
        pos[a[i]].push_back(i);
    }

    build();

    ll sumMin = 0;
    ll sumMax = 0;

    for(int i = 1;i <= n;i++) {
        int bl, br, bm;
        int L, R;

        bl = 1;
        br = i;

        while(br - bl > 1) {
            bm = (bl + br) / 2;
            if(getMin(bm, i) == a[i]) {
                br = bm;
            }else {
                bl = bm + 1;
            }
        }

        if(bl < br && getMin(bl, i) == a[i]) {
            L = bl;
        }else {
            L = br;
        }

        bl = i;
        br = n;

        while(br - bl > 1) {
            bm = (bl + br) / 2;
            if(getMin(i, bm) == a[i]) {
                bl = bm;
            }else {
                br = bm - 1;
            }
        }

        if(bl < br && getMin(i, br) == a[i]) {
            R = br;
        }else {
            R = bl;
        }

        int j = lower_bound(ALL(pos[a[i]]), L) - pos[a[i]].begin();
        if(pos[a[i]][j] == i) {
            sumMin += 1ll * a[i] * (i - L + 1) * (R - i + 1);
        }else {
            j = lower_bound(ALL(pos[a[i]]), i) - pos[a[i]].begin();
            j--;
            L = pos[a[i]][j] + 1;
            sumMin += 1ll * a[i] * (i - L + 1) * (R - i + 1);
        }
    }

    for(int i = 1;i <= n;i++) {
        int bl, br, bm;
        int L, R;

        bl = 1;
        br = i;

        while(br - bl > 1) {
            bm = (bl + br) / 2;
            if(getMax(bm, i) == a[i]) {
                br = bm;
            }else {
                bl = bm + 1;
            }
        }

        if(bl < br && getMax(bl, i) == a[i]) {
            L = bl;
        }else {
            L = br;
        }

        bl = i;
        br = n;

        while(br - bl > 1) {
            bm = (bl + br) / 2;
            if(getMax(i, bm) == a[i]) {
                bl = bm;
            }else {
                br = bm - 1;
            }
        }

        if(bl < br && getMax(i, br) == a[i]) {
            R = br;
        }else {
            R = bl;
        }

        int j = lower_bound(ALL(pos[a[i]]), L) - pos[a[i]].begin();
        if(pos[a[i]][j] == i) {
            sumMax += 1ll * a[i] * (i - L + 1) * (R - i + 1);
        }else {
            j = lower_bound(ALL(pos[a[i]]), i) - pos[a[i]].begin();
            j--;
            L = pos[a[i]][j] + 1;
            sumMax += 1ll * a[i] * (i - L + 1) * (R - i + 1);
        }
    }

    cout << sumMax - sumMin << "\n";

    return 0;
}