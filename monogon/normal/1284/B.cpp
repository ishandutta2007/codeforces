
#include <bits/stdc++.h>

#define ll long long
using namespace std;

const int N = 1e5 + 5;
int n, l, a, m, M[N], pref[N];
bool b[N];
vector<pair<int, int>> v;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> l >> m;
        M[i] = m;
        for(int j = 1; j < l; j++) {
            cin >> a;
            if(a > m) b[i] = true;
            M[i] = max(M[i], a);
            m = min(m, a);
        }
        v.emplace_back(m, i);
    }
    sort(v.begin(), v.end());
    pref[0] = 0;
    for(int i = 0; i < n; i++) {
        pref[i + 1] = pref[i] + b[v[i].second];
    }

    ll cnt = 0;
    for(int i = 0; i < n; i++) {
        if(b[i]) {
            cnt += n;
        }else {
            int j = lower_bound(v.begin(), v.end(), pair(M[i], 0)) - v.begin();
            cnt += j + pref[n] - pref[j];
        }
    }
    cout << cnt << endl;
}