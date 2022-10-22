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

const ll X = 1e15;

ll eval(string s) {
    ll res = 0;
    char op = '+';
    for (int i = 0; i < (int) s.size(); i++) {
        if (s[i] == '-' || s[i] == '+') {
            op = s[i];
            continue;
        }
        int j = i;
        while (j < (int) s.size() && s[j] != '-' && s[j] != '+')
            j++;
        j--;
        ll tmp = 1;
        for (int q = i; q <= j; q += 2)
            tmp *= (s[q] - '0');
        if (op == '+')
            res += tmp;
        else
            res -= tmp;
        i = j;
    }
    return res;
}

string DP(int n, vector<int> a, string s) {
    vector<ll> dp(n + 1, -inf64);
    vector<int> fr(n + 1, -1);
    dp[0] = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i] == 1) {
            dp[i] = dp[i - 1] + 1;
            fr[i] = i;
        } else {
            ll ml = 1;
            for (int j = i; j >= 1; j--) {
                ml *= a[j];
                if (dp[i] < dp[j - 1] + ml) {
                    dp[i] = dp[j - 1] + ml;
                    fr[i] = j;
                }
            }
        }
    }
    string res;
    for (int i = 1; i <= n; i++) {
        if (i > 1)
            res.push_back('+');
        res.push_back(a[i] + '0');
    }
    for (int i = n; i >= 1;) {
        int j = fr[i];
        int le = 2 * (j - 1);
        int ri = 2 * (i - 1);
        for (int q = le + 1; q < ri; q += 2)
            res[q] = '*';
        i = j - 1;
    }
    return res;
}

string slow(int n, vector<int> a, string s) {
    ll best = -inf64;
    string res = "?";
    string ops(n - 1, '?');
    function<void(int)> rec = [&](int i) {
        if (i == n - 1) {
            string tmp;
            tmp.push_back(a[1] + '0');
            for (int j = 0; j < n - 1; j++)
                tmp.push_back(ops[j]), tmp.push_back(a[j + 2] + '0');
            ll tmp_score = eval(tmp);
            if (tmp_score > best) {
                best = tmp_score;
                res = tmp;
            }
            return;
        }
        for (char c : s) {
            ops[i] = c;
            rec(i + 1);
        }
    };
    rec(0);
    return res;
}

string fast(int n, vector<int> a, string s) {
    if ((int) s.size() == 1) {
        string res;
        for (int i = 1; i <= n; i++) {
            if (i > 1)
                res.push_back(s[0]);
            res.push_back(a[i] + '0');
        }
        return res;
    }
    set<char> Q(s.begin(), s.end());
    if (Q.count('+') && Q.count('*')) {
        string res;
        for (int i = 1; i <= n; i++) {
            if (a[i] == 0 || a[i] == 1) {
                if (i > 1)
                    res.push_back('+');
                res.push_back(a[i] + '0');
                continue;
            }
            int j = i;
            while (j <= n && a[j] != 0)
                j++;
            j--;
            if (i > 1)
                res.push_back('+');
            int jj = j;
            while (a[jj] == 1)
                jj--;
            ll ml = 1;
            for (int q = i; q <= jj; q++){
                ml = min(X, ml * a[q]);
            }
            if (ml == X) {
                for (int q = i; q <= jj; q++) {
                    res.push_back(a[q] + '0');
                    if (q < jj)
                        res.push_back('*');
                }
            } else {
                int nn = jj - i + 1;
                vector<int> aa(nn + 1);
                for (int q = i; q <= jj; q++)
                    aa[q - i + 1] = a[q];
                res += DP(nn, aa, s);
            }
            while (jj < j)
                res.push_back('+'), res.push_back(a[++jj] + '0');
            i = j;
        }
        return res;
    }
    // +- | -*
    if (Q.count('+')) {
        string res;
        for (int i = 1; i <= n; i++) {
            if (i > 1)
                res.push_back('+');
            res.push_back(a[i] + '0');
        }
        return res;
    }
    // *-
    {
        string res;
        int i = 1;
        while (i <= n && a[i] > 0) {
            if (i > 1)
                res.push_back('*');
            res.push_back(a[i] + '0');
            i++;
        }
        if (i <= n) {
            if (i > 1)
                res.push_back('-');
            res.push_back(a[i] + '0');
            i++;
            while (i <= n)
                res.push_back('*'), res.push_back(a[i] + '0'), i++;
        }
        return res;
    }
}

void work() {
    int n;
    vector<int> a;
    string s;

    cin >> n;
    a.resize(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    cin >> s;

    string fs = fast(n, a, s);

    cout << fs << "\n";

//    cout << "val = " << eval(fs) << "\n";
}

void test() {
    mt19937 rnd(42);
    const int N = 15;
    while (1) {
        int n;
        vector<int> a;
        string s;

        n = rnd() % N + 1;
        a.resize(n + 1);
        for (int i = 1; i <= n; i++)
            a[i] = rnd() % 10;

        string S = "+-*";
        int mask = rnd() % 7 + 1;
        for (int i = 0; i < 3; i++)
            if ((1 << i) & mask)
                s.push_back(S[i]);

        string fs = fast(n, a, s);
        string sl = slow(n, a, s);

        ll fs_score = eval(fs);
        ll sl_score = eval(sl);

        if (fs_score == sl_score) {
            cout << "OK(" << fs_score << ")" << endl;
        } else {
            cout << "WA\n";
            cout << "exp = " << sl << ", val = " << sl_score << "\n";
            cout << "fnd = " << fs << ", val = " << fs_score << "\n";
            cout << "\n";
            cout << n << "\n";
            for (int i = 1; i <= n; i++)
                cout << a[i] << " ";
            cout << "\n";
            cout << s << "\n";
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