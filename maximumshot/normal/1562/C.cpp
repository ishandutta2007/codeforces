#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int inf = 1e9;
const ll inf64 = 1e18;

vector<int> fast(int n, string s) {
    int x = n / 2;
    for (int i = 1; i + x - 1 < n; i++) {
        if (s[i - 1] == '0')
            return {i, i + x, i + 1, i + x};
    }
    if (n % 2)
        return {1, x, 2, x + 1};
    if (s[x] == '1')
        return {1, x, 2, x + 1};
    return {1, x + 1, 1, x};
}

int to_int(string s) {
    int res = 0;
    for (char c : s)
        res = res * 2 + c - '0';
    return res;
}

int main() {

#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        auto res = fast(n, s);
        for (auto x : res)
            cout << x << " ";
        cout << "\n";

//        string t = s.substr(res[0] - 1, res[1] - res[0] + 1);
//        string w = s.substr(res[2] - 1, res[3] - res[2] + 1);
//
//        cout << to_int(t) << " " << to_int(w) << "\n";
    }

    return 0;
}