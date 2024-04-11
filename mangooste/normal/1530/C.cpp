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

vector<int> part_sums(const vector<int> &a) {
    vector<int> pref(len(a) + 1);
    for (int i = 0; i < len(a); i++)
        pref[i + 1] = pref[i] + a[i];

    return pref;
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a)
        cin >> x;

    vector<int> b(n);
    for (auto &x : b)
        cin >> x;

    sort(all(a));
    sort(all(b));

    auto pa = part_sums(a);
    auto pb = part_sums(b);

    auto can = [&](int cnt) {
        int new_n = n + cnt;
        int bad = new_n >> 2;
        int our_sum = pa.back() + cnt * 100;
        our_sum -= pa[min(n, bad)];
        if (bad > n)
            our_sum -= (bad - n) * 100;

        int his_sum = pb.back();
        if (cnt < bad)
            his_sum -= pb[bad - cnt];

        return our_sum >= his_sum;
    };

    int answer = 0;
    while (!can(answer))
        answer++;

    cout << answer << '\n';
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int tests;
    cin >> tests;
    while (tests--)
        solve();
}