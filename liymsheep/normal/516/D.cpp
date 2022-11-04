#include <functional>
#include <algorithm>
#include <stdexcept>
#include <iostream>
#include <sstream>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <cstdlib>
#include <cstring>
#include <utility>
#include <cctype>
#include <vector>
#include <string>
#include <bitset>
#include <cmath>
#include <queue>
#include <stdio.h>
#include <stack>
#include <ctime>
#include <list>
#include <map>
#include <set>
#include <assert.h>
#define REP(i,n) for(int i=0;i<n;i++)
#define TR(i,x) for(__typeof(x.begin()) i=x.begin();i!=x.end();i++)
#define ALL(x) x.begin(),x.end()
#define SORT(x) sort(ALL(x))
#define CLEAR(x) memset(x,0,sizeof(x))
#define FILL(x,c) memset(x,c,sizeof(x))

#include <unordered_set>

using namespace std;

const double eps = 1e-12;

#define PB push_back
#define MP make_pair

typedef map<int,int> MII;
typedef map<string,int> MSI;
typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<long double> VD;
typedef pair<int,int> PII;
typedef long long int64;
typedef long long LL;
typedef unsigned int UI;
typedef long double LD;
typedef unsigned long long ULL;

const int N = 100007;

vector<PII> edge[N];

LL far_up[N], far_down[N], far[N];

void go_down(int x, int fa) {
    far_down[x] = 0;
    TR(it, edge[x]) {
        if (it->first == fa) continue;
        go_down(it->first, x);
        far_down[x] = max(far_down[x], far_down[it->first] + it->second);
    }
}

void go_up(int x, int fa) {
    far[x] = max(far_up[x], far_down[x]);

    REP(i, edge[x].size()) {
        if (edge[x][i].first == fa) {
            continue;
        }
        far_up[edge[x][i].first] = far_up[x] + edge[x][i].second;
    }
    LL current = 0;
    REP(i, edge[x].size()) {
        if (edge[x][i].first == fa) continue;
        far_up[edge[x][i].first] = max(far_up[edge[x][i].first], current + edge[x][i].second);
        current = max(current, far_down[edge[x][i].first] + edge[x][i].second);
    }
    current = 0;
    for (int i = edge[x].size() - 1; i >= 0; --i) {
        if (edge[x][i].first == fa) continue;
        far_up[edge[x][i].first] = max(far_up[edge[x][i].first], current + edge[x][i].second);
        current = max(current, far_down[edge[x][i].first] + edge[x][i].second);
    }

    TR(it, edge[x]) {
        if (it->first == fa) continue;
        go_up(it->first, x);
    }
}

LL dis[N];
int last_time = 0;
int inner[N], outter[N], which[N];

void dfs(int x, int fa, LL d) {
    which[last_time] = x;
    inner[x] = last_time++;
    dis[x] = d;
    TR(it, edge[x]) {
        if (it->first == fa) continue;
        dfs(it->first, x, d + it->second);
    }
    outter[x] = last_time - 1;
}

const int MAXN = 2222222;

struct Node2
{
    int l, r, cl, cr, val;

    Node2(int tl, int tr, int tcl, int tcr, int tval = 0) :
        l(tl), r(tr), cl(tcl), cr(tcr), val(tval)
    {
    }

    Node2()
    {
    }
} tree[MAXN];

int last;

int getNode() { return last++;}

int makeNode(int left, int right, int cl, int cr, int x)
{
    tree[x] = Node2(left, right, cl, cr);
    tree[x].val = tree[cl].val + tree[cr].val;
    return x;
}

int build(int left, int right, int val, int x)
{
    tree[x].l = left;
    tree[x].r = right;
    if (left == right)
    {
        tree[x].val = val;
        return x;
    }

    int mid = (left + right) >> 1;
    tree[x].cl = build(left, mid, val, getNode());
    tree[x].cr = build(mid+1, right, val, getNode());
    tree[x].val = tree[tree[x].cl].val + tree[tree[x].cr].val;

    return x;
}

