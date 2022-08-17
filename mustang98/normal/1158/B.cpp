#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza
#define MP make_pair
#define PB push_back

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 1, inf = 1000111222;

string numtos(int n, int len) {
    string res;
    for (int i = 0; i < len; ++i) {
        res += ('0' + (n % 2));
        n /= 2;
    }
    return res;
}

int per(string s) {
    map<string, int> cnt;
    for (int i = 0; i < s.size(); ++i) {
        for (int j = i; j < s.size(); ++j) {
            string sub = s.substr(i, j - i + 1);
            cnt[sub]++;
        }
    }
    int minp = inf;
    for (pair<string, int> p : cnt) {
        if (p.S == 1) {
            minp = min(minp, int(p.F.size()));
        }
    }
    return minp;
}

void solve(int n, int k) {
    int c0 = (n - k) / 2;
    string res = "";
    for (int i = 1; i <= n; ++i) {
        if (i % (c0 + 1) == 0) {
            res += '1';
        } else {
            res += '0';
        }
    }
    cout << res << endl;
}

int n, k;

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n >> k;
    solve(n, k);
    return 0;

    n = 16;
    k = 4;
    for (int i = 0; i < (1 << n); ++i) {
        string s = numtos(i, n);
        if (per(s) == k) {
            cout << s << endl;
        }
    }

    return 0;
}