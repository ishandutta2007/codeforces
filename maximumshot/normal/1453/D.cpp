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

int cnt_bits(ll x) {
    int res = 0;
    while (x > 0)
        res += int(x & 1), x >>= 1;
    return res;
}

vector<int> get_bits(ll x) {
    vector<int> res;
    for (int i = 0; x > 0; i++, x >>= 1) {
        if (x & 1)
            res.push_back(i);
    }
    return res;
}

vector<int> fast(ll k) {
    if (k % 2)
        return {};
    for (int m = 1; m <= 2000; m++) {
        if ((k + 2 * m) % 2)
            continue;
        ll value = (k + 2 * m) / 2;
        int bp = cnt_bits(value);
        if (bp > m)
            continue;
        vector<int> bits = get_bits(value);
        vector<int> cnt(70);
        for (int i : bits)
            cnt[i]++;
        if (cnt[0])
            continue;
        int cur = (int) bits.size();
        while (cur < m) {
            int any = 0;
            for (int i = 2; i < (int) cnt.size(); i++)
                if (cnt[i] > 0) {
                    any = 1;
                    cnt[i]--;
                    cnt[i - 1] += 2;
                    cur++;
                    break;
                }
            if (!any)
                break;
        }
        if (cur < m)
            continue;
        vector<int> res = {1};

        for (int i = 0; i < (int) cnt.size(); i++) {
            while (cnt[i] > 0) {
                cnt[i]--;
                for (int j = 1; j < i; j++)
                    res.push_back(0);
                res.push_back(1);
            }
        }
        res.pop_back();
        if ((int) res.size() > 2000)
            continue;
        return res;
    }
    return {};
}

void work() {
    int t;
    cin >> t;
    while (t--) {
        ll k;
        cin >> k;
        vector<int> fs = fast(k);
        if (fs.empty()) {
            cout << "-1\n";
        } else {
            cout << (int) fs.size() << "\n";
            for (int x : fs)
                cout << x << " ";
            cout << "\n";
        }
    }
}

int main() {

#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    work();

    return 0;
}