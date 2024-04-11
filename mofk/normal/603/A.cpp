#include <bits/stdc++.h>

using namespace std;

int main(void) {
    int n; string s;
    cin >> n >> s;
    vector <int> v;
    for (int i = 0; i < s.size(); ++i) if (i == 0 || s[i] != s[i-1]) v.push_back(1); else ++v.back();
    int ans = v.size();
    for (int i = 0; i < v.size(); ++i) if (v[i] >= 3) return cout << v.size() + 2 << endl, 0;
    int cnt = 0;
    for (int i = 0; i < v.size(); ++i) if (v[i] >= 2) ++cnt;
    if (cnt >= 2) ans = v.size() + 2; else if (cnt == 1) ans = v.size() + 1;
    cout << ans << endl;
}