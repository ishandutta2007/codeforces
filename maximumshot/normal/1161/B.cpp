#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef long long ll;

const int inf = 1e9;
const ll inf64 = 1e18;

const int N = 2e5 + 5;

int n, m;
pii b[N];
pii b2[N];

int pr[N];

int main() {

    fill(pr, pr + N, 1);

    pr[0] = pr[1] = 0;

    for (int i = 2; i * i < N; i++) {
        if (!pr[i]) continue;
        for (int j = i * i; j < N; j += i) {
            pr[j] = 0;
        }
    }

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        if (u > v) swap(u, v);
        u--, v--;
        b[i] = {u, v};
    }



    sort(b, b + m);

    vector<int> candidate;

    for (int k = 2; k <= n; k++) {
        if (pr[k] && n % k == 0) {
            candidate.push_back(n / k);
        }
    }

    for (int k : candidate) {
        for (int i = 0; i < m; i++) {
            b2[i] = {
                    (b[i].first + k) % n,
                    (b[i].second + k) % n
            };
            if (b2[i].first > b2[i].second) {
                swap(b2[i].first, b2[i].second);
            }
        }
        sort(b2, b2 + m);
        int ok = 1;
        for (int i = 0; i < m; i++) {
            if (b[i] != b2[i]) {
                ok = 0;
                break;
            }
        }
        if (ok) {
            cout << "Yes\n";
            return 0;
        }
    }

    cout << "No\n";

    return 0;
}