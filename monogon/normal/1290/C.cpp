
#include <bits/stdc++.h>

#define ll long long
using namespace std;

const int N = 3e5 + 5;
int n, k;
string s;
int c, x;
vector<int> adj[N];
int dsu2[N], cnt[N][2];
bool flip[N], fix[N];
int ans = 0;

int trace2(int x) {
    return dsu2[x] < 0 ? x : trace2(dsu2[x]);
}

void flipcomp(int x) {
    flip[x] = !flip[x];
    ans += cnt[x][0] - cnt[x][1];
    swap(cnt[x][0], cnt[x][1]);
}

void join2(int x, int y) {
    if((x = trace2(x)) == (y = trace2(y))) return;
    if(dsu2[x] > dsu2[y]) swap(x, y);
    if(flip[x]) {
        flip[y] = !flip[y];
    }
    dsu2[x] += dsu2[y];
    cnt[x][0] += cnt[y][0];
    cnt[x][1] += cnt[y][1];
    fix[x] = fix[x] || fix[y];
    dsu2[y] = x;
}

bool isflipped(int x) {
    return dsu2[x] < 0 ? flip[x] : flip[x] ^ isflipped(dsu2[x]);
}

void flipone(int a, int b) {
    if(fix[a]) {
        flipcomp(b);
    }else if(fix[b]) {
        flipcomp(a);
    }else if(cnt[a][1] - cnt[a][0] > cnt[b][1] - cnt[b][0]) {
        flipcomp(a);
    }else {
        flipcomp(b);
    }
}

void printstate() {
    cout << "----" << endl;
    for(int i = 0; i < k; i++) {
        cout << dsu2[i] << " " << flip[i] << " " << cnt[i][0] << " " << cnt[i][1] << "\t" << fix[i] << endl;
    }
    cout << "----" << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> k >> s;
    for(int i = 0; i < k; i++) {
        cin >> c;
        for(int j = 0; j < c; j++) {
            cin >> x;
            adj[x - 1].push_back(i);
        }
    }
    fill(dsu2, dsu2 + N, -1);
    for(int i = 0; i < k; i++) {
        cnt[i][0] = 1;
    }
    for(int i = 0; i < n; i++) {
        if(s[i] == '1') {
            if(adj[i].size() == 2) {
                int x = adj[i][0], y = adj[i][1];
                int a = trace2(x), b = trace2(y);
                if(isflipped(x) != isflipped(y)) {
                    flipone(a, b);
                }
                join2(a, b);
            }else if(adj[i].size() == 1) {
                int u = adj[i][0];
                int v = trace2(u);
                if(isflipped(u)) {
                    flipcomp(v);
                }
                fix[v] = true;
            }
        }else {
            if(adj[i].size() == 2) {
                int x = adj[i][0], y = adj[i][1];
                int a = trace2(x), b = trace2(y);
                if(isflipped(x) == isflipped(y)) {
                    flipone(a, b);
                }
                join2(a, b);
            }else {
                int u = adj[i][0];
                int v = trace2(u);
                if(!isflipped(u)) {
                    flipcomp(v);
                }
                fix[v] = true;
            }
        }
        cout << ans << endl;
    }
}