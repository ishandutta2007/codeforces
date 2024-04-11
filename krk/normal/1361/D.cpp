#include <bits/stdc++.h>
using namespace std;
 
typedef pair <int, int> ii;
typedef long double ld;
typedef pair <ld, int> ldi;
 
const int Maxn = 500005;
const int Maxm = 2097152;
const ld Inf = 1e30l;
 
int n, k;
int X[Maxn], Y[Maxn];
map <ii, int> ID;
int myid[Maxn], mxid;
vector <vector <ld> > V;
vector <vector <int> > toel;
map <ii, vector <ld> > M;
ldi seq[Maxn];
int slen;
ld sum[Maxm];
int cnt[Maxm];
ld res = 0;

int getID(const ii &p)
{
    auto it = ID.find(p);
    if (it == ID.end()) {
        int res = ID.size();
        ID.insert(make_pair(p, res));
        return res;
    }
    return it->second;
}

int gcd(int x, int y) { return x? gcd(y % x, x): y; }
 
ld Len(ld x, ld y) { return sqrt(x * x + y * y); }
 
void Union(int v)
{
    int lc = 2 * v, rc = 2 * v + 1;
    assert(rc < Maxm);
    sum[v] = sum[lc] + sum[rc];
    cnt[v] = cnt[lc] + cnt[rc];
}
 
void Create(int v, int l, int r)
{
    if (l > r) return;
    if (l == r) {
        sum[v] = seq[l].first;
        cnt[v] = 1;
    } else {
        int m = l + r >> 1;
        Create(2 * v, l, m);
        Create(2 * v + 1, m + 1, r);
        Union(v);
    }
}
 
ld Get(int v, int l, int r, int hm)
{
    if (hm <= 0) return 0;
    if (hm >= cnt[v]) return sum[v];
    int m = l + r >> 1;
    assert(2 * v + 1 < Maxm);
    return Get(2 * v + 1, m + 1, r, hm) + Get(2 * v, l, m, hm - cnt[2 * v + 1]);
}
 
void Update(int v, int l, int r, int x, bool add)
{
    if (l == r) {
        assert(add != cnt[v]);
        if (add) {
            sum[v] = seq[l].first;
            cnt[v] = 1;
        } else {
            sum[v] = 0;
            cnt[v] = 0;
        }
    }
    else {
        int m = l + r >> 1;
        if (x <= m) Update(2 * v, l, m, x, add);
        else Update(2 * v + 1, m + 1, r, x, add);
        Union(v);
    }
}
 
ld Get(int k)
{
    if (k > cnt[1]) return -Inf;
    return Get(1, 0, slen - 1, k);
}
 
int main()
{
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &X[i], &Y[i]);
        if (X[i] || Y[i]) {
            int g = gcd(abs(X[i]), abs(Y[i]));
            myid[i] = getID(ii(X[i] / g, Y[i] / g));
            mxid = max(mxid, myid[i]);
        }
    }
    V.resize(mxid + 1);
    for (int i = 0; i < n; i++)
        if (X[i] || Y[i]) {
            ld len = Len(X[i], Y[i]);
            V[myid[i]].push_back(len);
        }
    for (int z = 0; z < V.size(); z++) {
        sort(V[z].begin(), V[z].end());
        for (int i = int(V[z].size()) - 1, cur = k - 1; cur > 0 && i >= 0; i--, cur -= 2)
            seq[slen++] = ldi(V[z][i] * cur, z);
    }
    sort(seq, seq + slen);
    toel.resize(V.size());
    for (int i = 0; i < slen; i++)
        toel[seq[i].second].push_back(i);
    Create(1, 0, slen - 1);
    res = max(Get(k), Get(k - 1));
    for (int z = 0; z < V.size(); z++) {
        for (int i = 0; i < toel[z].size(); i++)
            Update(1, 0, slen - 1, toel[z][i], false);
        int lef = 0, rig = 0;
        ld S = 0;
        ld my = 0;
        for (int i = 1, cur = k - 1; i <= k && i <= V[z].size(); i++) {
            if (cur >= 0) {
                my += -2 * S + cur * V[z][int(V[z].size()) - 1 - rig];
                cur -= 2;
                rig++;
            } else {
                my += -2 * S + cur * V[z][lef];
                S += V[z][lef++];
            }
            res = max(res, Get(k - i) + my);
            if (i < k) res = max(res, Get(k - i - 1) + my);
        }
        for (int i = 0; i < toel[z].size(); i++)
            Update(1, 0, slen - 1, toel[z][i], true);
    }
    cout << fixed << setprecision(10) << res << endl;
    return 0;
}