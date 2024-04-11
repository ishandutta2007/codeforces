#include <bits/stdc++.h>

using namespace std;

const int maxn = 1000005;
int n;
int a[maxn], b[maxn], c[maxn], d[maxn];
int ord[maxn];
map <int, int> mp;

void no(void) {
    cout << "NO" << endl;
    exit(0);
}

void up(int i) {
    if (mp.find(c[i]) == mp.end()) mp[c[i]] = 0;
    mp[c[i]] = max(mp[c[i]], d[i]);
    while (true) {
        auto it = mp.upper_bound(c[i]);
        if (it == mp.end() || it->second > d[i]) break;
        mp.erase(it);
    }
}

void gogo(void) {
    mp.clear();
    mp[0] = 0;
    iota(ord + 1, ord + n + 1, 1);
    sort(ord + 1, ord + n + 1, [](int x, int y) { return a[x] < a[y]; });
    priority_queue <pair <int, int> > q;

    for (int i = 1; i <= n; ++i) {
        int x = ord[i];
        while (q.size()) {
            int y = q.top().second;
            assert(q.top().first == -b[y]);
            if (b[y] < a[x]) up(y);
            else break;
            q.pop();
        }
        auto it = mp.lower_bound(c[x]);
        --it;
        if (it->second >= c[x]) no();
        auto jt = mp.upper_bound(d[x]);
        --jt;
        if (jt->first >= c[x]) no();
        q.push({-b[x], x});
    }
}

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i] >> b[i] >> c[i] >> d[i];
    gogo();
    for (int i = 1; i <= n; ++i) swap(a[i], c[i]), swap(b[i], d[i]);
    gogo();
    cout << "YES" << endl;
    return 0;
}