#include <bits/stdc++.h>
#define pb push_back
using namespace std;

const int N = 1e6 + 5;
const int magic = 3000;

struct query {
    int f, s, t, ind;
};

int cur_l, cur_r, cur_t, n, m, ans = 1, a[N], answer[N], is[N], kol_of_kol[N];
vector<query> q;
vector<int> all, al;
map <int, int> to;
vector<pair<int, int> > upd;

bool cmp(query a, query b) {
    if (a.t / magic != b.t / magic)
        return a.t / magic < b.t / magic;
    if (a.f / magic != b.f / magic)
        return a.f / magic < b.f / magic;
    return a.s < b.s;
}

void makeUpd(int ind) {
    int x = upd[ind].first;
    if (x < cur_l || x > cur_r) {
        int y = a[x];
        a[x] = upd[ind].second;
        upd[ind].second = y;
        return;
    }
    if (a[x] != 0)
        kol_of_kol[is[a[x]]]--;
    is[a[x]]--;
    if (a[x] != 0)
        kol_of_kol[is[a[x]]]++;
    int y = a[x];
    a[x] = upd[ind].second;
    if (a[x] != 0)
        kol_of_kol[is[a[x]]]--;
    is[a[x]]++;
    if (a[x] != 0)
        kol_of_kol[is[a[x]]]++;
    upd[ind].second = y;
}

void makePos(int ind) {
    if (a[ind] != 0)
        kol_of_kol[is[a[ind]]]--;
    is[a[ind]]++;
    if (a[ind] != 0)
        kol_of_kol[is[a[ind]]]++;
}

void delPos(int ind) {
    if (a[ind] != 0)
        kol_of_kol[is[a[ind]]]--;
    is[a[ind]]--;
    if (a[ind] != 0)
        kol_of_kol[is[a[ind]]]++;
}

int getAns() {
    for (int i = 1; i <= 1000000; i++)
        if (kol_of_kol[i] == 0)
            return i;
}

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        all.pb(a[i]);
    }
    int x = 0;
    upd.pb({-1, -1});
    for (int i = 1; i <= m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        if (a == 2)
            all.pb(c), x++;
        if (a == 1)
            q.pb({b, c, x, i});
        else
            upd.pb({b, c});
        answer[i] = -1;
    }

    is[0] = 1000000000;

    sort(all.begin(), all.end());
    al.pb(all[0]);
    for (int i = 1; i < all.size(); i++)
        if (all[i] != all[i - 1])
            al.pb(all[i]);
    all = al;
    for (int i = 1; i <= n; i++)
    {
        int pos = lower_bound(all.begin(), all.end(), a[i]) - all.begin()+1;
        a[i] = pos;
    }
    for (int i = 1; i < upd.size(); i++) {
        int pos = lower_bound(all.begin(), all.end(), upd[i].second) - all.begin()+1;
        upd[i].second = pos;
    }
    sort(q.begin(), q.end(), cmp);
    cur_l = q[0].f, cur_r = q[0].f-1, cur_t = 0;
    for (int i = 0; i < q.size(); i++) {
        if (cur_r < q[i].f) {
            for (int j = cur_l; j <= cur_r; j++)
                delPos(j);
            cur_r = q[i].f - 1;
            cur_l = q[i].f;
        }
        if (cur_l > q[i].s) {
            for (int j = cur_l; j <= cur_r; j++)
                delPos(j);
            cur_l = q[i].s + 1;
            cur_r = q[i].s;
        }
        while (cur_l < q[i].f)
            delPos(cur_l), cur_l++;
        while (cur_l > q[i].f)
            makePos(cur_l - 1), cur_l--;
        while (cur_r < q[i].s)
            makePos(cur_r + 1), cur_r++;
        while (cur_r > q[i].s)
            delPos(cur_r), cur_r--;
        while (cur_t < q[i].t)
            makeUpd(cur_t + 1), cur_t++;
        while (cur_t > q[i].t)
            makeUpd(cur_t), cur_t--;
        answer[q[i].ind] = getAns();
    }
    for (int i = 1; i <= m; i++)
        if (answer[i] != -1)
            cout << answer[i] << "\n";
    return 0;
}