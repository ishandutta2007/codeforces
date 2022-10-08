
#include <bits/stdc++.h>

#define ll long long
using namespace std;

const int N = 2e5 + 5;
int q, n, m, s;
ll a[N], p;
vector<pair<ll, int>> v;
map<ll, int> stam;

// in the first day, we must defeat the maximum # of monsters possible
// greedily choose the hero that can defeat the most monsters
// sort heroes by power in reverse. For a given power threshold, find maximum
// stamina of a hero above that threshold

// bool cmp(const pair<ll, int> &p1, const pair<ll, int> &p2) {
//     return p1.first == p2.first ? p1.second < p2.second : p1.first < p2.first;
// }

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> q;
    while(q--) {
        cin >> n;
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }
        v.clear();
        stam.clear();
        cin >> m;
        for(int i = 0; i < m; i++) {
            cin >> p >> s;
            v.emplace_back(p, s);
        }
        sort(v.begin(), v.end());
        s = 0;
        for(int i = m - 1; i >= 0; i--) {
            stam[v[i].first] = s = max(s, v[i].second);
        }
        int days = 1;
        int monst = 0;
        p = 0;
        for(int i = 0; i < n; i++) {
            p = max(p, a[i]);
            monst++;
            auto it = lower_bound(v.begin(), v.end(), make_pair(p, -1));
            if(it == v.end() || stam[it->first] < monst) {
                p = 0;
                days++;
                if(monst == 1) {
                    cout << -1 << endl;
                    goto endloop;
                }
                monst = 0;
                i--;
            }
        }
        cout << days << endl;
        endloop:;
    }
}