#include <algorithm>
#include <cassert>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <functional>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <string>
#include <vector>

using namespace std;
using ll = long long;

void Main();

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cout << fixed << setprecision(10);
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    Main();
#ifdef LOCAL
    cout << "\nTime: " << (int)ceil((double)1000 * clock() / CLOCKS_PER_SEC) << " ms";
#endif
}

int ask(string s) {
    cout << s << endl;
    int cur;
    cin >> cur;
    assert(cur != -1);
    if (cur == 0) {
        exit(0);
    }
    return cur;
}

void Main() {
    int n = ask("a") + 1;
    if (n == 301) {
        ask(string(300, 'b'));
    }
    string s(n, 'a');
    int was = ask(s);
    if (was == n) {
        ask(string(n - 1, 'b'));
    }
    for (int i = 0; i < n - 1 && was > 0; i++) {
        s[i] = 'b';
        int cur = ask(s);
        if (cur > was) {
            s[i] = 'a';
        } else {
            was--;
        }
    }
    if (was == 1) {
        s.back() = 'b';
    }
    ask(s);
    assert(false);
}