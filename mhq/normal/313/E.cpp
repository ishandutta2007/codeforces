#include <bits/stdc++.h>
using namespace std;
int n, m;
const int maxN = (int)1e5 + 10;
int c1[maxN];
int c2[maxN];
set < pair < int, int > > s1;
set < pair < int, int > > s2;
vector < int > ans;
int main() {
    //freopen("input.txt", "r", stdin);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        c1[x]++;
        s1.insert(make_pair(x, c1[x]));
    }
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        c2[x]++;
        s2.insert(make_pair(x, c2[x]));
    }
    for (int i = 1; i <= n; i++) {
        auto it1 = s1.end();
        it1--;
        int x = (*it1).first;
        auto it = s2.lower_bound(make_pair(m - x, 0));
        if (it != s2.begin()) {
            it--;
            ans.push_back(x + (*it).first);
            s1.erase(it1);
            s2.erase(it);
            continue;
        }
        auto it2 = s2.end();
        it2--;
        int y = (*it2).first;
        auto it3 = s1.lower_bound(make_pair(m - y, 0));
        if (it3 != s1.begin()) {
            it3--;
            ans.push_back(y + (*it3).first);
            s1.erase(it3);
            s2.erase(it2);
            continue;
        }
        ans.push_back(x + y - m);
        s1.erase(it1);
        s2.erase(it2);
    }
    sort(ans.begin(), ans.end());
    reverse(ans.begin(), ans.end());
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    return 0;
}