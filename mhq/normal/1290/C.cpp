#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
const int maxN = 3 * (int)1e5 + 100;
int n, k;
int tp[maxN];
vector < int > who[maxN];
int TOT = 0;
pair < int, int > p[maxN];
int cnt0[maxN];
int cnt1[maxN];
pair < int, int > get(int x) {
    if (x == p[x].first) return {x, 0};
    auto it = get(p[x].first);
    p[x] = make_pair(it.first, it.second ^ p[x].second);
    return p[x];
}
mt19937 rnd(228);
int calc(int a) {
    if (a == 0) return cnt0[a];
    return min(cnt0[a], cnt1[a]);
}
void unite(int a, int b, int edge) {
    auto it1 = get(a);
    auto it2 = get(b);
    if (it1.first == it2.first) return;
    if (it2.first == 0 || (it1.first != 0 && (rnd() & 1))) {
        swap(it1.first, it2.first);
        swap(a, b);
    }
    TOT -= calc(it1.first);
    TOT -= calc(it2.first);
    p[it2.first] = {it1.first, ((it1.second ^ it2.second) ^ edge)};
    if (p[it2.first].second == 0) {
        cnt0[it1.first] += cnt0[it2.first];
        cnt1[it1.first] += cnt1[it2.first];
    }
    else {
        cnt0[it1.first] += cnt1[it2.first];
        cnt1[it1.first] += cnt0[it2.first];
    }
    TOT += calc(it1.first);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        char c;
        cin >> c;
        tp[i] = c - '0';
    }
    for (int i = 1; i <= k; i++) {
        int cnt;
        cin >> cnt;
        for (int j = 1; j <= cnt; j++) {
            int x;
            cin >> x;
            who[x].push_back(i);
        }
    }
    for (int i = 0; i <= k; i++) {
        p[i] = {i, 0};
        cnt0[i] = 0;
        cnt1[i] = 1;
    }
    for (int i = 1; i <= n; i++) {
        if (who[i].size() == 1) {
            unite(who[i][0], 0, tp[i] ^ 1);
        }
        else if (who[i].size() == 2) {
            unite(who[i][1], who[i][0], tp[i] ^ 1);
        }
        cout << TOT << '\n';
    }
    return 0;
}