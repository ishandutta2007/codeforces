#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <ios>
#include <tuple>

using namespace std;

#define A get<0>
#define B get<1>
#define C get<2>

typedef tuple<int, int, int> item;

const int maxn = 4005;
const int maxt = 10005;

int n, p, q;
item ar[maxn];
int fw[maxn][maxn], bk[maxn][maxn];

bool cmp(item a, item b) {
    return C(a) < C(b);
}

bool cmpl(item a, int x) {
    return C(a) < x;
}

int main() {
    ios_base::sync_with_stdio(0);
    
    cin >> n >> p;

    for (int i = 0; i < n; i++) cin >> A(ar[i]) >> B(ar[i]) >> C(ar[i]);
    
    sort(ar, ar + n, cmp);

    //for (int i = 0; i < n; i++) cout << A(ar[i]) << ' ' << B(ar[i]) << ' ' << C(ar[i]) << endl;

    for (int i = 0; i < n; i++) {
        if (i && C(ar[i - 1]) / p == C(ar[i]) / p) {
            for (int j = 0; j < maxn; j++)
                fw[i][j] = fw[i - 1][j];
        }

        for (int j = maxn - 1 - A(ar[i]); j >= 0; j--)
            fw[i][j + A(ar[i])] = max(fw[i][j + A(ar[i])], fw[i][j] + B(ar[i]));
    }

    for (int i = n - 1; i >= 0; i--) {
        if (i < n - 1 && C(ar[i + 1]) / p == C(ar[i]) / p) {
            for (int j = 0; j < maxn; j++)
                bk[i][j] = bk[i + 1][j];
        }

        for (int j = maxn - 1 - A(ar[i]); j >= 0; j--)
            bk[i][j + A(ar[i])] = max(bk[i][j + A(ar[i])], bk[i][j] + B(ar[i]));
    }

    cin >> q;
    for (int i = 0; i < q; i++) {
        int a, b;
        cin >> a >> b;

        int c = max(a - (p - 1), 0);

        int lo = lower_bound(ar, ar + n, c, cmpl) - ar;
        int hi = lower_bound(ar, ar + n, a + 1, cmpl) - ar - 1;

        if (lo > hi) cout << "0\n";
        else {
            int k = p * (a / p);
            int lt = C(ar[lo]), rt = C(ar[hi]);
            if (lt < k && rt >= k) {
                int best = 0;
                for (int j = 0; j <= b; j++)
                    best = max(best, bk[lo][j] + fw[hi][b - j]);
                cout << best << '\n';
            } else if (lt < k) cout << bk[lo][b] << '\n';
            else cout << fw[hi][b] << '\n';
        }
    }
}