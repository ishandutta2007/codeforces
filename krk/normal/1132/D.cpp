#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair <ll, int> lli;

const int Maxn = 200005;
const ll lim = 1000000000000000000ll;

int n, k;
ll a[Maxn];
int b[Maxn];
ll nxt[Maxn];
vector <int> S[Maxn];

bool Check(ll x)
{
    for (int i = 1; i <= k - 1; i++)
        S[i].clear();
    for (int i = 1; i <= n; i++) {
        ll dv = a[i] / b[i] + 1;
        if (dv <= k - 1) S[dv].push_back(i);
        nxt[i] = a[i] - ll(b[i]) * dv;
    }
    int has = 0;
    for (int i = 1; i <= k - 1; i++) {
        has++;
        while (!S[i].empty()) {
            int ind = S[i].back(); S[i].pop_back();
            while (has > 0 && nxt[ind] < 0) {
                has--; nxt[ind] += x;
            }
            if (nxt[ind] < 0) return false;
            ll dv = nxt[ind] / b[ind] + 1;
            if (i + dv <= k - 1) S[i + dv].push_back(ind);
            nxt[ind] = nxt[ind] - ll(b[ind]) * dv;
        }
    }
    return true;
}

int main()
{
    scanf("%d %d", &n, &k);
    for (int i = 1; i <= n; i++)
        scanf("%I64d", &a[i]);
    for (int i = 1; i <= n; i++)
        scanf("%d", &b[i]);
    ll lef = 0, rig = lim;
    while (lef <= rig) {
        ll mid = lef + rig >> 1ll;
        if (Check(mid)) rig = mid - 1;
        else lef = mid + 1;
    }
    ll res = rig + 1;
    if (res > lim) cout << "-1" << endl;
    else cout << res << endl;
    return 0;
}