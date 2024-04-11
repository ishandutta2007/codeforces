#include<bits/stdc++.h>

using namespace std;

const int N = 3e5 + 100;

vector <vector <int> > g[N];

int ans[N];
int used[N];

int coun = 0;

void go_to1(int v) {
    used[v] = 1;
    coun++;
    for(auto to : g[v]) {
        if(used[to[0]]) {
            continue;
        }
        if(to[1] == -1) {
            go_to1(to[0]);
        }
        else {
            ans[to[1]] = 1 + to[2];
            go_to1(to[0]);
        }
    }
}

void go_to2(int v) {
    used[v] = 1;
    coun++;
    for(auto to : g[v]) {
        if(used[to[0]]) {
            continue;
        }
        if(to[1] == -1) {
            go_to2(to[0]);
        }
        else {
            ans[to[1]] = 2 - to[2];
        }
    }
}

main() {
#ifdef HOME
    freopen("input.txt", "r", stdin);
#endif // HOME
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m, s;
    cin >> n >> m >> s;
    for(int i = 0; i < m; i++) {
        int t, u, v;
        cin >> t >> u >> v;
        u--;
        v--;
        if (t == 1) {
            g[u].push_back({v, -1, 0});
        }
        else {
            ans[i] = 1;
            g[u].push_back({v, i, 0});
            g[v].push_back({u, i, 1});
        }
    }
    s--;
    go_to1(s);
    cout << coun << "\n";
    for (int i = 0; i < m; i++) {
        if(ans[i]) {
            if(ans[i] == 1) {
                cout << "+";
            }
            else {
                cout << "-";
            }
        }
    }
    cout << "\n";
    fill(used, used + N, 0);
    coun = 0;
    go_to2(s);
    cout << coun << "\n";
    for(int i = 0; i < m; i++) {
        if(ans[i]) {
            if(ans[i] == 1) {
                cout << "+";
            }
            else {
                cout << "-";
            }
        }
    }
    return 0;
}