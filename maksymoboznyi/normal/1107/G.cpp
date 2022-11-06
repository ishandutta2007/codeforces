#include <bits/stdc++.h>
#define pb push_back
#define int long long

using namespace std;

const long long M = 1e9 + 7;
const int N = 3e5 + 5;

int pl[N], pr[N], tp[4*N], s[N], ts[4*N], c[N], n, d[N], a;

int sum(int l, int r) {
    return a * (r - l + 1) - s[r] + s[l - 1];
}

void buildp(int v, int vl, int vr) {
    if (vl == vr) {
        tp[v] = a - c[vl];
        return;
    }
    int vm = (vl + vr) / 2;
    buildp(v + v, vl, vm);
    buildp(v + v + 1, vm + 1, vr);
    tp[v] = max(tp[v + v], sum(vl, vm) + tp[v + v + 1]);
}

void builds(int v, int vl, int vr) {
    if (vl == vr) {
        ts[v] = a - c[vl];
        return;
    }
    int vm = (vl + vr) / 2;
    builds(v + v, vl, vm);
    builds(v + v + 1, vm + 1, vr);
    ts[v] = max(ts[v + v + 1], sum(vm + 1, vr) + ts[v + v]);
}

int getp(int v, int vl, int vr, int l, int r) {
    if (l > r)
        return 0;
    if (vl == l && vr == r)
        return tp[v];
    int vm = (vl + vr) / 2;
    if (r <= vm)
        return getp(v + v, vl, vm, l, r);
    if (l > vm)
        return getp(v + v + 1, vm + 1, vr, l, r);
    int x = getp(v + v, vl, vm, l, vm), y = getp(v + v + 1, vm + 1, vr, vm + 1, r);
    return max(x, sum(l, vm) + y);
}

int gets(int v, int vl, int vr, int l, int r) {
    if (l > r)
        return 0;
   // cout << vl << ' ' << vr << ' ' << l << ' ' << r << endl;
    if (vl == l && vr == r)
        return ts[v];
    int vm = (vl + vr) / 2;
    if (r <= vm)
        return gets(v + v, vl, vm, l, r);
    if (l > vm)
        return gets(v + v + 1, vm + 1, vr, l, r);
    int x = gets(v + v, vl, vm, l, vm), y = gets(v + v + 1, vm + 1, vr, vm + 1, r);
    return max(y, sum(vm + 1, r) + x);
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> a;
    for (int i = 1; i <= n; i++)
        cin >> d[i] >> c[i], s[i] = s[i - 1] + c[i];
    buildp(1, 1, n);
    builds(1, 1, n);
    int ans = 0;
    for (int i = 1; i <= n; i++)
        ans = max(ans, a - c[i]);
    stack<pair<int, int> > q;
    pl[1] = 0;
    q.push({1, abs(d[2] - d[1])});
    //cout << q.top().second << endl;
    for (int i = 3; i <= n; i++) {
        while (q.size() > 0 && q.top().second <= abs(d[i] - d[i - 1]))
            q.pop();
        //cout << '*' << q.size() << ' ' << i- 1<<' ' << q.top().first<<endl;
        if (q.size() == 0)
            pl[i - 1] = 0;
        else
            pl[i - 1] = q.top().first;
        q.push({i - 1, abs(d[i] - d[i - 1])});
    }
    pr[n - 1] = n;
    while (q.size() > 0)
        q.pop();
    q.push({n - 1, abs(d[n] - d[n - 1])});
    for (int i = n - 2; i >= 1; i--) {
        while (q.size() > 0 && q.top().second <= abs(d[i + 1] - d[i]))
            q.pop();
        if (q.size() == 0)
            pr[i] = n;
        else
            pr[i] = q.top().first;
        q.push({i, abs(d[i + 1] - d[i])});
    }
    for (int i = 1; i < n; i++)
    {
        //cout << pl[i] + 1 << ' ' << i << ' ' << gets(1, 1, n, pl[i] + 1, i) << endl;
        ans = max(ans, -(d[i + 1] - d[i]) * (d[i + 1] - d[i]) + gets(1, 1, n, pl[i] + 1, i) + getp(1, 1, n, i + 1, pr[i]));
    }
    cout << ans << endl;
    return 0;
}