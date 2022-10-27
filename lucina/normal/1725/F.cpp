#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int N = 1e5 + 10;
const int INF = 1e9;

pii inv[N];
int ans[35];
int n;
    
void find_ans(int id, int val) {
    vector<pii> event;
    for (int i = 1; i <= n; i++) {
        if ( inv[i].second - inv[i].first + 1 >= val) {
            ans[id] ++;
            continue;
        }
        int l = inv[i].first % val, r = inv[i].second % val;
        if (l <= r) {
            event.push_back(make_pair(l, 1));
            if (r != val -1) event.push_back(make_pair(r + 1, -1));
        } else {
            event.push_back(make_pair(l, 1));
            event.push_back(make_pair(0, 1));
            event.push_back(make_pair(r + 1, -1));
        }
    }
    sort(event.begin(), event.end());
    int pt = 0, sum = 0, ma = 0;
    for (; pt < event.size();) {
        int cur = event[pt].first;
        for (; pt < event.size() && event[pt].first == cur; pt ++) {
            sum += event[pt].second;
        }
        ma = max(ma, sum);
    }
    ans[id] += ma;
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d %d", &inv[i].first, &inv[i].second);
    }
    for (int i = 0, val = 1; val <= INF; i ++, val <<= 1) {
        find_ans(i, val);  
    }   
    int q;
    scanf("%d", &q);
    while (q--) {
        int x, id = 0;
        scanf("%d", &x);
        for(; (x & 1) == 0; id ++, x >>= 1);
        printf("%d\n", ans[id]);
    }
}