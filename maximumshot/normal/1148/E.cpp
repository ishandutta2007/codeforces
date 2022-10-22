#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;
typedef long double ld;

const int inf = 1e9;
const ll inf64 = 1e18;

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;

    cin >> n;

    vector<pii> s(n);
    vector<int> t(n);

    ll sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> s[i].first;
        s[i].second = i;
        sum += s[i].first;
    }

    for (int i = 0; i < n; i++) {
        cin >> t[i];
        sum -= t[i];
    }

    if (sum) {
        cout << "NO\n";
        return 0;
    }

    sort(s.begin(), s.end());
    sort(t.begin(), t.end());

    vector<tuple<int, int, int>> ans;

    vector<int> nxt(n, n), prv(n, -1);

    for (int i = 1; i < n; i++) {
        prv[i] = i > 0 && s[i - 1].first != t[i - 1] ? i - 1 : prv[i - 1];
    }

    for (int i = n - 2; i >= 0; i--) {
        nxt[i] = i + 1 < n && s[i + 1].first != t[i + 1] ? i + 1 : nxt[i + 1];
    }

    set<int> q;

    for (int i = 0; i < n; i++) {
        if (nxt[i] >= n) continue;
        if (s[i].first < t[i] && s[nxt[i]].first > t[nxt[i]]) {
            q.insert(i);
        }
    }

    while (!q.empty()) {
        int i = *q.begin();
        q.erase(q.begin());
        int j = nxt[i];
        q.erase(j);
        int d = min(t[i] - s[i].first, s[j].first - t[j]);
        ans.emplace_back(i, j, d);
        s[i].first += d;
        s[j].first -= d;
        int li = prv[i];
        int rj = nxt[j];
        set<int> candidates = {li, i, j, rj};
        if (s[i].first == t[i]) {
            if (prv[i] >= 0) nxt[prv[i]] = nxt[i];
            if (nxt[i] < n) prv[nxt[i]] = prv[i];
        }
        if (s[j].first == t[j]) {
            if (prv[j] >= 0) nxt[prv[j]] = nxt[j];
            if (nxt[j] < n) prv[nxt[j]] = prv[j];
        }
        for (int id : candidates) {
            if (id == -1 || id == n) continue;
            if (q.count(id)) continue;
            if (nxt[id] >= n) continue;
            if (s[id].first < t[id] && s[nxt[id]].first > t[nxt[id]]) {
                q.insert(id);
            }
        }
    }

    vector<int> aa, bb;

    for (int i = 0; i < n; i++) {
        aa.push_back(s[i].first);
        bb.push_back(t[i]);
    }

    sort(aa.begin(), aa.end());
    sort(bb.begin(), bb.end());

    if (aa != bb) {
        cout << "NO\n";
        return 0;
    }
    
    cout << "YES\n" << (int)ans.size() << "\n";

    for (auto it : ans) {
        int i, j, d;
        tie(i, j, d) = it;
        cout << s[i].second + 1 << " " << s[j].second + 1 << " " << d << "\n";
    }

    return 0;
}