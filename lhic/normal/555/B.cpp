#include <iostream>
#include <fstream>
#include <set>
#include <map>
#include <string>
#include <vector>
#include <bitset>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <cassert>
#include <queue>


typedef long long ll;
typedef long double ld;

using namespace std;

const int MAXN = 210000;

set<pair<ll, int> > ss;
pair<ll, int> a[MAXN];
ll l2[MAXN];
ll r2[MAXN];
ll l[MAXN];
ll r[MAXN];
int n, m;

int ans[MAXN];


vector<pair<ll, int> > ev;

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i) {
        scanf("%lld%lld", &l2[i], &r2[i]);
    }
    for (int i = 0; i < n - 1; ++i) {
        l[i] = l2[i + 1] - r2[i];
        r[i] = r2[i + 1] - l2[i];
        ev.push_back(make_pair(l[i], i));
    }
    --n;
    sort(ev.begin(), ev.end());
    for (int i = 0; i < m; ++i)
        scanf("%lld", &a[i].first), a[i].second = i;
    sort(a, a + m);
    int now = 0;
    for (int i = 0; i < m; ++i) {
        while (now < (int)ev.size() && ev[now].first <= a[i].first) {
            ss.insert(make_pair(r[ev[now].second], ev[now].second));
            ++now;
        }
        if (!ss.empty() && ss.begin()->first >= a[i].first) {
            ans[ss.begin()->second] = a[i].second + 1;
            ss.erase(ss.begin());
        }
    }
    if (!ss.empty() || now!= ev.size() ) {
        printf("No\n");
    }
    else {
        printf("Yes\n");
        for (int i = 0; i < n; ++i)
            printf("%d ", ans[i]);
    }
    return 0;
}