#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;
typedef long double ld;

const int inf = 1e9;
const ll inf64 = 1e18;

bool is_prime(int x) {
    if (x <= 1)
        return false;
    for (int p = 2; p * p <= x; p++) {
        if (x % p == 0)
            return false;
    }
    return true;
}

int main() {

#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

//    for (int x = 0; x < 60; x++) {
//        if (is_prime(x))
//            cout << x << ", ";
//    }

    vector<int> pr = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59};
    int sz = (int) pr.size();
    const int X = 60;
    vector<int> mask(X);
    for (int x = 2; x < X; x++) {
        for (int i = 0; i < sz; i++) {
            if (x % pr[i] == 0)
                mask[x] |= (1 << i);
        }
    }

    int n;
    cin >> n;

    vector<pii> a(n);
    vector<int> pref(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(a.begin(), a.end());
    for (int i = 0; i < n; i++) {
        if (i > 0)
            pref[i] = pref[i - 1];
        pref[i] += a[i].first - 1;
    }

    vector<int> st;

    int res = inf;
    vector<int> b;

    function<void(int, int)> rec = [&](int xx, int MASK) {
        if (xx == X || (int) st.size() == n) {
            int score = 0;
            for (int i = 0; i < (int) st.size(); i++)
                score += abs(a[n - 1 - i].first - st[(int) st.size() - 1 - i]);
            if ((int) st.size() < n)
                score += pref[n - 1 - (int) st.size()];
            if (score < res) {
                res = score;
                b = st;
            }
            return;
        }
        if (!(mask[xx] & MASK)) {
            st.push_back(xx);
            rec(xx + 1, MASK | mask[xx]);
            st.pop_back();
        }
        rec(xx + 1, MASK);
    };

    rec(2, 0);

    st = b;
    vector<int> out(n, 1);
    for (int i = 0; i < (int) st.size(); i++) {
        out[a[n - 1 - i].second] = st[(int) st.size() - 1 - i];
    }

    for (int x : out)
        cout << x << " ";
    cout << "\n";

    return 0;
}