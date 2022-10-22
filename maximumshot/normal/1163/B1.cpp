#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef long long ll;

const int inf = 1e9;
const ll inf64 = 1e18;

const int N = 1e5 + 5;

int n;
int cnt[N];

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    set<pii> q;

    int res = 0;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        q.erase({cnt[x], x});
        cnt[x]++;
        q.insert({cnt[x], x});
        if (q.begin()->first == 1) {
            pii tmp = *q.begin();
            q.erase(q.begin());
            if (q.empty() || q.begin()->first == (--q.end())->first) {
                res = i + 1;
            }
            q.insert(tmp);
        }
        pii tmp = *(--q.end());
        q.erase(--q.end());
        if (q.empty() || (q.begin()->first == (--q.end())->first && q.begin()->first == tmp.first - 1)) {
            res = i + 1;
        }
        q.insert(tmp);
    }

    cout << res << "\n";

    return 0;
}