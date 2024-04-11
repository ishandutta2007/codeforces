#include <bits/stdc++.h>
using namespace std;
const int maxN = 2 * (int)1e5 + 5;
int n, x;
vector < int > a;
int b[maxN];
vector < int > comp[maxN];
long long ans;
int number;
struct node {
    int next[2];
    int path;
    node() {
        for (int i = 0; i < 2; i++) next[i] = -1;
        path = 0;
    }
};
node t[maxN * 30];
int sz = 1;
pair < int, int > mi[maxN];

void add(int x) {
    int v = 0;
    for (int j = 29; j >= 0; j--) {
        int bit = (x >> j) & 1;
        if (t[v].next[bit] == -1) {
            t[v].next[bit] = sz;
            sz++;
        }
        v = t[v].next[bit];
        t[v].path++;
    }
}
void del(int x) {
    int v = 0;
    for (int j = 29; j >= 0; j--) {
        int bit = (x >> j) & 1;
        v = t[v].next[bit];
        t[v].path--;
    }
}
map <int, int > idx;
pair < int, int > need(int x) {
    int ans = 0;
    int ret = 0;
    int v = 0;
    for (int j = 29; j >= 0; j--) {
        int bit = (x >> j) & 1;
        if (t[t[v].next[bit]].path != 0) {
            v = t[v].next[bit];
            ret |= (bit << j);
        }
        else {
            v = t[v].next[1 ^ bit];
            ans |= 1 << j;
            ret |= ((bit ^ 1) << j);
        }
    }
    int num = idx[ret];
    //cout << ans << " " << ret << " " << num << endl;
    return make_pair(ans, num);
}
void solve() {
    for (int i = 0; i < n; i++) {
        if (comp[i].size() == 0) continue;
        for (int j = 0; j < comp[i].size(); j++) {
            del(comp[i][j]);
        }
        int curans = (1 << 30) + 10;
        int curcomp = -1;
        for (int j = 0; j < comp[i].size(); j++) {
            auto s = need(comp[i][j]);
            if (curans > s.first) {
                curans = s.first;
                curcomp = s.second;
            }
        }
        //cout << curcomp << endl;
        mi[i] = make_pair(curans, curcomp);
        for (int j = 0; j < comp[i].size(); j++) {
            add(comp[i][j]);
        }
    }
    for (int i = 0; i < n; i++) {
        if (comp[i].size() == 0) continue;
        int to = mi[i].second;
//        cout << to << endl;
        to = idx[a[to]];
//        cout << to << endl;
        if (comp[to].size() == 0 || i == to) continue;
        ans += mi[i].first;
//       if (comp[i].size() < comp[to].size())
            {
            for (int j = 0; j < comp[i].size(); j++) {
                comp[to].push_back(comp[i][j]);
                idx[comp[i][j]] = to;
            }
            comp[i].clear();
        } /*else {
            for (int j = 0; j < comp[to].size(); j++) {
                comp[i].push_back(comp[to][j]);
                idx[comp[to][j]] = i;
            }
            comp[to].clear();

        }*/
        //cout << "HUI" << endl;
    }
    number = 0;
    for (int i = 0; i < n; i++) {
        if (comp[i].size() != 0) number++;
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> b[i];
        //comp[i].push_back(a[i]);
    }
    sort(b, b + n);
    int cur = -1;
    for (int i = 0; i < n; i++) {
        if (b[i] == cur) {
            continue;
        }
        else {
            cur = b[i];
            a.push_back(b[i]);
        }
    }
    n = a.size();
    for (int i = 0; i < n; i++) {
        comp[i].push_back(a[i]);
    }
    number = n;
    int sz = 1;
    for (int i = 0; i < n; i++) {
        add(a[i]);
        idx[a[i]] = i;

    }
    while (number != 1) {
        //cout << number << endl;
        solve();
    }
    cout << ans;
    return 0;
}