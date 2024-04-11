#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int inf = 1e9;
const ll inf64 = 1e18;

vector<ll> slow(vector<ll> h) {
    int n = (int) h.size();
    while (1) {
        vector<ll> hh = h;
        for (int i = 0; i + 1 < n; i++) {
            if (h[i] + 2 <= h[i + 1])
                hh[i]++, hh[i + 1]--;
        }
        if (h == hh)
            break;
        h = hh;
    }
    return h;
}

struct Fen {
    int n = 0; // [0, n)
    vector<ll> f;

    Fen(int nn) {
        n = nn;
        f.resize(n);
    }

    void upd(int pos, ll x) {
        for (int cur = pos; cur < n; cur |= (cur + 1))
            f[cur] += x;
    }

    void add(int l, int r, ll x) {
        l = max(0, l);
        r = min(n - 1, r);
        if (l > r)
            return;
        upd(l, x);
        upd(r + 1, -x);
    }

    ll get(int pos) {
        ll res = 0;
        for (int cur = pos; cur >= 0; cur = (cur & (cur + 1)) - 1)
            res += f[cur];
        return res;
    }
};

vector<ll> fast(vector<ll> h) {
    int n = (int) h.size();
    vector<int> st = {1};
    Fen fen(n);
    for (int i = 0; i < n; i++)
        fen.add(i, i, h[i]);
    for (int i = 1; i < n; i++) {

        while ((int) st.size() >= 2 && fen.get(i - 1) + 2 <= fen.get(i) - st.back() + 1) {
            int x = st.back();
            st.pop_back();
            st.back() += x;

            // [i - x, i - 1]
            fen.add(i - x, i - 1, 1);
            fen.add(i, i, -x);
        }
//        while ((int) st.size() >= 2 && h[i - 1] + 2 <= h[i] - st.back() + 1) {
//            int x = st.back();
//            st.pop_back();
//            st.back() += x;
//
//            // [i - x, i - 1]
//            for (int j = i - x; j <= i - 1; j++)
//                h[j]++;
//            h[i] -= x;
//        }

        {
            // h[i - 1] + x <= h[i] - st.back() * x
            // x * (1 + st.back()) <= h[i] - h[i - 1]
            // x <= (h[i] - h[i - 1]) / (1 + st.back())
            ll citers = (fen.get(i) - fen.get(i - 1)) / (1 + st.back());
            fen.add(i - st.back(), i - 1, citers);
            fen.add(i, i, -citers * st.back());

//            ll citers = (h[i] - h[i - 1]) / (1 + st.back());
//            for (int j = i - st.back(); j <= i - 1; j++) {
//                h[j] += citers;
//            }
//            h[i] -= citers * st.back();

        }
//        while (h[i - 1] + 2 <= h[i] - st.back() + 1) {
//            for (int j = i - st.back(); j <= i - 1; j++)
//                h[j]++;
//            h[i] -= st.back();
//        }

        ll cnt = max(0ll, fen.get(i) - fen.get(i - 1) - 1);
        fen.add(i - st.back(), i - st.back() + cnt - 1, 1);
        fen.add(i, i, -cnt);

//        ll cnt = max(0ll, h[i] - h[i - 1] - 1);
//        for (int j = i - st.back(); j <= i - st.back() + cnt - 1; j++) {
//            h[j]++;
//        }
//        h[i] -= cnt;

//        for (int j = i - st.back(); h[i - 1] + 2 <= h[i]; j++) {
//            h[j]++;
//            h[i]--;
//            cnt++;
//        }

        if (cnt > 0) {
            int total = st.back();
            st.pop_back();
            if (!st.empty()) {
                st.back() += cnt;
            } else {
                st.push_back(cnt);
            }
            st.push_back(total - cnt);
        }

        if (fen.get(i - 1) < fen.get(i))
            st.back()++;
        else
            st.push_back(1);
//        if (h[i - 1] < h[i])
//            st.back()++;
//        else
//            st.push_back(1);
    }
    for (int i = 0; i < n; i++)
        h[i] = fen.get(i);
    return h;
}

void test() {
    mt19937 rnd(42);
    const int N = 50;
    const int X = 50;
    while (1) {
        int n = rnd() % N + 1;
        vector<ll> h(n);
        for (int i = 0; i < n; i++)
            h[i] = rnd() % X + 1 + (i > 0 ? h[i - 1] : 0);
        vector<ll> fs = fast(h);
        vector<ll> sl = slow(h);
        if (fs == sl) {
            cout << "OK( "; for (auto x : fs) cout << x << " "; cout << ")" << endl;
        } else {
            cout << "WA\n";
            cout << "exp = "; for (auto x : sl) cout << x << " "; cout << "\n";
            cout << "fnd = "; for (auto x : fs) cout << x << " "; cout << "\n";
            cout << n << "\n";
            for (auto x : h)
                cout << x << " ";
            cout << "\n";
            break;
        }
    }
}

void work() {
    int n;
    cin >> n;
    vector<ll> h(n);
    for (int i = 0; i < n; i++)
        cin >> h[i];
    vector<ll> res = fast(h);
    for (auto x : res)
        cout << x << " ";
    cout << "\n";
}

int main() {

#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    work();
//    test();

    return 0;
}