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
    vector<int> a(n);
    for (auto &x : a)
        cin >> x;

    vector<int> b(n);
    for (auto &x : b)
        cin >> x;

    ll total = 0;
    for (int i = 0; i < n; i++)
        total += 1ll * a[i] * b[i];

    ll answer = total;
    for (int mid = 0; mid < n; mid++) {
        ll current = total;
        for (int i = mid - 1, j = mid + 1; i >= 0 && j < n; i--, j++) {
            current -= 1ll * a[i] * b[i] + 1ll * a[j] * b[j];
            current += 1ll * a[i] * b[j] + 1ll * a[j] * b[i];
            answer = max(answer, current);
        }
    }

    for (int mid = 0; mid < n; mid++) {
        ll current = total;
        for (int i = mid, j = mid + 1; i >= 0 && j < n; i--, j++) {
            current -= 1ll * a[i] * b[i] + 1ll * a[j] * b[j];
            current += 1ll * a[i] * b[j] + 1ll * a[j] * b[i];
            answer = max(answer, current);
        }
    }
    cout << answer << '\n';
}