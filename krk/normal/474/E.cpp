#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef pair <int, int> ii;

const int Maxn = 100005;
const int Maxm = 524288;

int n, d;
ll a[Maxn];
vector <ll> un;
ii mx[Maxm];
ii par[Maxn];
ii res;
int seq[Maxn];

void Update(int v, int l, int r, int a, int b, ii val)
{
    if (l == a && r == b) {
        if (val.first > mx[v].first) mx[v] = val;
    }
    else {
        int m = l + r >> 1;
        if (a <= m) Update(2 * v, l, m, a, min(m, b), val);
        if (m + 1 <= b) Update(2 * v + 1, m + 1, r, max(m + 1, a), b, val);
    }
}

ii Get(int v, int l, int r, int x)
{
    ii res = mx[v];
    if (l < r) {
        int m = l + r >> 1;
        if (x <= m) {
            ii cand = Get(2 * v, l, m, x);
            if (cand.first > res.first) res = cand;
        } else {
            ii cand = Get(2 * v + 1, m + 1, r, x);
            if (cand.first > res.first) res = cand;
        }
    }
    return res;
}

void insertSmall(ll x, ii cand)
{
    int ind = upper_bound(un.begin(), un.end(), x) - un.begin() - 1;
    if (ind >= 0) Update(1, 0, n - 1, 0, ind, cand);
}

void insertBig(ll x, ii cand)
{
    int ind = lower_bound(un.begin(), un.end(), x) - un.begin();
    if (ind < n) Update(1, 0, n - 1, ind, n - 1, cand);
}

int main()
{
    scanf("%d %d", &n, &d);
    for (int i = 0; i < n; i++) {
        scanf("%I64d", &a[i]);
        un.push_back(a[i]);
    }
    sort(un.begin(), un.end()); un.erase(unique(un.begin(), un.end()), un.end());
    for (int i = 0; i < n; i++) {
        int ind = lower_bound(un.begin(), un.end(), a[i]) - un.begin();
        ii cand = Get(1, 0, n - 1, ind);
        par[i] = cand;
        cand.first++; cand.second = i;
        if (cand.first > res.first) res = cand;
        insertSmall(a[i] - ll(d), cand); insertBig(a[i] + ll(d), cand);
    }
    int tims = res.first;
    printf("%d\n", tims);
    for (int i = tims - 1; i >= 0; i--) {
        seq[i] = res.second + 1;
        res.second = par[res.second].second;
    }
    for (int i = 0; i < tims; i++)
        printf("%d%c", seq[i], i + 1 < tims? ' ': '\n');
    return 0;
}