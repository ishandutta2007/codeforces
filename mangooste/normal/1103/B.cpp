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

inline int ask(int x, int y) {
    cout << "? " << x << ' ' << y << endl;
    char res; cin >> res;
    assert(res != 'e');
    return res == 'y';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    while (true) {
        cin >> s;
        assert(s != "mistake");
        if (s == "end") break;
        assert(s == "start");

        if (ask(0, 1) == 0) {
            cout << "! 1" << endl;
            continue;
        }
        int p = 1;
        while (ask(p, 2 * p) == 1) p *= 2;

        int l = p;
        int r = 2 * p;
        while (r - l > 1) {
            int mid = ((ll) l + r) / 2;
            if (ask(mid, 2 * p) == 0) {
                l = mid;
            } else {
                r = mid;
            }
        }
        cout << "! " << r << endl;
    }
}