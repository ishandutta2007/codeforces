/*input
4
1 2
1 3
1 4


4
1 2
2 3
3 4




*/
#include <bits/stdc++.h>
using namespace std;
#define sp ' '
#define endl '\n'
#define fi first
#define se second
#define mp make_pair
#define int long long
#define N 200005
#define bit(x,y) ((x>>y)&1LL)
#define loop(i,l,r) for(int i=(int)(l); i<=(int)(r); i++)

void read(int &number) {
    bool negative = false;
    int c;
    number = 0;
    c = getchar();
    while (c == ' ' || c == '\n')
        c = getchar();
    if (c == '-') {
        negative = true;
        c = getchar();
    }
    for (; (c > 47 && c < 58); c = getchar())
        number = number * 10 + c - 48;
    if (negative)
        number = -number;
}

template <class T1, class T2>
ostream &operator<<(ostream &os, const pair<T1, T2> &a) {
    return os << '(' << a.first << ", " << a.second << ')';
}
template <class T>
ostream &operator<<(ostream &os, const vector<T> &a) {
    os << '[';
    for (unsigned int i = 0; i < a.size(); i++)
        os << a[i] << (i < a.size() - 1 ? ", " : "");
    os << ']';
    return os;
}
template <class T>
ostream &operator<<(ostream &os, const set<T> &a) {
    os << '{';
    for (typename set<T>::iterator it = a.begin(); it != a.end(); it++) {
        typename set<T>::iterator jt = it;
        os << *it << (++jt != a.end() ? ", " : "");
    }
    os << '}';
    return os;
}
template <class T1, class T2>
ostream &operator<<(ostream &os, map<T1, T2> &a) {
    os << "{\n";
    for (typename map<T1, T2>::iterator it = a.begin(); it != a.end(); it++) {
        typename map<T1, T2>::iterator jt = it;
        os << "  " << it->first << ": " << it->second << (++jt != a.end() ? ",\n" : "\n");
    }
    os << '}';
    return os;
}

int n;
vector<vector<int> > a(N);
int dp[N][2];
int all[2];
int child[N];
int ans = 0;
void dfs(int u, int p) {
    child[u] = 1;
    for (auto v : a[u]) {
        if (v == p) continue;
        dfs(v, u);
        ans += child[v] * (n - child[v]);
        child[u] += child[v];
    }
    for (auto v : a[u]) {
        if (v == p) continue;
        all[0] -= dp[v][0] * dp[v][0] + dp[v][1] * dp[v][1];
        all[1] -= dp[v][0] * dp[v][1];
        dp[u][1] += dp[v][0];
        dp[u][0] += dp[v][1];
    }
    all[1] += dp[u][1]; all[0] += dp[u][0];
    all[0] += dp[u][0] * dp[u][0] + dp[u][1] * dp[u][1];
    all[1] += dp[u][0] * dp[u][1];
    dp[u][0]++;
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    loop(i, 0, n - 2) {
        int u, v; cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    memset(dp, 0, sizeof(dp));
    dfs(1, 1);
    cout << (ans - all[1]) / 2 + all[1] << endl;
}