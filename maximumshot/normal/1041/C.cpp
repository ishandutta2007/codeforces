#ifdef debug
#define _GLIBCXX_DEBUG
#endif

#include <bits/stdc++.h>
//#include "optimization.h"

using namespace std;

#define vec vector
#define ALL(x) begin(x), end(x)

typedef unsigned int ui;
typedef long long ll;
typedef long double ld;
typedef pair< int, int > pii;
typedef pair< long long, long long > pll;

const int inf = 1e9;
const ll inf64 = 1e18;

const int N = 2e5 + 5;

int n, m, d;
int res[N];
pii a[N];
unordered_map< int, int > mp;

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);

    cin >> n >> m >> d;

    for(int i = 0;i < n;i++) {
        cin >> a[i].first;
        a[i].second = i;
    }

    sort(a, a + n);

    set< int > q;

    int cur = 0;

    for(int i = 0;i < n;i++) {
        int x = a[i].first;

        set< int > :: iterator fnd = q.lower_bound(x - d);
        if(fnd == q.begin()) {
            cur++;
            res[a[i].second] = cur;
            mp[x] = cur;
            q.insert(x);
            continue;
        }

        fnd--;

        int y = mp[*fnd];
        q.erase(fnd);

        q.insert(x);
        mp[x] = y;
        res[a[i].second] = y;
    }

    cout << cur << "\n";

    for(int i = 0;i < n;i++) {
        cout << res[i] << " ";
    }
    cout << "\n";

    return 0;
}