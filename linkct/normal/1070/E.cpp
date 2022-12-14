#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int MAXN = 200003;
typedef long long LL;
LL t;
int n, m;
int a[MAXN];
vector<LL> b;
LL haha(LL d, int &num)
{
    num = 0;
    LL tm = 0;
    LL sm = 0;
    int ct = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] > d)
            continue;
        if (ct == m) {
            tm += sm;
            ct = 0;
            sm = 0;
        }
        if (tm + a[i] <= t)
            ++num;
        ++ct;
        tm += a[i];
        sm += a[i];
    }
    return tm;
}
void run()
{
    cin >> n >> m >> t;
    b.clear();
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        b.push_back(a[i]);
    }
    b.push_back(t + 1);
    sort(b.begin(), b.end());
    b.erase(unique(b.begin(), b.end()), b.end());
    LL l = 0, r = t + 1;
    while (l + 1 != r) {
        LL mid = (l + r) / 2;
        int f;
        if (haha(mid, f) <= t)
            l = mid;
        else
            r = mid;
    }
    int ans1, ans2;
    haha(l, ans1);
    LL l2 = *upper_bound(b.begin(), b.end(), l);
    l2 = min(l2, t);
    haha(l2, ans2);
    LL ans, d;
    if (ans1 > ans2) {
        ans = ans1;
        d = l;
    }
    else {
        ans = ans2;
        d = l2;
    }
    cout << ans << ' ' << d << endl;
}
int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
        run();
    return 0;
}