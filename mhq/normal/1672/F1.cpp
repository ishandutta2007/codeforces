#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;


using ll = long long;
using ld = long double;
const int maxN = 2e5 + 10;
int a[maxN];
int ans[maxN];
int main()
{
    ios_base::sync_with_stdio(false);
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
//  1 1 1 1 2 2 2 2
//  2 2 2 2 1 1 1 1
    int tst;
    cin >> tst;
    while (tst--) {
        int n;
        cin >> n;
        vector<pair<int,int>> f;
        int mx_freq = 0;
        vector<int> p(n + 1);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            f.emplace_back(a[i], i);
            p[a[i]]++;
            mx_freq = max(mx_freq, p[a[i]]);
        }
        sort(f.begin(), f.end());
        for (int j = 0; j < n; j++) {
            ans[f[j].second] = f[(j + mx_freq) % n].first;
        }
        for (int j = 0; j < n; j++) cout << ans[j] << " ";
        cout << '\n';
    }
}