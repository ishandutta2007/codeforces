#define first f
#define second s
#include <algorithm>
#include <iostream>
#include <vector>
#include <set>
#define all(a) begin(a), end(a)
#define pb push_back

using namespace std;

const int dog = 2000000001;
int n, m, a, b, c, o, ans;
vector<pair<int, int>> v;
multiset<int> cop;

int main()
{
    cin.tie(0), ios::sync_with_stdio(0);
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
        cin >> a, v.pb({a, dog});
    for (int i = 0; i < m; ++i)
        cin >> a >> b, v.pb({a - b, a + b});
    sort(all(v));
    for (auto i: v)
    {
        while (!cop.empty() && *cop.begin() < i.f)
            cop.erase(cop.begin());
        if (i.s == dog)
            if (!cop.empty())
                cop.erase(cop.begin()), ++ans;
        else;else
            cop.insert(i.s);
    }
    cout << ans;
    return 0;
}