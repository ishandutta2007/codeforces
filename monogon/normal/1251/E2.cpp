
#include <bits/stdc++.h>

#define ll long long
using namespace std;

const int N = 2e5 + 5;
int t, n;
int m[N], p[N];
vector<int> v[N];
multiset<int> prices;
int pref[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> n;
        for(int i = 0; i < n; i++) {
            v[i].clear();
        }
        for(int i = 0; i < n; i++) {
            cin >> m[i] >> p[i];
            v[m[i]].push_back(i);
        }
        pref[0] = 0;
        for(int i = 1; i < n; i++) {
            pref[i] = pref[i - 1] + v[i - 1].size();
        }
        prices.clear();
        ll cost = 0;
        int cnt = 0;
        for(int i = n - 1; i >= 0; i--) {
            for(int x : v[i]) {
                prices.insert(p[x]);
            }
            while(i > pref[i] + cnt) {
                cost += *prices.begin();
                prices.erase(prices.begin());
                cnt++;
            }
        }
        cout << cost << endl;
    }
}