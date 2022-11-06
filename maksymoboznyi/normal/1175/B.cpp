#include <bits/stdc++.h>
#define pb push_back
#define int long long

using namespace std;

const int N = 3e5 + 5;
const long long M = 1e9 + 7;

long long n, pref[N];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    vector<long long> q;
    pref[0] = 1;
    cin >> n;
    long long MAX = (1ll << 32) - 1, all = 0;
    for (int i = 1; i <= n; i++) {
        string s;
        cin >> s;
        if (s == "end")
            q.pop_back();
        if (s == "for") {
            int x;
            cin >> x;
            q.pb(x);
            pref[q.size()] = pref[q.size() - 1] * x;
            if (pref[q.size()] > 1e10)
                pref[q.size()] = 1e10;
        }
        if (s == "add"){
            all += pref[q.size()];
            if (all > MAX) {
                cout << "OVERFLOW!!!";
                return 0;
            }
        }
    }
    cout << all;
    return 0;
}