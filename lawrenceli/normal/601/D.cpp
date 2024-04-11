#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <cstring>
#include <bitset>
#include <map>

using namespace std;

typedef long long ll;

const int maxn = 1 << 19;
const int maxlg = 20;
const int mod1 = 1e9 + 7;
const int mod2 = 1e9 + 9;
const int X = 42;

int n, c[maxn];
char v[maxn];
vector<int> adj[maxn];

int ent[maxn], exi[maxn], eu[2 * maxn], eucnt;
ll val[maxn], buc[maxn];

void dfs(int cur, int p = -1, int h1 = 0, int h2 = 0) {
    h1 = (ll(h1) * X % mod1 + v[cur]) % mod1;
    h2 = (ll(h2) * X % mod2 + v[cur]) % mod2;
    val[cur] = ll(h1) * mod2 + h2;

    ent[cur] = eucnt, eu[eucnt] = cur, eucnt++;

    for (int i : adj[cur])
        if (i != p)
            dfs(i, cur, h1, h2);

    exi[cur] = eucnt, eu[eucnt] = cur, eucnt++;
}

int bit[2 * maxn];

void upd(int i, int v) {
    for (i++; i < 2*maxn; i += i&-i) bit[i] += v;
}

int qry(int i) {
    int sum = 0;
    for (i++; i > 0; i -= i&-i) sum += bit[i];
    return sum;
}

int last[maxn];
int num[maxn];

void go() {
    for (int i = 0; i < n; i++) buc[i] = val[i];
    sort(buc, buc + n);
    int m = unique(buc, buc + n) - buc;
    for (int i = 0; i < n; i++) val[i] = lower_bound(buc, buc + n, val[i]) - buc;

    //for (int i = 0; i < n; i++) cout << val[i] << endl;
    
    memset(last, -1, sizeof(last));
    for (int i = 0; i < 2*n; i++) {
        if (ent[eu[i]] == i) {
            int x = val[eu[i]];
            if (last[x] == -1)
                last[x] = i, upd(i, 1);
            else
                upd(last[x], -1), upd(i, 1), last[x] = i;
        } else {
            num[eu[i]] = qry(exi[eu[i]]) - qry(ent[eu[i]] - 1);
            //cout << eu[i] << ' ' << num[eu[i]] << endl;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin >> n;
    for (int i = 0; i < n; i++) cin >> c[i];
    cin >> v;
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(0);
    go();

    int ma = 0;
    for (int i = 0; i < n; i++)
        ma = max(ma, num[i] + c[i]);

    int cnt = 0;
    for (int i = 0; i < n; i++)
        if (num[i] + c[i] == ma)
            cnt++;

    cout << ma << '\n' << cnt << '\n';
}