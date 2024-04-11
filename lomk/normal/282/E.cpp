/*input
2
1 2
*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sp ' '
#define endl '\n'
#define fi first
#define se second
#define bit(x,y) ((x>>y)&1)
#define loop(i,l,r) for(int i=(int)l; i<=(int)r; i++)
#define rloop(i,l,r) for(int i=(int)l; i>=(int)r; i--)
#ifdef UncleGrandpa
#include <prettyprint.hpp>
void print() {cout << endl;} template<typename T, typename... Ts> void print(const T& value, const Ts&... values) {cout << value << ' ', print(values...);}
void debug() {cerr << endl;} template<typename T, typename... Ts> void debug(const T& value, const Ts&... values) {cerr << value << ' ', debug(values...);}
#endif
const int N = 1e5 + 5;

ll a[N], cur_pre, cur_suf, ans;
int n;

struct Node {
    Node * cnt[2];
    bool isLeaf;
    Node() {
        for (int i = 0; i < 2; i++) cnt[i] = NULL;
        isLeaf = false;
    }
} * root = new Node();

void add(ll x) {
    Node * cur = root;
    for (int i = 63; i >= 0; i--) {
        int t = bit(x, i);
        if (cur->cnt[t] == NULL) cur -> cnt[t] = new Node();
        cur = cur->cnt[t];
    }
    cur->isLeaf = true;
}

void dfs(Node * u, ll num, ll curAns, int lev) {
    if (lev == -1) {
        ans = max(ans, curAns);
        return;
    }
    int t = bit(num, lev);
    if (u -> cnt[t ^ 1] != NULL) {
        curAns ^= (1LL << lev);
        u = u -> cnt[t ^ 1];
    }
    else
        u = u -> cnt[t];
    dfs(u, num, curAns, lev - 1);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    add(0);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i], cur_pre ^= a[i];
    dfs(root, cur_pre, 0, 63);
    for (int i = n; i >= 1; i--) {
        cur_suf ^= a[i];
        add(cur_suf);
        cur_pre ^= a[i];
        dfs(root, cur_pre, 0, 63);
    }
    cout << ans << endl;
}