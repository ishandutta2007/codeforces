#pragma GCC optimize(2)
#pragma GCC optimize(3)
#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = a; i >= b; i--)
using namespace std;

typedef unsigned long long ull;
typedef pair <int, int> pii;
typedef long long ll;

template <typename _T>
inline void read(_T &f) {
    f = 0; _T fu = 1; char c = getchar();
    while (c < '0' || c > '9') { if (c == '-') { fu = -1; } c = getchar(); }
    while (c >= '0' && c <= '9') { f = (f << 3) + (f << 1) + (c & 15); c = getchar(); }
    f *= fu;
}

template <typename T>
void print(T x) {
    if (x < 0) putchar('-'), x = -x;
    if (x < 10) putchar(x + 48);
    else print(x / 10), putchar(x % 10 + 48);
}

template <typename T>
void print(T x, char t) {
    print(x); putchar(t);
}

const int N = 2e5 + 5;

struct ele {
    ll x, cnt;
    ele (ll a = 0, ll b = 0) : x(a), cnt(b) {}
    bool operator < (const ele A) const { return x < A.x; }
};

// set <ele> wxw;
// set <ele> :: iterator it;
deque <ele> q1, q2;
pair <ll, ll> r[3];
int a[N];
int T, n;
ll sum, L, R, lcnt, mid, rcnt, ans;

ele fir() {
    if (q1.empty()) {
        ele ans = q2.front(); q2.pop_front(); return ans;
    }
    if (q2.empty()) {
        ele ans = q1.front(); q1.pop_front(); return ans;
    }
    if (q1.front().x <= q2.front().x) {
        ele ans = q1.front(); q1.pop_front(); return ans;   
    }
    ele ans = q2.front(); q2.pop_front(); return ans;
}

int main() {
    // read(T);
    T = 1;
    while (T--) {
        read(n); // read(L); read(R);
        L = 2; R = 3;
        // n = 100000; L = 4; R = 4;
        ans = sum = 0;
        while (!q1.empty()) q1.pop_back();
        while (!q2.empty()) q2.pop_back();
        for (int i = 1; i <= n; i++) {
            read(a[i]);
            // a[i] = 100000;
            // sum += a[i];
            // wxw.insert(ele(i, a[i]));
            // q1.push_back(ele(i, a[i]));
        }
        sort(a + 1, a + n + 1);
        for (int i = 1; i <= n; i++) sum += 1, q1.push_back(ele(a[i], 1));
        rcnt = -1;
        if ((sum - 1) % (R - 1) == 0) {
            lcnt = mid = 0; rcnt = (sum - 1) / (R - 1);
        } else {
            if (L == R) {
                print(-1, '\n');
                continue;
            }
            for (ll i = (sum - 1) / (R - 1); i >= 0; i--) {
                ll las = (sum - 1) - i * (R - 1), cnt = las / (L - 1) - 1;
                if (cnt < 0) continue;
                if (las - cnt * (L - 1) <= (R - 1)) {
                    rcnt = i;
                    mid = las - cnt * (L - 1) + 1;
                    lcnt = cnt;
                    break;
                }
            }
        }
        // cout << "debug : " << lcnt << " " << mid << " " << rcnt << endl;
        r[0] = make_pair(lcnt, L);
        if (mid) r[1] = make_pair(1, mid);
        r[2] = make_pair(rcnt, R);
        if (rcnt == -1) {
            print(-1, '\n');
            continue;
        }
        // int cnt1 = 0, cnt2 = 0;
        int pos = 0;
        while (1) {
            // int pos = 0;
            while (pos <= 2 && !r[pos].first) ++pos;
            if (pos == 3) break;
            ele tmp = fir();
            if (tmp.cnt >= r[pos].second) {
                // ++cnt1;
                // ele tmp = *wxw.begin(); wxw.erase(wxw.begin());
                ll cnt = min(r[pos].first, tmp.cnt / r[pos].second);
                r[pos].first -= cnt; tmp.cnt -= cnt * r[pos].second; ans += cnt * r[pos].second * tmp.x;
                if (tmp.cnt) q1.push_front(tmp);
                // if (!q2.empty()) assert(q2.back().x <= r[pos].second * tmp.x);
                q2.push_back(ele(r[pos].second * tmp.x, cnt));
            } else {
                // ++cnt2;
                --r[pos].first;
                ll las = r[pos].second - tmp.cnt, s = tmp.cnt * tmp.x;
                while (1) {
                    tmp = fir();
                    if (tmp.cnt >= las) {
                        tmp.cnt -= las; s += las * tmp.x;
                        if (tmp.cnt) q1.push_front(tmp);
                        break;
                    } else las -= tmp.cnt, s += tmp.cnt * tmp.x;
                }
                ans += s;
                // if (!q2.empty()) assert(q2.back().x <= s);
                q2.push_back(ele(s, 1));
            }
        }
        // fprintf(stderr, "cnt1 = %d, cnt2 = %d\n", cnt1, cnt2);
        print(ans, '\n');
    }
    return 0;
}