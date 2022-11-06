#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define all(x) (x).begin(), (x).end()
using namespace std;

const int N = 5e5 + 5;

int n, a[N];
int qq;
int t[4*N];

void upd(int v, int vl, int vr, int pos, int val) {
    if (vl == vr) {
        t[v] = val;
        return;
    }
    int vm = (vl + vr) / 2;
    if (pos <= vm)
        upd(v + v, vl, vm, pos, val);
    else
        upd(v + v + 1, vm + 1, vr, pos, val);
    t[v] = max(t[v + v], t[v + v + 1]);
}

int get(int v, int vl, int vr, int l, int r) {
    if (l > r)
        return 0;
    if (vl == l && vr == r)
        return t[v];
    int vm = (vl + vr) / 2;
    return max(get(v + v, vl, vm, l, min(r, vm)), get(v + v + 1, vm + 1, vr,  max(l, vm + 1), r));
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> qq;
    while (qq--) {
        cin >> n;
        for (int i = 0; i <= 4 * n; i++)
            t[i] = 0;
        set<int> pos;
        vector<pair<int, int> > q;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            pos.insert(i);
            q.pb({a[i], i});
        }
        sort(all(q));
        for (auto [x, p] : q) {
            int dp = get(1, 1, n, 1, p - 1) + 1;
            pos.erase(p);
            //cout << '?' << p << endl;
            if (pos.size() != 0) {
                auto it = pos.lower_bound(p);
                if (it != pos.begin()) {
                    it--;
                    dp = max(dp, get(1, 1, n, 1, (*it) - 1) + 2);
                    //cout << '!' << get(1, 1 ,n , 1, (*it) - 1) << endl;
                }
            }
            upd(1, 1, n, p, dp);
        }
        cout << get(1, 1, n, 1, n) << "\n";
    }


    return 0;
}