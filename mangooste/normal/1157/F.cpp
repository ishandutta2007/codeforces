#include <algorithm>
#include <array>
#include <cassert>
#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

template<typename A, typename B> ostream& operator<<(ostream &out, pair<A, B> p) { return out << '(' << p.first << ", " << p.second << ')'; }
template<typename A, typename B = typename enable_if<!is_same<A, string>::value, typename A::value_type>::type> ostream& operator<<(ostream &out, A v) { out << '{'; string sep; for (const B &x : v) out << sep << x, sep = ", "; return out << '}'; }

void dbgPrint() { cerr << endl; }
template<typename A, typename... B> void dbgPrint(A a, B... b) { cerr << ' ' << a; dbgPrint(b...); }

#ifdef LOCAL
#define dbg(...) cerr << "line #" << __LINE__ << " [" << #__VA_ARGS__ << "]:", dbgPrint(__VA_ARGS__)
#else
#define dbg(...)
#endif

#define sz(a) int(a.size())
#define all(a) (a).begin(), (a).end()

const int MAXN = 2'000'00 + 1;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    vector<int> cnt(MAXN, 0);
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        cnt[x]++;
    }

    vector<int> pref(MAXN + 1, 0);
    for (int i = 0; i < MAXN; i++) {
        pref[i + 1] = pref[i] + cnt[i];
    }
    auto getSum = [&](int l, int r) {
        return pref[r + 1] - pref[l];
    };

    vector<int> validUp(MAXN, -1);
    int cur = MAXN - 1;
    for (int i = MAXN - 1; i >= 0; i--) {
        if (cnt[i] < 2) {
            cur = i - 1;
        } else {
            validUp[i] = cur;
        }
    }

    vector<int> validDown(MAXN, -1);
    cur = 0;
    for (int i = 0; i < MAXN; i++) {
        if (cnt[i] < 2) {
            cur = i + 1;
        } else {
            validDown[i] = cur;
        }
    }

    int ans = 1;
    for (int i = 0; i < MAXN; i++) {
        ans = max(ans, cnt[i]);
        if (cnt[i] >= 2) {
            int up = validUp[i];
            int down = validDown[i];
            assert(up != -1 && down != -1);
            if (up != MAXN - 1 && cnt[up + 1] == 1) up++;
            if (down && cnt[down - 1] == 1) down--;
            ans = max(ans, getSum(down, up));
        }
        if (i == MAXN - 1) continue;
        if (cnt[i] == 1 && cnt[i + 1] == 1) ans = max(ans, 2);
    }

    assert(ans > 0);
    cout << ans << '\n';
    for (int i = 0; i < MAXN; i++) {
        if (ans == cnt[i]) {
            for (int j = 0; j < ans; j++) {
                cout << i << ' ';
            }
            cout << '\n';
            return 0;
        }

        if (cnt[i] >= 2) {
            int up = validUp[i];
            int down = validDown[i];
            if (up != MAXN - 1 && cnt[up + 1] == 1) up++;
            if (down && cnt[down - 1] == 1) down--;
            if (getSum(down, up) == ans) {
                for (int j = i; j >= down; j--) {
                    cout << j << ' ';
                }
                for (int j = down; j <= i; j++) {
                    while (--cnt[j]) cout << j << ' ';
                }
                for (int j = i + 1; j <= up; j++) {
                    cout << j << ' ';
                }
                for (int j = up; j > i; j--) {
                    while (--cnt[j]) cout << j << ' ';
                }
                cout << '\n';
                return 0;
            }
        }

        if (i == MAXN - 1) continue;
        if (cnt[i] == 1 && cnt[i + 1] == 1 && ans == 2) {
            cout << i << ' ' << i + 1 << '\n';
            return 0;
        }
    }
    assert(false);
}