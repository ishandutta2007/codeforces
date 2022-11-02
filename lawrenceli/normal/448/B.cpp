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

bool a(string s, string t) {
    int p = 0;
    rep(i, s.length())
        if (p < t.length() && s[i] == t[p]) p++;
    return p == t.length();
}

bool b(string s, string t) {
    vector<int> freq (30, 0), freq2 (30, 0);
    rep(i, s.length()) freq[s[i]-'a']++;
    rep(i, t.length()) freq2[t[i]-'a']++;
    rep(i, 30)
        if (freq[i] != freq2[i])
            return 0;
    return 1;
}

bool c(string s, string t) {
    vector<int> freq (30, 0), freq2 (30, 0);
    rep(i, s.length()) freq[s[i]-'a']++;
    rep(i, t.length()) freq2[t[i]-'a']++;
    rep(i, 30)
        if (freq[i] < freq2[i])
            return 0;
    return 1;
}

int main() { _
    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);

    string s, t;
    cin >> s >> t;
    if (a(s, t)) cout << "automaton\n";
    else if (b(s, t)) cout << "array\n";
    else if (c(s, t)) cout << "both\n";
    else cout << "need tree\n";
    return 0;
}