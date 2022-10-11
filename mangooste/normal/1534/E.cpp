#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

#define vec vector
#define ar array

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

    int n, k;
    cin >> n >> k;

    if (n % 2 == 1 && k % 2 == 0) {
        cout << "-1\n";
        return 0;
    }

    auto query = [&](vec<int> i) {
        cout << "?";
        for (auto x : i)
            cout << ' ' << x + 1;

        cout << endl;

        int result;
        cin >> result;
        return result;
    };

    auto ok = [&](int count) {
        if (count < n)
            return false;

        int which = (count / n);
        if (which % 2 == 0)
            which--;

        int left = count - which * n;
        if (left % 2 != 0 || left / 2 > n)
            return false;

        int first = which + 2 * (left != 0);
        if (first <= count / k)
            return true;

        return false;
    };

    int count;
    for (int c = 1;; c++) {
        int current = k * c;
        if (ok(current)) {
            count = k * c;
            break;
        }
    }

    vec<vec<int>> inds(count / k);
    int which = (count / n);
    if (which % 2 == 0)
        which--;

    int left = count - which * n;
    for (int i = 0, pos = 0; i < n; i++) {
        int cnt = which + 2 * (i < left / 2);
        assert(cnt % 2 == 1);
        while (cnt--) {
            inds[pos].push_back(i);
            pos = (pos + 1) % len(inds);
        }
    }

    int answer = 0;
    for (auto &q : inds)
        answer ^= query(q);

    cout << "! " << answer << '\n';
}