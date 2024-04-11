#include <bits/stdc++.h>

#define F first
#define S second
#define MP make_pair
#define PB push_back

using namespace std;

typedef long long ll;
typedef long double ld;

const int max_n = 1011, inf = 1000111222;

vector<int> v[max_n];
bool vis[max_n];
set<int> my;
set<int> his;

int result = -1;

void clr() {
    for (int i = 0; i < max_n; ++i) {
        v[i].clear();
        vis[i] = 0;
    }
    result = -1;
    my.clear();
    his.clear();
}


int gethis(int my) {
    cout << "A " << my +1 << endl;
    cout.flush();
    int his;
    cin >> his;
    return his - 1;
}

int getmy(int his) {
    cout << "B " << his +1 << endl;
    cout.flush();
    int my;
    cin >> my;
    return my - 1;
}

int fin(int ans) {
    cout << "C ";
    if (ans == -1) {
        cout << ans << endl;
    } else {
        cout << ans + 1 << endl;
    }
    cout.flush();
}

void dfs(int cur) {
    vis[cur] = 1;
    if (result != -1) return;
    if (my.find(cur) != my.end()) {
        result = cur;
        return;
    }
    for (int i = 0; i < v[cur].size(); ++i) {
        int to = v[cur][i];
        if (vis[to]) continue;
        dfs(to);
    }
}

void solve() {
    clr();
    int n;
    scanf("%d", &n);
    for (int i = 0; i + 1 < n; ++i) {
        int a, b;
        scanf("%d%d", &a, &b);
        --a, --b;
        v[a].PB(b);
        v[b].PB(a);
    }

    int cm, ch;
    cin >> cm;
    for (int i = 0; i < cm; ++i) {
        int x;
        scanf("%d", &x);
        --x;
        my.insert(x);
    }
    cin >> ch;
    for (int i = 0; i < ch; ++i) {
        int x;
        scanf("%d", &x);
        --x;
        his.insert(x);
    }
    int my0 = getmy(*his.begin());
    dfs(my0);
    if (result == -1) {
        exit(228);
    }
    int his0 = gethis(result);
    if (his.find(his0) != his.end()) {
        fin(result);
        return;
    }
    fin(-1);
}


int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int T;
    cin >> T;
    while(T--) {
        solve();
    }

    return 0;
}