#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;

const int inf = 1e9;
const ll inf64 = 1e18;

int solve(string s) {
    map<string, int> cnt;
    for (int i = 0; i < (int)s.size(); i++) {
        string t = "";
        for (int j = i; j < (int)s.size(); j++) {
            t.push_back(s[j]);
            cnt[t]++;
        }
    }
    int res = inf;
    for (auto p : cnt) {
        if (p.second == 1) {
            res = min(res, (int)p.first.size());
        }
    }
    return res;
}

void work() {
    int n, k;

    cin >> n >> k;

    if (n == k) {
        cout << string(n, '0') << "\n";
        return;
    }

    if (n % 2 && k == 1) {
//        cerr << "k = " << solve("1" + string(n - 1, '0')) << "\n";
        cout << "1" + string(n - 1, '0') << "\n";;
        return;
    }

    if (3 * k <= n + 4) {
        int l = k - 2;
        int r = l + k - 1;
        string s = "";
        for (int i = 0; i < l; i++) {
            s.push_back('0');
        }
        s.push_back('1');
        for (int i = l + 1; i < r; i++) {
            s.push_back('0');
        }
        s.push_back('1');
        for (int i = r + 1; i < n; i++) {
            s.push_back('0');
        }
//        cerr << "k = " << solve(s) << "\n";
        cout << s << "\n";
        return;
    }

    int per = (n - k) / 2 + 1;

    string t(per, '0');
    t[per - 1] = '1';

    string s = "";

    while ((int)s.size() < n) s += t;
    while ((int)s.size() > n) s.pop_back();

//    cerr << "k = " << solve(s) << "\n";
    cout << s << "\n";
}

void test() {
    int n, k;
    cin >> n >> k;

    int mx = 0;
    for (int l = 0; l < n; l++) {
        for (int r = l + 1; r < n; r++) {
            if (r - l + 1 != k) continue;
            if (l != k - 2) continue;
            string s = "";
            for (int i = 0; i < l; i++) {
                s.push_back('0');
            }
            s.push_back('1');
            for (int i = l + 1; i < r; i++) {
                s.push_back('0');
            }
            s.push_back('1');
            for (int i = r + 1; i < n; i++) {
                s.push_back('0');
            }
            cout << s << " : " << solve(s) << "\n";
        }
    }
}

void brute() {
    int n = 7;
    int k = 1;
    for (int mask = 0; mask < (1 << n); mask++) {
        string s = "";
        for (int i = 0; i < n; i++) {
            s.push_back(((mask >> i) & 1) + '0');
        }
        if (solve(s) == k) {
            cout << s << "\n";
        }
    }
}

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    work();
//    test();
//    brute();

    return 0;
}