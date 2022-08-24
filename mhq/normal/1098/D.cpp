#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int q;
const int maxN = 5 * (int)1e5 + 100;
vector < int > all;
vector < pair < int, int > > que;
ll f[maxN];
void add(int pos, int d) {
    while (pos < maxN) {
        f[pos] += d;
        pos = (pos | (pos - 1)) + 1;
    }
}
ll get(int r) {
    ll ans = 0;
    while (r > 0) {
        ans += f[r];
        r = (r & (r - 1));
    }
    return ans;
}
multiset < int > now;
set < int > inter;
int sz = 0;
void ans_que() {
    int cur = sz - inter.size();
    for (int x : inter) {
        int pos = lower_bound(all.begin(), all.end(), x) - all.begin() + 2;
        if (2 * get(pos - 1) >= x) cur++;
    }
    cout << cur << '\n';
}
void check_good(int x) {
    auto it = now.lower_bound(x);
    if (it == now.begin()) {
        inter.insert(x);
        return ;
    }
    --it;
    int s = 2 * (*it);
    if (s < x) {
        inter.insert(x);
    }
    else {
        inter.erase(x);
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    cin >> q;
    for (int i = 1; i <= q; i++) {
        char s;
        cin >> s;
        int x;
        cin >> x;
        all.push_back(x);
        if (s == '+') que.push_back(make_pair(1, x));
        else que.push_back(make_pair(-1, x));
    }
    sort(all.begin(), all.end());
    all.erase(unique(all.begin(), all.end()), all.end());
    set < int > need;
    for (auto t : que) {
        int x = t.second;
        sz += t.first;
        int ind = lower_bound(all.begin(), all.end(), x) - all.begin() + 2;
        add(ind, x * t.first);
        if (t.first == 1) {
            now.insert(x);
        }
        else {
            now.erase(now.find(x));
            inter.erase(x);
        }
        auto it = now.lower_bound(x);
        if (it != now.end()) {
            check_good(*it);
        }
        if (it != now.begin()) {
            check_good(*(--it));
        }
        it = now.upper_bound(x);
        if (it != now.end()) {
            check_good(*it);
        }
        if (it != now.begin()) {
            check_good(*(--it));
        }
        ans_que();
    }
    return 0;
}