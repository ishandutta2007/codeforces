#include <bits/stdc++.h>

using namespace std;
const int maxn = 3e5;
set<pair<int, int> > s;
vector<int > d[maxn];
int a[maxn];
int n, cnt;
int main() {
    ios_base::sync_with_stdio(0);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];

    for (int i = 1; i <= n; i++) {
        if (s.lower_bound(make_pair(a[i], 0)) == s.begin()) {
            cnt++;
            d[cnt].push_back(a[i]);
            s.insert(make_pair(a[i], cnt));
        }
        else {
            auto it = s.lower_bound(make_pair(a[i], 0));
            it--;
            int x = (*it).second;
            s.erase(it);
            d[x].push_back(a[i]);
            s.insert(make_pair(a[i], x));
        }
    }
    for (int i = 1; i <= cnt; i++) {
        for (int j = 0; j < d[i].size(); j++) cout << d[i][j] << " ";
        cout << "\n";
    }
    return 0;
}