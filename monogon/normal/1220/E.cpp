
#include <bits/stdc++.h>

#define ll long long
using namespace std;

const int N = 2e5 + 5;
int n, m, u, v, s;
vector<int> adj[N];
ll w[N];
ll termw[N];
ll termwmax[N];
bool terminal[N];
int termcount[N];
bool visited[N];
stack<int> st;
ll maxterm = 0;
ll wsum = 0;

void dfs(int x) {
    st.push(x);
    visited[x] = true;
    for(int y : adj[x]) {
        if(!visited[y]) {
            dfs(y);
        }
    }
}
void dfs2(int x) {
    visited[x] = true;
    if(terminal[x]) {
        maxterm = max(maxterm, termw[x]);
        return;
    }
    wsum += w[x];
    for(int y : adj[x]) {
        if(!visited[y]) {
            dfs2(y);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        cin >> w[i];
        termw[i] = w[i];
    }
    for(int i = 0; i < m; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    cin >> s;

    dfs(s);
    fill(visited, visited + N, false);
    while(!st.empty()) {
        int x = st.top();
        st.pop();
        visited[x] = true;
        termw[x] += termwmax[x];
        if(termcount[x] + 1 >= adj[x].size() && x != s) {
            terminal[x] = true;
            for(int y : adj[x]) {
                if(!visited[y]) {
                    termcount[y]++;
                    termwmax[y] = max(termwmax[y], termw[x]);
                }
            }
        }
    }

    fill(visited, visited + N, false);
    dfs2(s);
    cout << (wsum + maxterm) << endl;
}