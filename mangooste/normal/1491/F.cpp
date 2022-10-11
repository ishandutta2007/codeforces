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

template<typename T>
vector<T> substr(const vector<T> &a, int l, int r) {
    vector<T> result(r - l);
    for (int i = l; i < r; i++)
        result[i - l] = a[i];

    return result;
}

int ask(const vector<int> &a, const vector<int> &b) {
    cout << "? " << len(a) << ' ' << len(b) << '\n';
    for (auto x : a)
        cout << x + 1 << ' ';

    cout << '\n';
    for (auto x : b)
        cout << x + 1 << ' ';

    cout << endl;

    int res;
    cin >> res;
    return res;
}

void solve() {
    int n;
    cin >> n;
    vector<int> pref{0};
    for (int i = 1; i < n; i++)
        if (ask(pref, {i}) == 0)
            pref.push_back(i);
        else
            break;

    vector<int> answer;
    for (int i = len(pref) + 1; i < n; i++)
        if (ask(pref, {i}) == 0)
            answer.push_back(i);

    int l = 0, r = len(pref);
    while (r - l > 1) {
        int mid = (l + r) >> 1;
        if (ask(substr(pref, 0, mid), {len(pref)}) == 0)
            l = mid;
        else
            r = mid;
    }

    for (int i = 0; i < len(pref); i++)
        if (i != l)
            answer.push_back(i);

    cout << "! " << len(answer);
    for (auto x : answer)
        cout << ' ' << x + 1;

    cout << endl;
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int tests;
    cin >> tests;
    while (tests--)
        solve();
}