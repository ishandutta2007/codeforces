#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int maxN = 5 * (int)1e5 + 10;
vector < int > g[maxN];
ll c[maxN];
int n, m, k;
int sz = 1;
const int mod = (int)1e9 + 7;
int sum(int a, int b) {
    int s = a + b;
    if (s >= mod) s -= mod;
    return s;
}
int sub(int a, int b) {
    int s = a - b;
    if (s < 0) s += mod;
    return s;
}
int mult(int a, int b) {
    return (1LL * a * b) % mod;
}
vector < pair < int, int > > edges[maxN];
int pw[maxN];
int p[maxN];
vector < int > roll_back;
int cnt = 0;
int find(int a) {
    if (a == p[a]) return a;
    p[a] = find(p[a]);
    return p[a];
}
int cmp;
void unite(int a, int b) {
    a = find(a);
    b = find(b);
    if (a == b) return;
    /*if (rand() & 1) {
        swap(a, b);
    }*/
    cnt++;
    cmp--;
    roll_back.push_back(a);
    p[a] = b;
    cnt++;
}
void go_back() {
    while (!roll_back.empty()) {
        p[roll_back.back()] = roll_back.back();
        roll_back.pop_back();
    }
    cmp = n;
}
int main() {
    srand(123 + 23123123 + 123123 - 123123);
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) p[i] = i;
    cmp = n;
    pw[0] = 1;
    for (int i = 1; i < maxN; i++) pw[i] = mult(pw[i - 1], 2);
    for (int i = 1; i <= n; i++) cin >> c[i];
    vector < pair < ll, pair < int, int > > > all;
    for (int i = 1; i <= m; i++) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
        all.emplace_back(make_pair(c[a] ^ c[b], make_pair(a, b)));
    }
    sort(all.begin(), all.end());
    int i = 0;
    while (i < all.size()) {
        int j = i;
        while ((j < all.size()) && all[j].first == all[i].first) j++; j--;
        for (int k = i; k <= j; k++) edges[sz].push_back(all[k].second);
        sz++;
        i = j + 1;
    }
    sz--;
    int ans = mult(pw[n], sub(pw[k], sz));
    for (int i = 1; i <= sz; i++) {
        for (auto t : edges[i]) {
            //cout << i << " " << t.first << " " << t.second << endl;
            unite(t.first, t.second);
        }
        ans = sum(ans, pw[cmp]);
        go_back();
    }
    cout << ans;
    return 0;
}