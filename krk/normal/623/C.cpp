#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair <int, int> ii;

const int Maxn = 100005;
const int Inf = 1000000000;

int n;
int X[Maxn], Y[Maxn];
vector <int> un;
vector <int> has[Maxn];
ii L[Maxn], R[Maxn];

ii Get(const vector <int> &V)
{
    ii res = ii(0, 0);
    for (int i = 0; i < V.size(); i++) {
        res.first = min(res.first, V[i]);
        res.second = max(res.second, V[i]);
    }
    return res;
}

bool solveTop(ll x)
{
    int pnt = 0;
    for (int i = int(un.size()) - 1; i >= 0 && un[i] >= 0; i--)
        if (ll(un[i]) * un[i] <= x) {
            while (pnt < i && un[pnt] <= 0 && (ll(un[i] - un[pnt]) * (un[i] - un[pnt]) > x || -un[pnt] > un[i]))
                pnt++;
            while (pnt > 0 && ll(un[i] - un[pnt - 1]) * (un[i] - un[pnt - 1]) <= x && -un[pnt - 1] <= un[i])
                pnt--;
            ll lef = min(L[pnt].first, R[i].first);
            ll rig = max(L[pnt].second, R[i].second);
            if (max(lef * lef, rig * rig) + ll(un[i]) * un[i] <= x && ll(rig - lef) * (rig - lef) <= x)
                return true;
        }
    return false;
}

bool solveBot(ll x)
{
    int pnt = int(un.size()) - 1;
    for (int i = 0; i < un.size() && un[i] <= 0; i++)
        if (ll(un[i]) * un[i] <= x) {
            while (pnt > i && un[pnt] >= 0 && (ll(un[i] - un[pnt]) * (un[i] - un[pnt]) > x || un[pnt] > -un[i]))
                pnt--;
            while (pnt + 1 < un.size() && ll(un[i] - un[pnt + 1]) * (un[i] - un[pnt + 1]) <= x && un[pnt + 1] <= -un[i])
                pnt++;
            ll lef = min(L[i].first, R[pnt].first);
            ll rig = max(L[i].second, R[pnt].second);
            if (max(lef * lef, rig * rig) + ll(un[i]) * un[i] <= x && ll(rig - lef) * (rig - lef) <= x)
                return true;
        }
    return false;
}

int main()
{
    scanf("%d", &n);
    int mnY = Inf, mxY = -Inf;
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &X[i], &Y[i]);
        un.push_back(X[i]);
        mnY = min(mnY, Y[i]);
        mxY = max(mxY, Y[i]);
    }
    sort(un.begin(), un.end()); un.erase(unique(un.begin(), un.end()), un.end());
    for (int i = 0; i < n; i++) {
        int ind = lower_bound(un.begin(), un.end(), X[i]) - un.begin();
        has[ind].push_back(Y[i]);
    }
    L[0] = ii(0, 0);
    for (int i = 0; i < un.size(); i++) {
        ii got = Get(has[i]);
        L[i + 1].first = min(L[i].first, got.first);
        L[i + 1].second = max(L[i].second, got.second);
    }
    R[int(un.size()) - 1] = ii(0, 0);
    for (int i = int(un.size()) - 1; i > 0; i--) {
        ii got = Get(has[i]);
        R[i - 1].first = min(R[i].first, got.first);
        R[i - 1].second = max(R[i].second, got.second);
    }
    ll best = min(ll(un.back() - un[0]) * (un.back() - un[0]), ll(mxY - mnY) * (mxY - mnY));
    ll l = 0, r = best - 1;
    while (l <= r) {
        ll m = l + r >> 1ll;
        if (solveTop(m) || solveBot(m)) r = m - 1;
        else l = m + 1;
    }
    cout << l << endl;
    return 0;
}