#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
int n;
const int maxN = (int)1e3 + 10;
int a[maxN];
bool hs[maxN][maxN];
bool cmp(int i, int j) {
    return make_pair(a[i], i) < make_pair(a[j], j);
}
int solve(vector < int > inds) {
    int n = inds.size();
//    cout << n << " GGWP" << endl;
    if (inds.empty()) return 0;
    sort(inds.begin(), inds.end(), cmp);
    int r = inds.size() - 1;
    while (r > 0 && a[inds[r - 1]] == n) r--;
    if (a[inds[r]] != n) {
        assert(r == n - 1);
        int g = inds.back();
        inds.pop_back();
        int p = solve(inds);
        if (p == n - 1) {
            for (int i = 1; i <= a[g] - 1; i++) {
                hs[i][g] = true;
            }
            hs[p + 1][g] = true;
            p++;
            return p;
        }
        else {
            for (int i = 1; i <= a[g]; i++) {
                hs[i][g] = true;
            }
            return p;
        }
    }
    vector < int > lft;
    for (int i = r; i < n - 1; i++) {
        a[inds[i]]--;
    }
    int g = inds.back();
    inds.pop_back();
    int p = solve(inds);
    if (p == n - 1) {
        for (int i = 1; i <= p; i++) {
            hs[i][g] = true;
        }
        if (r != inds.size()) {
            p++;
            for (int i = r; i < inds.size(); i++) {
                hs[p][inds[i]] = true;
            }
        }
        p++;
        hs[p][g] = true;
        return p;
    }
    else {
        for (int i = 1; i <= p; i++) {
            hs[i][g] = true;
        }
        if (r != inds.size()) {
            p++;
            for (int i = r; i < inds.size(); i++) {
                hs[p][inds[i]] = true;
            }
        }
        return p;
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    cin >> n;
    vector < int > inds;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        inds.push_back(i);
    }
    int p = solve(inds);
    cout << p << '\n';
    for (int i = 1; i <= p; i++) {
        for (int j = 1; j <= n; j++) {
            if (hs[i][j]) cout << "1";
            else cout << "0";
        }
        cout << '\n';
    }
    return 0;
}