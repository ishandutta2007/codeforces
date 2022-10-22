#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 100005;
const int Maxm = 524288;

struct node {
    int lef, rig, siz;
    ll sum;
};

int n;
map <int, int> lst;
vector <int> seq;
int prv[Maxn];
node st[Maxm];
ll sum[Maxn];
ll res;

ll Intervals(int x) { return ll(x) * (x + 1) / 2ll; }

node Union(const node &a, const node &b)
{
    node c;
    c.siz = a.siz + b.siz;
    c.lef = a.lef + (a.lef == a.siz? b.lef: 0);
    c.rig = b.rig + (b.rig == b.siz? a.rig: 0);
    c.sum = a.sum - Intervals(a.rig) + b.sum - Intervals(b.lef) + Intervals(a.rig + b.lef);
    return c;
}

void Initialize(int v, int l, int r)
{
    st[v].siz = st[v].lef = st[v].rig = r - l + 1;
    st[v].sum = Intervals(st[v].siz);
}

void Create(int v, int l, int r)
{
    Initialize(v, l, r);
    if (l < r) {
        int m = l + r >> 1;
        Create(2 * v, l, m);
        Create(2 * v + 1, m + 1, r);
    }
}

void Clear(int v, int l, int r)
{
    if (st[v].lef == st[v].siz) return;
    Initialize(v, l, r);
    if (l < r) {
        int m = l + r >> 1;
        Clear(2 * v, l, m);
        Clear(2 * v + 1, m + 1, r);
    }
}

void Update(int v, int l, int r, int x)
{
    if (l == r) st[v].lef = st[v].rig = st[v].sum = 0;
    else {
        int m = l + r >> 1;
        if (x <= m) Update(2 * v, l, m, x);
        else Update(2 * v + 1, m + 1, r, x);
        st[v] = Union(st[2 * v], st[2 * v + 1]);
    }
}

node Get(int v, int l, int r, int a, int b)
{
    if (l == a && r == b) return st[v];
    else {
        int m = l + r >> 1;
        if (b <= m) return Get(2 * v, l, m, a, b);
        if (m + 1 <= a) return Get(2 * v + 1, m + 1, r, a, b);
        return Union(Get(2 * v, l, m, a, m), Get(2 * v + 1, m + 1, r, m + 1, b));
    }
}

bool Lucky(int x)
{
    while (x) {
        int dig = x % 10;
        if (dig != 4 && dig != 7)
            return false;
        x /= 10;
    }
    return true;
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int a; scanf("%d", &a);
        if (Lucky(a)) {
            seq.push_back(i);
            auto it = lst.find(a);
            if (it == lst.end()) {
                prv[i] = -1;
                lst.insert(make_pair(a, i));
            } else {
                prv[i] = it->second;
                it->second = i;
            }
        }
    }
    Create(1, 0, n - 1);
    sum[0] = Intervals(0);
    for (int i = 1; i <= n; i++)
        sum[i] = sum[i - 1] + Intervals(i);
    for (int i = 0; i < n; i++) {
        int ind = lower_bound(seq.begin(), seq.end(), i) - seq.begin();
        int to = ind < seq.size()? seq[ind]: n;
        res += Intervals(i) * ll(to - i);
    }
    for (int i = 0; i < seq.size(); i++) {
        int from = i == 0? -1: seq[i - 1];
        Clear(1, 0, n - 1);
        for (int j = i; j < seq.size(); j++) {
            int nxt = j + 1 >= seq.size()? n: seq[j + 1];
            if (prv[seq[j]] < seq[i]) {
                int el = prv[seq[j]];
                while (el != -1) {
                    Update(1, 0, n - 1, el);
                    el = prv[el];
                }
            }
            node got = Get(1, 0, n - 1, 0, seq[i]);
            ll intervals = got.sum - Intervals(got.rig);
            res += intervals * ll(seq[i] - from) * ll(nxt - seq[j]);
            int st = seq[i] + 1 - got.rig;
            if (st > from) res += sum[seq[i] - st] * ll(nxt - seq[j]);
            else res += (sum[seq[i] - st] - sum[from - st]) * ll(nxt - seq[j]);
        }
    }
    cout << res << endl;
    return 0;
}