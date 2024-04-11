#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef long long ll;

const int inf = 1e9;
const ll inf64 = 1e18;

string f(string s) {
    string res = "";
    for (char c : s) {
        if (c != 'a') {
            res.push_back(c);
        }
    }
    return res;
}

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string t;

    cin >> t;

    int cnt = 0;

    for (char c : t) {
        cnt += c == 'a';
    }

    int l = ((int)t.size() + cnt);

    if (l % 2) {
        cout << ":(\n";
        return 0;
    }

    l /= 2;

    string s = t.substr(0, l);

    if (s + f(s) != t) {
        cout << ":(\n";
    } else {
        cout << s << "\n";
    }

    return 0;
}