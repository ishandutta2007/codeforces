#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int inf = 1e9;
const ll inf64 = 1e18;

int fast(int n, vector<int> p) {
    vector<int> l(n + 2), r(n + 2), L(n + 2), R(n + 2);

    for (int i = 1; i <= n; i++) {
        l[i] = L[i] = 1;
        if (p[i] > p[i - 1])
            l[i] = l[i - 1] + 1;
        else
            L[i] = L[i - 1] + 1;
    }

    for (int i = n; i >= 1; i--) {
        r[i] = R[i] = 1;
        if (p[i] > p[i + 1])
            r[i] = r[i + 1] + 1;
        else
            R[i] = R[i + 1] + 1;
    }

    vector<int> pref(n + 2), suff(n + 2);
    for (int i = 1; i <= n; i++)
        pref[i] = max({pref[i - 1], L[i], R[i]});
    for (int i = n; i >= 1; i--)
        suff[i] = max({suff[i + 1], L[i], R[i]});

    int res = 0;

    for (int x = 1; x <= n; x++) {
        int ql = x - l[x] + 1;
        int qr = x + r[x] - 1;
        int cur = max(l[x], r[x]);
        if (pref[ql - 1] >= cur)
            continue;
        if (suff[qr + 1] >= cur)
            continue;
        int lx = l[x];
        int rx = r[x];
        if (lx % 2 == 0 && max(L[x - lx + 1], lx - 1) >= r[x])
            continue;
        if (lx % 2 == 1 && L[x - lx + 1] >= max(l[x], r[x]))
            continue;
        if (rx % 2 == 0 && max(R[x + lx - 1], rx - 1) >= l[x])
            continue;
        if (rx % 2 == 1 && R[x + lx - 1] >= max(l[x], r[x]))
            continue;
        if (lx % 2) lx--;
        if (rx % 2) rx--;
        if (rx > 0 && rx >= l[x])
            continue;
        if (lx > 0 && lx >= r[x])
            continue;
//        cout << "x = " << x << "\n";
        res++;
    }
    return res;
}

int slow(int n, vector<int> p) {
    int res = 0;
    for (int x = 1; x <= n; x++) {
        int ok = 1;
        for (int y = 1; y <= n; y++) {
            if (x == y)
                continue;
            int goody = 1;
            for (int dx = -1; dx <= 1; dx += 2) {
                int win = 1;
                for (int dy = -1; dy <= 1; dy += 2) {
                    int turn = 0;
                    int cx = x;
                    int cy = y;
                    while (1) {
                        if (turn == 0) {
                            if (1 <= cx + dx && cx + dx <= n && cx + dx != cy && p[cx + dx] < p[cx]) {
                                cx += dx;
                                turn ^= 1;
                            } else {
                                break;
                            }
                        } else {
                            if (1 <= cy + dy && cy + dy <= n && cy + dy != cx && p[cy + dy] > p[cy]) {
                                cy += dy;
                                turn ^= 1;
                            } else {
                                break;
                            }
                        }
                    }
                    if (turn == 0) {
                        win = 0;
                        break;
                    }
                }
                if (win == 1) {
                    goody = 0;
                    break;
                }
            }
            if (goody) {
                ok = 0;
                break;
            }
        }
        if (ok)
            cout << "x = " << x << "\n";
        res += ok;
    }
    return res;
}

void work() {
    int n;
    cin >> n;
    vector<int> p(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
    }
    int fs = fast(n, p);
    cout << fs << "\n";
}

void test() {
    mt19937 rnd(42);
    const int N = 50;
    while (1) {
        int n = rnd() % N + 2;
        vector<int> p(n + 1);
        for (int i = 1; i <= n; i++)
            p[i] = i;
        shuffle(p.begin() + 1, p.end(), rnd);
        int fs = fast(n, p);
        int sl = slow(n, p);
        if (fs == sl) {
            cout << "OK(" << fs << ")" << endl;
        } else {
            cout << "WA\n";
            cout << "exp = " << sl << "\n";
            cout << "fnd = " << fs << "\n";
            cout << n << "\n";
            for (int i = 1; i <= n; i++)
                cout << p[i] << " ";
            cout << "\n";
            break;
        }
    }
}

int main() {

#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    work();
//    test();

    return 0;
}