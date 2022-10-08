
#include <bits/stdc++.h>

#define ll long long
using namespace std;

const int M = 2520, MAX_N = 1005;
int dp[MAX_N][M];
int visited[MAX_N][M], visited2[MAX_N][M];
int visit[MAX_N];
ll n, q, x, y;
int k[MAX_N], m[MAX_N];
int e[MAX_N][10];

int query2(int x, int y, int v, int counter) {
    stack<int> xstack;
    stack<int> ystack;
    xstack.push(x);
    ystack.push(y);
    int ans = 0;
    while(true) {
        x = xstack.top();
        y = ystack.top();
        if(visited2[x][y] == v) {
            dp[x][y] = counter;
        }
        if(visited2[x][y]) {
            ans = dp[x][y];
            break;
        }
        if(visit[x] != v) {
            counter++;
        }
        visited2[x][y] = v;
        visit[x] = v;
        int y2 = ((y + k[x]) % M + M) % M;
        int x2 = e[x][y2 % m[x]];
        xstack.push(x2);
        ystack.push(y2);
    }
    while(!xstack.empty()) {
        x = xstack.top(); xstack.pop();
        y = ystack.top(); ystack.pop();
        dp[x][y] = ans;
    }
    return ans;
}
int query(int x, int y, int v) {
    stack<int> xstack;
    stack<int> ystack;
    xstack.push(x);
    ystack.push(y);
    int ans = 0;
    while(true) {
        x = xstack.top();
        y = ystack.top();
        if(visited[x][y] == v) {
            dp[x][y] = query2(x, y, v, 0);
        }
        if(visited[x][y]) {
            ans = dp[x][y];
            break;
        }
        visited[x][y] = v;
        int y2 = ((y + k[x]) % M + M) % M;
        int x2 = e[x][y2 % m[x]];
        xstack.push(x2);
        ystack.push(y2);
    }
    while(!xstack.empty()) {
        x = xstack.top(); xstack.pop();
        y = ystack.top(); ystack.pop();
        dp[x][y] = ans;
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> k[i];
        k[i] = (k[i] % M + M) % M;
    }
    for(int i = 0; i < n; i++) {
        cin >> m[i];
        for(int j = 0; j < m[i]; j++) {
            cin >> e[i][j];
            e[i][j]--;
        }
    }
    cin >> q;
    while(q--) {
        cin >> x >> y;
        x--;
        y = (y % M + M) % M;
        cout << query(x, y, q + 1) << endl;
    }
}