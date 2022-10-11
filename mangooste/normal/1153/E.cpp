#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

#define all(a) begin(a), end(a)
#define rall(a) rbegin(a), rend(a)
#define len(a) ((int)((a).size()))

template<typename A, typename B>
ostream& operator<<(ostream &out, pair<A, B> p) { return out << '(' << p.first << ", " << p.second << ')'; }

template<typename A, typename B = typename enable_if<!is_same<A, string>::value, typename A::value_type>::type>
ostream& operator<<(ostream &out, A vec) { out << '{'; string sep; for (B x : vec) out << sep << x, sep = ", "; return out << '}'; }

void dbg_print() { cerr << endl; }
template<typename A, typename... B> void dbg_print(A a, B... b) { cerr << ' ' << a; dbg_print(b...); }

#ifdef LOCAL
    #define dbg(...) cerr << '#' << __LINE__ << " [" << #__VA_ARGS__ << "]:", dbg_print(__VA_ARGS__)
#else
    #define dbg(...)
#endif

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int n;
    cin >> n;

    auto ask = [&](int x1, int y1, int x2, int y2) {
        if (x1 == 1 && y1 == 1 && x2 == n && y2 == n)
            return 0;

        static int tot = 0;
        assert(++tot <= 2019);

        cout << "? " << x1 << ' ' << y1 << ' ' << x2 << ' ' << y2 << endl;
        int res;
        cin >> res;
        assert(res != -1);
        return res & 1;
    };

    array<pair<int, int>, 2> answer;

    auto finish = [&]() {
        cout << '!';
        for (const auto &[x, y] : answer)
            cout << ' ' << x << ' ' << y;

        cout << endl;
        exit(0);
    };

    for (int i = 1; i <= n; i++) {
        int current = ask(1, 1, i, n);
        if (current == 1) {
            for (int j = 1; j <= n; j++)
                if (ask(i, j, i, j) == 1) {
                    answer[0] = {i, j};
                    break;
                }

            {
                int l = i, r = n;
                while (r - l > 1) {
                    int mid = (l + r) >> 1;
                    (ask(1, 1, mid, n) == 1 ? l : r) = mid;
                }
                answer[1].first = r;
            }

            {
                int l = 0, r = n;
                while (r - l > 1) {
                    int mid = (l + r) >> 1;
                    (ask(answer[1].first, 1, n, mid) == 1 ? r : l) = mid;
                }
                answer[1].second = r;
            }

            finish();
        }
    }

    for (int j = 1; j <= n; j++) {
        int current = ask(1, 1, n, j);
        if (current == 1) {
            {
                int l = 0, r = n;
                while (r - l > 1) {
                    int mid = (l + r) >> 1;
                    (ask(1, 1, mid, j) == 1 ? r : l) = mid;
                }
                answer[0] = {r, j};
            }

            {
                int l = j, r = n;
                while (r - l > 1) {
                    int mid = (l + r) >> 1;
                    (ask(1, 1, n, mid) == 1 ? l : r) = mid;
                }
                answer[1] = {answer[0].first, r};
            }

            finish();
        }
    }
    assert(false);
}