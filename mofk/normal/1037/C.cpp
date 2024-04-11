#include <bits/stdc++.h>

using namespace std;

int n;
string s, t;
int f[1000006];

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> s >> t;
    vector <pair <int, char> > v;
    v.push_back(make_pair(-2, '?'));
    for (int i = 0; i < n; ++i) if (s[i] != t[i]) v.push_back(make_pair(i, s[i]));
    int ans = 0;
    for (int i = 1; i < v.size(); ++i) {
        f[i] = f[i-1] + 1;
        if (v[i].first - v[i-1].first == 1 && v[i].second != v[i-1].second)
            f[i] = min(f[i], f[i-2] + 1);
    }
    cout << f[v.size() - 1] << endl;
    return 0;
}