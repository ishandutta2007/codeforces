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

int slow(string s, string t) {
    int n = (int) s.size();
    int m = (int) t.size();
    for (int mask = 0; mask < (1 << n); mask++) {
        string tmp;
        for (int i = 0; i < n; i++) {
            if ((1 << i) & mask) {
                tmp.push_back(s[i]);
            } else {
                if (!tmp.empty())
                    tmp.pop_back();
            }
        }
        if (tmp == t)
            return 1;
    }
    return 0;
}

int fast(string s, string t) {
    reverse(s.begin(), s.end());
    reverse(t.begin(), t.end());
    int n = (int) s.size();
    int m = (int) t.size();
    vector<int> dp(n, -inf);
    int ok = 0;
    vector<vector<int>> last(26, vector<int>(2, -1));
    for (int i = 0; i < n; i++) {
        if (t[0] == s[i] && i % 2 == 0)
            dp[i] = 1;
//            for (int j = i - 1; j >= 0; j -= 2) {
//                if (t[dp[j]] == s[i]) {
//                    dp[i] = max(dp[i], dp[j] + 1);
//                    break;
//                }
//            }
        if (int j = last[s[i] - 'a'][(i + 1) % 2]; j != -1) {
            dp[i] = max(dp[i], dp[j] + 1);
        }
        if (dp[i] == m) {
            ok = 1;
            break;
        }
        if (dp[i] >= 0) {
            int& was = last[t[dp[i]] - 'a'][i % 2];
            if (was == -1 || dp[was] < dp[i])
                was = i;
        }
    }
    return ok;
}

void work() {
    int q;
    cin >> q;
    while (q--) {
        string s, t;
        cin >> s >> t;
        int res = fast(s, t);
        cout << (res ? "YES" : "NO") << "\n";
    }
}

string gen_string(mt19937& rnd, int maxn, int maxc) {
    int n = rnd() % maxn + 1;
    string res(n, '?');
    for (char& c : res)
        c = rnd() % maxc + 'a';
    return res;
}

void test() {
    mt19937 rnd(42);
    const int MAXN = 15;
    const int MAXC = 2;
    while (1) {
        string s = gen_string(rnd, MAXN, MAXC);
        string t = gen_string(rnd, MAXN, MAXC);
        int fs = fast(s, t);
        int sl = slow(s, t);
        if (fs == sl) {
            cout << "OK(" << fs << ")" << endl;
        } else {
            cout << "WA\n";
            cout << "exp = " << sl << "\n";
            cout << "fnd = " << fs << "\n";
            cout << 1 << "\n" << s << "\n" << t << "\n";
            break;
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
//    test();

    return 0;
}