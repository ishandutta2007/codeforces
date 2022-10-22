#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;

const int inf = 1e9;
const ll inf64 = 1e18;

const int N = 4e5 + 5;

int n, m;
int k[N];
int cnt[N];
int used[N];
pii events[N];
int last[N];
vector<int> ty[N];
ll tot[N];

bool check(int max_day) {
    fill(used + 1, used + n + 1, 0);
    fill(cnt + 1, cnt + n + 1, 0);
    fill(tot + 1, tot + max_day + 1, 0);
    for (int i = m - 1; i >= 0; i--) {
        int dd, tt;
        tie(dd, tt) = events[i];
        if (dd > max_day) continue;
        if (used[tt]) continue;
        used[tt] = 1;
        last[tt] = dd;
        tot[dd] += k[tt];
    }
    ll have = 0;
    ll cost = 0;
    for (int dd = 1; dd <= max_day; dd++) {
        have++;
        ll add = min(have, tot[dd]);
        have -= add;
        cost += add;
    }
    ll ost = 0;
    for (int i = 1; i <= n; i++) {
        ost += k[i];
    }
    return (ost - cost) * 2 <= have;
}

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        cin >> k[i];
    }

    for (int i = 0; i < m; i++) {
        int dd, tt;
        cin >> dd >> tt;
        events[i] = {dd, tt};
        ty[dd].push_back(tt);
    }

    sort(events, events + m);

    int bl = 0;
    int br = N - 2;
    int bm;

    while (br - bl > 1) {
        bm = (bl + br) / 2;
        if (check(bm)) {
            br = bm;
        } else {
            bl = bm;
        }
    }

    cout << br << "\n";

    return 0;
}