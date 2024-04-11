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

string solve(int n) {
    string res;
    for (int cur = 0, i = 0; i < n; i += 2, cur ^= 1) {
        if (i + 1 < n) {
            res.push_back(cur + 'a');
            res.push_back(cur + 'a');
        } else {
            res.push_back(cur + 'a');
        }
    }

    return res;
}

bool check(int n, const string &s) { // TODO: add print (specify error)
    if ((int) s.size() != n)
        return false;
    for (int i = 0; i + 2 < n; i++) {
        if (s[i] == s[i + 2])
            return false;
    }
    return true;
}

void work() {
    int n;
    cin >> n;
    cout << solve(n) << "\n";
}

void test() {
    for (int n = 1; n <= 100; n++) {
        string s = solve(n);
        if (!check(n, s)) {
            cout << "WA\n";
            cout << n << "\n";
            cout << "found: " << s << "\n";
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

//    test();
    work();

    return 0;
}