#include <bits/stdc++.h>

using namespace std;

typedef pair <pair <int, int>, int> dat;
int N, Q;
int p[200005];
int l[200005], d[200005], r[200005], u[200005];
vector <dat> lquery[200005], rquery[200005];
long long ans[200005];
int t[200005];

inline long long c2(long long n) { return n * (n - 1) / 2; }

void upd(int i) { for (; i <= N; i += i & -i) ++t[i]; }
int get(int i) { int ret = 0; for (; i; i -= i & -i) ret += t[i]; return ret; }

int main(void) {
    ios_base::sync_with_stdio(0);
    cin >> N >> Q;
    for (int i = 1; i <= N; ++i) cin >> p[i];
    for (int i = 1; i <= Q; ++i) {
        cin >> l[i] >> d[i] >> r[i] >> u[i];
        lquery[l[i]].push_back(make_pair(make_pair(d[i] - 1, u[i]), i));
        rquery[r[i]].push_back(make_pair(make_pair(d[i] - 1, u[i]), i));
    }
    for (int i = 1; i <= Q; ++i) ans[i] = c2(N) - c2(l[i] - 1) - c2(N - r[i]) - c2(d[i] - 1) - c2(N - u[i]);
    for (int i = 1; i <= N; ++i) {
        for (auto x: lquery[i]) {
            ans[x.second] += c2(get(x.first.first));
            ans[x.second] += c2(i - 1 - get(x.first.second));
        }
        upd(p[i]);
    }
    for (int i = 1; i <= N; ++i) t[i] = 0;
    for (int i = N; i >= 1; --i) {
        for (auto x: rquery[i]) {
            ans[x.second] += c2(get(x.first.first));
            ans[x.second] += c2(N - i - get(x.first.second));
        }
        upd(p[i]);
    }
    for (int i = 1; i <= Q; ++i) cout << ans[i] << '\n';
}