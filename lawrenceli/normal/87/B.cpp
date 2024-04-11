#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define px real()
#define py imag()
#define rep(i, n) for (int i=0, _##i=(n); i<_##i; ++i)
#define repi(i, n) for (__typeof((n).begin()) i=(n).begin(), _##i=n.end(); i != _##i; ++i)
#define sz(x) int((x).size())
#define print(x) cerr << #x << ": " << x << endl
#define _ ios_base::sync_with_stdio(0); cin.tie(0);

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef complex<double> pnt;

int n;
map<string, int> mp;

pair<string, int> getp(string s) {
    int x = 0;
    while (s[s.length()-1] == '*') x++, s = s.substr(0, s.length()-1);
    while (s[0] == '&') x--, s = s.substr(1);
    assert(s[0] != '*');
    assert(s[s.length()-1] != '&');
    return make_pair(s, x);
}

int add(int a, int b) {
    if (a == -1) return -1;
    a += b;
    if (a < 0) return -1;
    else return a;
}

int main() { _
    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);

    mp["void"] = 0;
    mp["errtype"] = -1;
    cin >> n;
    rep(i, n) {
        string t; cin >> t;
        if (t == "typedef") {
            string a, b;
            cin >> a >> b;
            pair<string, int> p = getp(a);
            if (mp.count(p.fi)) mp[b] = add(mp[p.fi], p.se);
        } else {
            string a;
            cin >> a;
            pair<string, int> p = getp(a);
            if (mp.count(p.fi)) {
                int x = add(mp[p.fi], p.se);
                if (x == -1) cout << "errtype\n";
                else {
                    cout << "void";
                    rep(j, x) cout << '*';
                    cout << '\n';
                }
            } else cout << "errtype\n";
        }
    }
    return 0;
}