#include <bits/stdc++.h>

using namespace std;

#define ALL(x) (x).begin(), (x).end()
#define vec vector

typedef unsigned int ui;
typedef long long ll;
typedef long double ld;
typedef pair< int, int > pii;
typedef pair< long long, long long > pll;

const int inf = 1e9;
const ll inf64 = 1e18;

const int N = 1e5 + 5;

int n;
int V[N];
int T[N];

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for(int i = 1;i <= n;i++) {
        cin >> V[i];
    }

    for(int i = 1;i <= n;i++) {
        cin >> T[i];
    }

    ll tot = 0;
    multiset< ll > q;

    for(int i = 1;i <= n;i++) {
        ll res = 0;
        q.insert(V[i] + tot);
        while(!q.empty() && *q.begin() - tot <= T[i]) {
            res += max(0ll, *q.begin() - tot);
            q.erase(q.begin());
        }
        res += 1ll * (int)q.size() * T[i];
        tot += T[i];
        cout << res << " ";
    }

    cout << "\n";

    return 0;
}