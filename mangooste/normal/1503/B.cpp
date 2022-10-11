#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define vec vector
#define ar array

#define all(a) (a).begin(), (a).end()
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
    vec<vec<pair<int, int>>> poses(2);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            poses[(i + j) % 2].emplace_back(i, j);
        }
    }
    auto go = [&](int type, int who) {
        cout << type + 1 << ' ' << poses[who].back().first + 1 << ' ' << poses[who].back().second + 1 << endl;
        poses[who].pop_back();
    };
    for (int i = 0; i < n * n; i++) {
        int a;
        cin >> a;
        if (a == 1) {
            if (len(poses[1])) {
                go(1, 1);
            } else {
                go(2, 0);
            }
        } else if (a == 2) {
            if (len(poses[0])) {
                go(0, 0);
            } else {
                go(2, 1);
            }
        } else {
            if (len(poses[0])) {
                go(0, 0);
            } else {
                go(1, 1);
            }
        }
    }
}