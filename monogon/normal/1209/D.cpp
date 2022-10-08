
#include <bits/stdc++.h>

#define ll long long
using namespace std;

const int N = 1e5 + 5;
int n, k, x, y;
vector<int> adj[N];
bool visited[N];

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> k;
    for(int i = 0; i < k; i++) {
        cin >> x >> y;
        adj[x - 1].push_back(y - 1);
        adj[y - 1].push_back(x - 1);
    }
    queue<int> q;
    int cmp = 0;
    for(int i = 0; i < n; i++) {
        if(!visited[i]) {
            q.push(i);
            visited[i] = true;
            cmp++;
        }
        while(q.size()) {
            x = q.front();
            q.pop();
            for(int v : adj[x]) {
                if(!visited[v]) {
                    q.push(v);
                    visited[v] = true;
                }
            }
        }
    }
    cout << max(0, k - n + cmp) << endl;
}