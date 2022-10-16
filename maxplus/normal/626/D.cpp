#define push_back pb
#define first f
#define second s
#include <algorithm>
#include <iostream>
#include <vector>
#include <map>

using namespace std;

const int N = 2001;
int n, a[N];
map<int, int> d;
vector<pair<int, int>> sd;

int main()
{
    cin >> n;
//    if (n == 2)
//        return cout << 0, 0;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    sort(a, a + n);
    for (int i = 0; i < n; ++i)
    for (int j = 0; j < i; ++j)
        d[a[i] - a[j]]++;
    for (auto i: d)
        sd.pb(i);
    for (int i = 1; i < sd.size(); ++i)
        sd[i].s += sd[i - 1].s;
    long double ans = 0;
    cout.precision(30);
    cout << fixed;
    for (int i = 0; i < sd.size(); ++i)
    for (int j = 0; j <= i; ++j)
    {
        auto it = upper_bound(sd.begin() + i, sd.end(), make_pair(sd[i].f + sd[j].f, 1000000000));
        int64_t am1 = i? sd[i].s - sd[i - 1].s: sd[i].s;
        int64_t am2 = j? sd[j].s - sd[j - 1].s: sd[j].s;
        ans += (sd.back().s - prev(it)->s) * am1 * am2 * (1 - 0.5 * (i == j));
    }
    ans *= 2;
    ans /= n * (n - 1) / 2;
    ans /= n * (n - 1) / 2;
    ans /= n * (n - 1) / 2;
    cout << ans;
    return 0;
}