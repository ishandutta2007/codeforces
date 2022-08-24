#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double ld;
bool check(string s, string t) {
    int st = 0;
    while (st < s.size() && s[st] == t[st]) st++;
    int en = s.size() - 1;
    while (en >= 0 && s[en] == t[en + 1]) en--;
    return st >= en + 1;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    int n;
    cin >> n;
    string s, t;
    cin >> s >> t;
    string ss, tt;
    int st = 0;
    while (s[st] == t[st]) st++;
    int en = s.size() - 1;
    while (s[en] == t[en]) en--;
    for (int j = st; j <= en; j++) ss += s[j];
    for (int j = st; j <= en; j++) tt += t[j];
    s = ss;
    t = tt;
    string can1 = t[0] + s;
    string can2 = s[0] + t;
    if (can1 == can2) {
        if (check(s, can1) && check(t, can1)) cout << 1;
        else cout << 0;
    }
    else {
        int ans = 0;
        if (check(s, can1) && check(t, can1)) ans++;
        if (check(s, can2) && check(t, can2)) ans++;
        cout << ans << '\n';
    }
}