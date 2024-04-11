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

bool ask(int h, int w, int i1, int j1, int i2, int j2) {
    cout << "? " << h << ' ' << w << ' ' << i1 << ' ' << j1 << ' ' << i2 << ' ' << j2 << endl;
    int res;
    cin >> res;
    return res;
}

bool check(int m, bool horizontal, int len, int max_len) {
    for (int l = 1; max_len - l + 1 > len;) {
        int coeff = (max_len - l + 1) / len;
        int mid = l + coeff / 2 * len;

        if (!(horizontal ? ask(m, coeff / 2 * len, 1, l, 1, mid) : ask(coeff / 2 * len, m, l, 1, mid, 1)))
            return false;

        l = mid;
    }

    return true;
}

int solve(int n, int m, bool horizontal) {
    vector<bool> good(n + 1);
    good[n] = true;

    for (int i = n - 1; i >= 1; i--) {
        if (n % i != 0 || good[i])
            continue;

        bool correct = true;
        for (int j = 2 * i; j <= n; j += i)
            if (n % j == 0 && !good[j]) {
                correct = false;
                break;
            }

        if (!correct)
            continue;

        int j = i + 1;
        while (n % j != 0 || j % i != 0)
            j++;

        good[i] = check(m, horizontal, i, j);
        if (!good[i])
            continue;

        for (int j = i + 1; j <= n; j++)
            if (good[j]) {
                int block = gcd(i, j);
                for (int x = block; x <= n; x += block)
                    if (n % x == 0)
                        good[x] = true;
            }
    }

    return accumulate(all(good), 0);    
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    int answer = solve(n, m, false) * solve(m, n, true);
    cout << "! " << answer << endl;
}