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

const int N = 1e5 + 5;

int n, p;
int t[N];
ll res[N];

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> p;

    set<tuple<ll, int, int>> events;

    for (int i = 1; i <= n; i++) {
         cin >> t[i];
         events.insert({t[i], 0, i});
    }

    queue<int> que;
    set<int> wait, empt;

    while (!events.empty()) {
        ll time;
        int type, id;
        tie(time, type, id) = *events.begin();
        events.erase(events.begin());
        if (type == 0) {
            if (!empt.empty() && *empt.begin() < id) {
                wait.insert(id);
            } else {
                empt.insert(id);
                if (que.empty()) {
                    events.insert({time + p, 1, id});
                }
                que.push(id);
            }
        } else {
            res[id] = time;
            empt.erase(id);
            que.pop();
            if (!que.empty()) {
                int j = que.front();
                events.insert({time + p, 1, j});
            }
            if (!wait.empty()) {
                int j = *wait.begin();
                if (empt.empty() || j < *empt.begin()) {
                    wait.erase(j);
                    empt.insert(j);
                    if (que.empty()) {
                        events.insert({time + p, 1, j});
                    }
                    que.push(j);
                }
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << res[i] << " ";
    }
    cout << "\n";

    return 0;
}