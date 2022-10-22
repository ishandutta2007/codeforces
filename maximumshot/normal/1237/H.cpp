#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;
typedef long double ld;

const int inf = 1e9;
const ll inf64 = 1e18;


int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int tt;
    cin >> tt;

    mt19937 rnd(time(NULL));

    while (tt--) {
        string sa, sb;
        int n;
        cin >> sa >> sb;
        n = (int) sa.size();

//        n = 6;
//        sa.resize(n, '?');
//        for (int i = 0; i < n; i++) sa[i] = rnd() % 2 + '0';
//        sb = sa;
//
//        for (int j = 0; j <= n; j++) {
//            int cnt = (rnd() % (n / 2) + 1) * 2;
//            reverse(sa.begin(), sa.begin() + cnt);
//        }
//
//        cout << sa << " " << sb << "\n";

        vector<int> a(n), b(n);
        for (int i = 0; i < n; i++) {
            a[i] = sa[i] - '0';
            b[i] = sb[i] - '0';
        }
        vector<vector<int>> need(2, vector<int>(2)), have = need, cur = need;
        for (int i = 0; i < n; i += 2) {
            need[b[i]][b[i + 1]]++;
            have[a[i]][a[i + 1]]++;
        }
        if (need[0][0] != have[0][0] || need[1][1] != have[1][1]) {
            cout << "-1\n";
            continue;
        }
        vector<int> res;
        int any = 0;
        auto do_op = [&](int cnt) {
            if (cnt <= 0) return;
            reverse(a.begin(), a.begin() + cnt);
            res.push_back(cnt);
        };
        int do_rev = -1;
        if (have[0][1] != need[1][0] || have[1][0] != need[0][1]) {
            for (int i = 0; i < n; i += 2) {
                cur[b[i]][b[i + 1]]++;
                vector<vector<int>> tmp(2, vector<int>(2));
                for (int x = 0; x < 2; x++) {
                    for (int y = 0; y < 2; y++) {
                        tmp[x][y] = cur[y][x] + need[x][y] - cur[x][y];
                    }
                }
                if (tmp[0][0] == have[0][0] && tmp[1][1] == have[1][1] && tmp[0][1] == have[1][0] && tmp[1][0] == have[0][1]) {
                    any = 1;
                    do_rev = i + 2;
                    reverse(b.begin(), b.begin() + i + 2);
                    break;
                }
            }
            if (!any) {
                cur.assign(2, vector<int>(2, 0));
                for (int i = 0; i < n; i += 2) {
                    cur[a[i]][a[i + 1]]++;
                    vector<vector<int>> tmp(2, vector<int>(2));
                    for (int x = 0; x < 2; x++) {
                        for (int y = 0; y < 2; y++) {
                            tmp[x][y] = cur[y][x] + have[x][y] - cur[x][y];
                        }
                    }
                    if (tmp[0][0] == need[0][0] && tmp[1][1] == need[1][1] && tmp[0][1] == need[1][0] && tmp[1][0] == need[0][1]) {
                        any = 1;
                        do_op(i + 2);
                        break;
                    }
                }
                if (!any) {
                    cout << "-1\n";
                    continue;
                }
            }
        }
//        cout << "do = " << do_rev << " : b = "; for (int x : b) cout << x; cout << "\n";
        int ok = 1;
        for (int i = n - 2; i >= 0; i -= 2) {
            any = 0;
            for (int j = n - 2; j >= 0; j -= 2) {
                if (a[j + 1] == b[i] && a[j] == b[i + 1]) {
                    do_op(j);
                    do_op(j + 2);
                    any = 1;
                    break;
                }
            }
            if (!any) {
                ok = 0;
                break;
            }
        }
        if (!ok) {
            cout << "-1\n";
            continue;
        }
        do_op(do_rev);
        cout << (int) res.size() << "\n";
        for (int cnt : res) {
            cout << cnt << " ";
        }
        cout << "\n";
//        for (int xa : a) cout << xa; cout << " == "; for (int xb : b) cout << xb; cout << "\n";
    }

    return 0;
}