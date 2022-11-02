#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200100;

int n, m, l[MAXN], r[MAXN], a[MAXN], b[MAXN], c[MAXN];
int ind[MAXN], ind2[MAXN];

bool cmp(int i1, int i2) { return l[i1] < l[i2]; }
bool cmp2(int i1, int i2) { return a[i1] < a[i2]; }

map<int, int> mp; int cnt;

//t1: max r-l, t2: min l
int t1[1<<21], t2[1<<21];

struct ccmp1 {
    bool operator()(const int& i1, const int& i2) const {
        if (r[i1]-l[i1] != r[i2]-l[i2])
            return r[i1]-l[i1] > r[i2]-l[i2];
        return i1 < i2;
    }
};

struct ccmp2 {
    bool operator()(const int& i1, const int& i2) const {
        if (l[i1] != l[i2])
            return l[i1] < l[i2];
        return i1 < i2;
    }
};

set<int, ccmp1> s1[4*MAXN], s2[4*MAXN];

void merge(int cur, int lt, int rt) {
    int x = t1[2*cur], y = t1[2*cur+1];
    if (x == -1) t1[cur] = y;
    else if (y == -1) t1[cur] = x;
    else t1[cur] = r[x]-l[x] > r[y]-l[y] ? x : y;

    x = t2[2*cur], y = t2[2*cur+1];
    if (x == -1) t2[cur] = y;
    else if (y == -1) t2[cur] = x;
    else t2[cur] = l[x] < l[y] ? x : y;
}

void upd(int cur, int lt, int rt, int p, int v, bool b) {
    if (lt + 1 == rt) {
        if (b) s1[p].insert(v), s2[p].insert(v);
        else s1[p].erase(v), s2[p].erase(v);
        t1[cur] = s1[p].size() ? *s1[p].begin() : -1;
        t2[cur] = s2[p].size() ? *s2[p].begin() : -1;
    } else {
        int mid = (lt + rt) / 2;
        if (p < mid) upd(2*cur, lt, mid, p, v, b);
        else upd(2*cur+1, mid, rt, p, v, b);
        merge(cur, lt, rt);
    }
}

int qry(int cur, int lt, int rt, int ql, int qr, bool b) {
    if (rt <= ql || lt >= qr) return -1;
    else if (lt >= ql && rt <= qr) return !b ? t1[cur] : t2[cur];
    else {
        int mid = (lt + rt) / 2;
        int x = qry(2*cur, lt, mid, ql, qr, b);
        int y = qry(2*cur+1, mid, rt, ql, qr, b);
        if (x == -1) return y;
        else if (y == -1) return x;
        else {
            if (!b) return r[x]-l[x] > r[y]-l[y] ? x : y;
            else return l[x] < l[y] ? x : y;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);

    cin >> n >> m;
    for (int i=0; i<n; i++) {
        cin >> l[i] >> r[i];
        mp[r[i]] = 0;
        ind[i] = i;
    }

    for (int i=0; i<m; i++) {
        cin >> a[i] >> b[i] >> c[i];
        mp[b[i]] = 0;
        ind2[i] = i;
    }

    for (map<int, int>::iterator it=mp.begin(); it!=mp.end(); it++)
        mp[it->first] = cnt++;

    memset(t1, -1, sizeof(t1));
    memset(t2, -1, sizeof(t2));

    for (int i=0; i<n; i++)
        upd(1, 0, cnt, mp[r[i]], i, 1);

    sort(ind, ind+n, cmp);
    sort(ind2, ind2+m, cmp2);

    long long ans = 0;
    int ai = -1, bi = -1;

    int ma = -1;
    for (int i1=0, p=0; i1<m; i1++) {
        int i = ind2[i1];
        while (p<n && l[ind[p]] <= a[i]) {
            if (ma == -1 || r[ma] < r[ind[p]]) ma = ind[p];
            upd(1, 0, cnt, mp[r[ind[p]]], ind[p], 0);
            p++;
        }

        int bt = -1, bv = 0;
        if (ma != -1) bt = ma, bv = min(b[i], r[ma])-a[i];

        int x = qry(1, 0, cnt, 0, mp[b[i]], 0);
        if (x != -1 && r[x]-l[x] > bv) bt = x, bv = r[x]-l[x];

        x = qry(1, 0, cnt, mp[b[i]], cnt, 1);
        if (x != -1 && b[i]-l[x] > bv) bt = x, bv = b[i]-l[x];

        if ((long long)(bv) * c[i] > ans)
            ans = (long long)(bv) * c[i], ai = i, bi = bt;
    }

    cout << ans << '\n';
    if (ans) cout << bi+1 << ' ' << ai+1 << '\n';
}