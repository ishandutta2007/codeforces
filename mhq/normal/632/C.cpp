#include <bits/stdc++.h>
using namespace std;
vector < string > s;
int n;
bool cmp(string a, string b) {
    return (a + b) < (b + a);
}
int main() {
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        string p;
        cin >> p;
        s.push_back(p);
    }
    sort(s.begin(), s.end(), cmp);
    string ans;
    for (int i = 0; i < s.size(); i++) {
        ans += s[i];
    }
    cout << ans;
    return 0;
}