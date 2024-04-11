#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair <ll, ll> llll;

const int Maxn = 100005;

int n;
llll ba[Maxn];

bool Get(ll x)
{
    ll memx = x;
    int i = n - 1;
    while (i >= 0 && ba[i].second <= memx) { memx -= ba[i].second; i--; }
    for (int j = 0; j <= i; j++)
        if (x >= 100000000000000000ll) return true;
        else if (ba[j].first <= x) x += ba[j].second;
        else return false;
    return true;
}

int main()
{
    scanf("%d", &n);
    ll sum = 0;
    for (int i = 0; i < n; i++) {
        scanf("%I64d %I64d", &ba[i].second, &ba[i].first);
        sum += ba[i].second;
    }
    sort(ba, ba + n);
    ll lef = 0, rig = 1000000000000000ll;
    while (lef <= rig) {
        ll mid = lef + rig >> 1ll;
        if (Get(mid)) rig = mid - 1;
        else lef = mid + 1;
    }
    cout << lef * 2 + max(sum - lef, 0ll) << endl;
    return 0;
}