int add(int pos, int val, int x)
{
    if (tree[x].l == tree[x].r)
        return build(tree[x].l, tree[x].r, tree[x].val + val, getNode());
    int mid = tree[tree[x].cl].r;
    if (pos <= mid)
        return makeNode(tree[x].l, tree[x].r, add(pos, val, tree[x].cl), tree[x].cr, getNode());
    return makeNode(tree[x].l, tree[x].r, tree[x].cl, add(pos, val, tree[x].cr), getNode());
}

int root[MAXN];

bool cmp(const pair<LL, vector<PII>::iterator>& a, const pair<LL, vector<PII>::iterator>& b) {
    return a.first > b.first;
}

int main() {
    int n;
    cin >> n;
    REP(i, n - 1) {
        int x, y, v;
        scanf("%d%d%d", &x, &y, &v);
        --x; --y;
        edge[x].PB(MP(y, v));
        edge[y].PB(MP(x, v));
    }
    go_down(0, -1);
    go_up(0, -1);
    LL max_d = 0x3F3F3F3F3F3F3F3FLL;
    REP(i, n) max_d = min(max_d, far[i]);
    VI center;
    REP(i, n) if (max_d == far[i]) center.PB(i);
    assert(center.size() <= 2);

    int real_center = center[0];
    if (center.size() == 2) {
        TR(it, edge[center[0]]) if (it->first == center[1]) {
            edge[center[0]].erase(it);
            break;
        }
        TR(it, edge[center[1]]) if (it->first == center[0]) {
            edge[center[1]].erase(it);
            break;
        }

        edge[n].PB(MP(center[0], 0));
        edge[n].PB(MP(center[1], 0));
        edge[center[0]].PB(MP(n, 0));
        edge[center[1]].PB(MP(n, 0));
        real_center = n;
        ++n;
    }

    go_down(real_center, -1);

    vector< pair<LL, vector<PII>::iterator> > down_edges;
    TR(it, edge[real_center]) {
        down_edges.PB(MP(far_down[it->first] + it->second, it));
    }

    sort(ALL(down_edges), cmp);

    if (down_edges.size() >= 2 && down_edges[0].first != down_edges[1].first) {
        down_edges[0].second->second -= (down_edges[0].first - down_edges[1].first);
    }

    dfs(real_center, -1, 0);
    vector<LL> dists(n);
    REP(i, n) dists[i] = dis[i];
    SORT(dists);
    dists.erase(unique(ALL(dists)), dists.end());

    int total = dists.size() - 1;

    int cur = build(0, total, 0, getNode());
    root[0] = cur;
    REP(i, n) {
        root[i + 1] = add(lower_bound(ALL(dists), dis[which[i]]) - dists.begin(), 1, cur);
        cur = root[i + 1];
    }

    // REP(i, n) cout << dis[i] << endl;

    int q;
    cin >> q;
    while (q--) {
        LL d;
        cin >> d;
        int res = 0;
        for (int i = 0; i < n; ++i) {
            int b = inner[i];
            int e = outter[i] + 1;

            LL max_dis = dis[i] + d;
            int r = upper_bound(ALL(dists), max_dis) - dists.begin() - 1;

            // cout << "max_dis = " << max_dis << ", r is " << r << endl;

            int ans = 0;
            int cury = root[e], curx = root[b];
            while (true)
            {
                int have = tree[cury].val - tree[curx].val;
                if (r >= tree[cury].r) {
                    ans += have;
                    // cout << "ANS IS " << ans << endl;
                    break;
                }
                if (r > tree[tree[cury].cl].r) {
                    ans += tree[tree[cury].cl].val - tree[tree[curx].cl].val;
                    curx = tree[curx].cr;
                    cury = tree[cury].cr;
                } else {
                    curx = tree[curx].cl;
                    cury = tree[cury].cl;
                }
            }

            if (center.size() == 2 && i == n - 1) {
                --ans;
            }
            res = max(res, ans);
        }
        cout << res << endl;
    }

    return 0;
}