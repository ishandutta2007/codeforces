#include <bits/stdc++.h>
#define pb push_back
#define int long long

using namespace std;

const long long M = 1e9 + 7;
const int N = 2e5 + 5;

int a[N], kol[N], n, k;
string s;

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    cin >> s;
    vector<pair<int, int> > v;
    int cv = s[0], ck = 1;
    for (int i = 1; i < s.size(); i++)
        if (s[i] == s[i - 1])
            ck++;
        else {
            v.pb({cv, ck});
            cv = s[i];
            ck = 1;
        }
    v.pb({cv, ck});
    int ans = 0, cur = 0;
    for (int i = 0; i < v.size(); i++) {
    if (v[i].second <= k) {
        int ck = v[i].second;
        //cout << cur << endl;
        for (int j = cur; j < cur + ck; j++)
            ans += a[j];
        //cout << cur + ck << ' ' << ans << endl;
        } else {
            int ck = v[i].second;
            //cout << '*' << cur << ' ' << ck << endl;
            sort(a + cur, a + ck + cur);
            for (int j = cur + ck - 1; j >= cur + ck - k; j--)
                ans += a[j];//, cout << a[j] << endl;
            //cout << '/' << ans << endl;
        }
        int ck = v[i].second;
        cur += ck;
    }
    cout << ans;
    return 0;
}