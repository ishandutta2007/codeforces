#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
bool cmp(vector < int >& a, vector < int >& b) {
    int sm = 0;
    for (int i = 0; i < 26; i++) {
        sm += b[i] - a[i];
    }
    return sm > 0;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    int n;
    cin >> n;
    cout << "? " << 1 << " " << n << endl;
    multiset < vector < int > > all;
    char any;
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j++) {
            string s;
            cin >> s;
            vector < int > f(26);
            for (char& c : s) {
                f[c - 'a']++;
                any = c;
            }
            all.insert(f);
        }
    }
    if (n == 1) {
        cout << "! " << any << endl;
        return 0;
    }
    cout << "? " << 2 << " " << n << endl;
    for (int i = 2; i <= n; i++) {
        for (int j = i; j <= n; j++) {
            string s;
            cin >> s;
            vector < int > f(26);
            for (char& c : s) {
                f[c - 'a']++;
            }
            all.erase(all.find(f));
        }
    }
    vector < vector < int > > gg;
    for (auto it : all) {
        gg.push_back(it);
    }
    sort(gg.begin(), gg.end(), cmp);
    vector < int > hs(26);
    string ans;
    for (int i = 0; i < gg.size(); i++) {
        for (int j = 0; j < 26; j++) {
            if (gg[i][j] > hs[j]) {
                ans += (char)(j + 'a');
                hs[j] = gg[i][j];
            }
        }
    }
    cout << "! " << ans << endl;
    return 0;
}