#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza
#define MP make_pair
#define PB push_back

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 200111, inf = 1000111222;

string s, t;

int main()
{
    //freopen("input.txt", "r", stdin);
    int ss, ts;
    cin >> ss >> ts;
    cin >> s >> t;
    if (s == t) {
        cout << "YES";
        return 0;
    }
    int zvpos = -1;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == '*') {
            zvpos = i;
            break;
        }
    }
    if (zvpos == -1) {
        cout << "NO";
        return 0;
    }
    if (t.size() + 1 < s.size()) {
        cout << "NO";
        return 0;
    }
    string pr = s.substr(0, zvpos);
    string suf = s.substr(zvpos + 1);
    for (int i = 0; i < pr.size(); ++i) {
        if (pr[i] != t[i]) {
            cout << "NO";
            return 0;
        }
    }
    for (int i = 0; i < suf.size(); ++i) {
        if (suf[suf.size() - i - 1] != t[t.size() - i - 1]) {
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
    return 0;
}