#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    vector<string> a(n);
    vector<string> b(n);
    vector<int> f1(n);
    vector<int> f2(n);
    vector<string> all;
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
        all.push_back(a[i]);
        all.push_back(b[i]);
    }
    vector<int> p(n);
    for (int i = 0; i < n; i++)
        cin >> p[i];
    sort(all.begin(), all.end());
    for (int i = 0; i < n; i++) {
        p[i]--;
        f1[i] = lower_bound(all.begin(), all.end(), a[p[i]]) - all.begin();
        f2[i] = lower_bound(all.begin(), all.end(), b[p[i]]) - all.begin();
    }
    vector<bool> dp1(n);
    vector<bool> dp2(n);
    dp1[0] = dp2[0] = true;
    for (int i = 1; i < n; i++) {
        if (f1[i - 1] < f1[i] && dp1[i - 1])
            dp1[i] = true;
        if (f2[i - 1] < f1[i] && dp2[i - 1])
            dp1[i] = true;
        if (f1[i - 1] < f2[i] && dp1[i - 1])
            dp2[i] = true; 
        if (f2[i - 1] < f2[i] && dp2[i - 1])
            dp2[i] = true;   
    }
    if (dp1.back() || dp2.back())
        cout << "YES";
    else
        cout << "NO";
    return 0;
}