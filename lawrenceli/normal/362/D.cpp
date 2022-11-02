#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <ios>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

const int MAXN = 100100;

int n, m, p, q;
int par[MAXN];
ll sum[MAXN];
vector<int> comp[MAXN];

void init() { for (int i=0; i<MAXN; i++) par[i] = i; }
int getpar(int a) { return par[a] == a ? a : par[a] = getpar(par[a]); }
void merge(int a, int b) { par[a] = getpar(par[b]); }

set<pll> st;

int main() {
    ios :: sync_with_stdio(0);

    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);

    cin >> n >> m >> p >> q;
    init();

    for (int i=0; i<m; i++) {
        int x, y, l;
        cin >> x >> y >> l;
        x--; y--;
        x = getpar(x), y = getpar(y);
        if (x == y) sum[x] += l;
        else {
            merge(x, y);
            sum[y] += sum[x] + l;
        }
    }

    for (int i=0; i<n; i++)
        if (par[i] == i)
            st.insert(pll(sum[i], i));

    if (st.size() < q) {
        cout << "NO\n";
        return 0;
    }

    vector<pll> ans;
    while (st.size() > q) {
        typeof(st.begin()) it = st.begin();
        pll p1 = *it;
        it++;
        pll p2 = *it;
        st.erase(p1); st.erase(p2);
        int a = p1.second, b = p2.second;
        a = getpar(a), b = getpar(b);
        ans.push_back(pll(a+1, b+1));
        merge(a, b);
        sum[b] += sum[a] + min(ll(1e9), sum[a] + sum[b] + 1);
        st.insert(pll(sum[b], b));
    }

    if (ans.size() > p) {
        cout << "NO\n";
        return 0;
    }

    if (ans.size() == p) {
        cout << "YES\n";
        for (int i=0; i<p; i++) cout << ans[i].first << ' ' << ans[i].second << '\n';
        return 0;
    }

    for (int i=0; i<n; i++) comp[getpar(i)].push_back(i+1);

    pll p1 = pll(-1, -1);
    for (int i=0; i<n; i++)
        if (comp[i].size() > 1)
            p1 = pll(comp[i][0], comp[i][1]);

    if (p1.first == -1) {
        cout << "NO\n";
        return 0;
    }

    cout << "YES\n";
    for (int i=0; i<ans.size(); i++) cout << ans[i].first << ' ' << ans[i].second << '\n';
    for (int i=0; i<p-ans.size(); i++) cout << p1.first << ' ' << p1.second << '\n';

    return 0;
}