#include <bits/stdc++.h>
using namespace std;
int n, t;
const int maxN = (int)1e5;
int a[maxN];
int d[maxN];
int num[maxN];
int brute(vector < int > v) {
    //memset(d, 0, sizeof d);
    for (int i = 1; i < 2 * v.size(); i++) d[i] = maxN;
    d[0] = -maxN;
    for (int i = 0; i < v.size(); i++) {
        int l = 0, r = v.size();
        while (r - l > 1) {
            int mid = (l + r) / 2;
            if (v[i] < d[mid]) {
                r = mid;
            }
            else l = mid;
        }
        //cout << r << endl;
        d[r] = v[i];
    }
    for (int i = v.size(); i >= 0; i--) {
        if (d[i] < maxN) return i;
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    srand(time(0));
    //freopen("input.txt", "r", stdin);
    cin >> n >> t;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        num[a[i]]++;
    }
    if (t <= 4 * n) {
        vector < int > v;
        for (int j = n + 1; j <= n * t; j++) a[j] = a[j - n];
        //v.push_back(0);
        for (int i = 1; i <= n * t; i++) v.push_back(a[i]);
        cout << brute(v);
        return 0;
    }
    for (int i = n + 1; i <= n * n; i++) {
        a[i] = a[i - n];
    }
    int mx = 0;
    for (int i = 1; i <= n; i++) {
        int ans = (t - 2 * n) * num[a[i]];
        vector < int > v1, v2;
        //v1.push_back(0);
        //v2.push_back(0);
        for (int j = 1; j <= n * n; j++) {
            if (a[j] <= a[i]) v1.push_back(a[j]);
            if (a[j] >= a[i]) v2.push_back(a[j]);
        }
        ans = ans + brute(v1) + brute(v2);
        mx = max(mx, ans);
    }
    cout << mx;
    return 0;
}