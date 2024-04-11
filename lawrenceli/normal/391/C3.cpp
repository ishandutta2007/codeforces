#include <cstdio>
#include <iostream>
#include <algorithm>
#include <ios>
#include <vector>
#include <queue>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int MAXN = 200100;
const ll INF = 1e15;

int n, k, p[MAXN], e[MAXN];
int ind[MAXN], pre[MAXN];
bool used[MAXN];
vector<int> num[MAXN];
ll ans = INF;

bool cmp(int a, int b) {
    return e[a] < e[b];
}

priority_queue<pii> pq;

int main() {
    ios :: sync_with_stdio(0);

    if (fopen("input.txt", "r")) {
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    }

    cin >> n >> k;
    for (int i=0; i<n; i++) {
        cin >> p[i] >> e[i];
        num[p[i]].push_back(i);
    }

    pre[0] = num[0].size();
    for (int i=1; i<MAXN; i++)
        pre[i] = pre[i-1] + num[i].size();

    for (int i=0; i<n; i++) ind[i] = i;
    sort(ind, ind + n, cmp);

    ll cur = 0;
    for (int i=0; i<=n; i++) {
        int beat = 0;
        if (i > 1) beat = pre[i-2];
        vector<int> v;
        for (int j=i-1; j<=i; j++) {
            if (j < 0) continue;
            for (int k=0; k<num[j].size(); k++) {
                if (!used[num[j][k]])
                    v.push_back(e[num[j][k]]);
                else
                    beat ++;
            }
        }
        sort(v.begin(), v.end());
        vector<pii> popped;
        ll cur2 = cur;
        int beat2 = beat;
        if (beat2 >= n+1-k)
            ans = min(ans, cur2);
        for (int j=0; j<v.size() && beat2 < n+1-k; j++) {
            while (!pq.empty()) {
                pii p = pq.top();
                pq.pop(); popped.push_back(p);
                if (p.second == i-1 || p.second == i) continue;
                cur2 = cur2 + v[j] - p.first;
                beat2 ++;
                break;
            }
            if (beat2 >= n+1-k) {
                ans = min(ans, cur2);
                break;
            }
        }

        for (int j=0; j<popped.size(); j++)
            pq.push(popped[j]);

        if (i == n) continue;
        cur += e[ind[i]];
        used[ind[i]] = 1;
        pq.push(pii(e[ind[i]], p[ind[i]]));
    }

    if (ans != INF) cout << ans << endl;
    else cout << -1 << endl;
    return 0;
}