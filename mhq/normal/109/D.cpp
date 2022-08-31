#include <bits/stdc++.h>
using namespace std;
const int maxN = (int)1e5 + 10;
int a[maxN];
int b[maxN];
int n;
set < pair < int, int > > s;
bool lucky(int x) {
    while (x > 0) {
        if (x % 10 == 4 || x % 10 == 7) {
            x /= 10;
        }
        else return false;
    }
    return true;
}

vector < pair < int, int > > ans;
int main() {
    ios_base::sync_with_stdio(false);
    //freopen("log.in", "r", stdin);
    //freopen("log.out", "w", stdout);
    //freopen("input.txt", "r", stdin);
    cin >> n;
    int ind = -1;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (lucky(a[i])) ind = i;
        b[i] = a[i];
        s.insert(make_pair(a[i], i));
    }
    bool ok = true;
    sort(b + 1, b + n + 1);
    for (int i = 1; i <= n; i++) {
        if (b[i] != a[i]) {
            ok = false;
            break;
        }
    }
    if (ok) {
        cout << "0";
        return 0;
    }
    if (ind == -1) {
        cout << -1;
        return 0;
    }
    for (int i = n; i >= 1; i--) {
        //cout << i << endl;
        if (b[i] == a[ind]) break;
        if (b[i] == a[i]) {
            s.erase(s.find(make_pair(a[i], i)));
            continue;
        }
        auto it = s.lower_bound(make_pair(b[i], 0));
        int pos = (*it).second;
        if (ind == i) {
            ans.push_back(make_pair(ind, pos));
            s.erase(it);
            s.erase(s.find(make_pair(a[ind], ind)));
            swap(a[ind], a[pos]);
            ind = pos;
            s.insert(make_pair(a[ind], ind));
        }
        else if (pos == ind) continue;
        else {
            ans.push_back(make_pair(i, ind));
            ans.push_back(make_pair(i, pos));
            s.erase(it);
            s.erase(s.find(make_pair(a[ind], ind)));
            s.erase(s.find(make_pair(a[i], i)));
            swap(a[ind], a[i]);
            swap(a[i], a[pos]);
            swap(ind, pos);
            s.insert(make_pair(a[ind], ind));
            s.insert(make_pair(a[pos], pos));
        }
    }
    for (int i = 1; i <= n; i++) {
        if (b[i] == a[ind]) break;
        if (b[i] == a[i]) {
            s.erase(s.find(make_pair(a[i], i)));
            continue;
        }
        auto it = s.lower_bound(make_pair(b[i], 0));
        int pos = (*it).second;
        if (ind == i) {
            ans.push_back(make_pair(ind, pos));
            s.erase(it);
            s.erase(s.find(make_pair(a[ind], ind)));
            swap(a[ind], a[pos]);
            ind = pos;
            s.insert(make_pair(a[ind], ind));
        }
        else if (pos == ind) continue;
        else {
            ans.push_back(make_pair(i, ind));
            ans.push_back(make_pair(i, pos));
            s.erase(it);
            s.erase(s.find(make_pair(a[ind], ind)));
            s.erase(s.find(make_pair(a[i], i)));
            swap(a[ind], a[i]);
            swap(a[i], a[pos]);
            swap(ind, pos);
            s.insert(make_pair(a[ind], ind));
            s.insert(make_pair(a[pos], pos));
        }
    }
    cout << ans.size() << '\n';
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i].first << " " << ans[i].second << '\n';
    }
    return 0;
}