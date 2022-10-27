#include<bits/stdc++.h>
using namespace std;
const int nax = 3e5 + 10;
int n;
int a[nax];
int b[nax];
int cnt[nax];
/**
1
5
2 2 2 1 5
2 2 5 2 1
_________
1 2 3 3 3
3 3 3 1 2
correct = 1, but there's two easy cycles
_________
1 2 3 3 3
3 1 3 3 2
correct = 2, but there's only one cycle

Is the number of cycle

2 2 2 1 5
2 2 5 2 1

2 1 5
5 2 1

the case where max_frequency is greater than half?

when max_frequency less than half, it's easy, just count the correct position



*/
vector <int> g[nax];
bool vis[nax];
bool in[nax];
int id;
bool cyc;

void dfs(int node) {
    vis[node] = in[node] = true;
    for (int to : g[node]) {
        if (!vis[to]) dfs(to);
        else if (in[to]) {
            cyc = true;
        }
    }
    in[node] = false;
}

bool solve() {
    cin >> n;
    fill(cnt + 1, cnt + n + 1, 0);
    for (int i = 1 ; i <= n ; ++ i) {
        cin >> a[i];
        g[i].clear();
        vis[i] = false;
        cnt[a[i]] += 1;
    }
    for (int i = 1 ; i <= n ; ++ i) {
        cin >> b[i];
        g[a[i]].push_back(b[i]);
    }
    int mx = max_element(cnt + 1, cnt + 1 + n) - cnt;
    vis[mx] = true;
    cyc = false;

    for (int i = 1 ; i <= n ; ++ i) {
        if (!vis[i]) dfs(i);
    }
    /**
        if there is cycle, it means that there exists cycle without mx_cnt
        To achieve maximum, every cycle must contain mx_cnt
        Otherwise, we can remove this cycle, let's say len k
        we will use k - 1 moves here, max_cnt is still maximum of n - k
        and it required only n - k - max_cnt
        Overall, we will just use n - max_cnt - 1,

        If the answer less than n - max_cnt, it also means that
        there must be at least max_cnt + 1 decomposition, which also means,
        there exist cycle without max_cnt
    */
    return !cyc;

}

int main() {
    int T;
    cin.tie(0)->sync_with_stdio(false);
    for (cin >> T ; T -- ;) {
        cout << (solve() ? "AC" : "WA") << '\n';
    }
}
/**
    long time no rated round
*/