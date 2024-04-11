#include <bits/stdc++.h>
#define pb push_back
using namespace std;

const int N = 5e5 + 5;

struct query {
    int l, r, num;
};

int n, m, ans[N], a[N];
vector<query> q;
vector<int> ll[N], rr[N];

void add(vector<int> &b, int a) {
    for (int i = 0; i < b.size(); i++)
        if ((b[i] ^ a) < a)
            a ^= b[i];
    if (a != 0) {
        for (int i = 0; i < b.size(); i++)
            if ((b[i] ^ a) < b[i])
                b[i] ^= a;
        b.pb(a);

        sort(b.begin(), b.end());
    }
}

void merge(vector<int> &a, vector<int> l, vector<int> r) {
    a = l;
    for (int i = 0; i < r.size(); i++)
        add(a, r[i]);
}

void solve(vector<query> q, int tl, int tr) {
    //cout << tl <<' ' << tr << ' ' << q.size() << endl;
    if (q.size() == 0)
        return;
    int tm = (tl + tr) / 2;
    ll[tm].clear();
    add(ll[tm], a[tm]);
    for (int l = tm - 1; l >= tl; l--)
    {
        ll[l] = ll[l + 1];
        add(ll[l], a[l]);
       /* cout << '*' << l << endl;
        for (int i = 0; i < ll[l].size(); i++)
            cout << ll[l][i] << ' ';
        cout << endl;
    */}
    rr[tm].clear();
    for (int r = tm + 1; r <= tr; r++) {
        rr[r] = rr[r - 1];
        add(rr[r], a[r]);
      /*  cout << '/' << r << endl;
        for (int i = 0; i < rr[r].size(); i++)
            cout << rr[r][i] << ' ';
        cout << endl;
    */}
    vector<query> ql, qr;
    for (int i = 0; i < q.size(); i++)
        if (q[i].r < tm)
            ql.pb(q[i]);
        else if (q[i].l > tm)
            qr.pb(q[i]);
        else
        {
            vector<int> a;
            merge(a, ll[q[i].l], rr[q[i].r]);
      /*      cout << '?' << q[i].l << ' ' << q[i].r << endl;
            for (int i = 0; i < a.size(); i++)
                cout << a[i] << ' ';
            cout << endl;
        */    int res = 0;
            for (int i = 0; i < a.size(); i++)
                if ((res ^ a[i]) > res)
                    res ^= a[i];
            ans[q[i].num] = res;
        }
    solve(ql, tl, tm);
    solve(qr, tm + 1, tr);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    cin >> m;
    for (int i = 1; i <= m; i++)
    {
        int a, b;
        cin >> a >> b;
        q.pb({a, b, i});
    }
    solve(q, 1, n);
    for (int i = 1; i <= m; i++)
        cout << ans[i] << "\n";
    return 0;
}