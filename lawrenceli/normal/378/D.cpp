#include <cstdio>
#include <iostream>
#include <algorithm>
#include <ios>
#include <queue>

using namespace std;

#define fi first
#define se second

struct data {
    int b, c, id;
    data() {}
    data(int b, int c, int id) : b(b), c(c), id(id) {}
};

typedef long long ll;
typedef pair<int, int> pii;

const int MAXN = 100100;

int n, m, s, ans[MAXN];
pii bug[MAXN];
data arr[MAXN];

bool cmp(data d1, data d2) {
    return d1.b > d2.b;
}

priority_queue<pii> pq;

bool pos(int mid) {
    while (!pq.empty()) pq.pop();
    ll sum = 0;
    int j = 0;
    for (int i=m-1; i>=0; ) {
        while (j < n && arr[j].b >= bug[i].fi) {
            pq.push(pii(-arr[j].c, arr[j].id));
            j++;
        }
        if (pq.empty()) return 0;
        sum += -pq.top().fi; pq.pop();
        i -= mid;
    }
    return sum <= s;
}

int main() {
    ios :: sync_with_stdio(false);

    if (fopen("input.txt", "r")) {
        freopen("input.txt", "r", stdin);
    }

    cin >> n >> m >> s;
    for (int i=0; i<m; i++) {
        cin >> bug[i].fi;
        bug[i].se = i;
    }
    for (int i=0; i<n; i++) cin >> arr[i].b;
    for (int i=0; i<n; i++) cin >> arr[i].c;
    for (int i=0; i<n; i++) arr[i].id = i+1;

    sort(bug, bug + m);
    sort(arr, arr + n, cmp);

    int lo = 1, hi = MAXN;

    while (lo < hi) {
        int mid = (lo + hi) / 2;
        if (pos(mid)) hi = mid;
        else lo = mid+1;
    }

    if (lo == MAXN) cout << "NO" << endl;
    else {
        cout << "YES" << endl;
        while (!pq.empty()) pq.pop();
        int j = 0;
        for (int i=m-1; i>=0; ) {
            while (j < n && arr[j].b >= bug[i].fi) {
                pq.push(pii(-arr[j].c, arr[j].id));
                j++;
            }
            pii p = pq.top(); pq.pop();
            for (int k=0; k<lo && i-k >= 0; k++) {
                ans[bug[i-k].se] = p.se;
            }
            i -= lo;
        }

        for (int i=0; i<m; i++) cout << ans[i] << ' ';
        cout << endl;
    }

    return 0;
}