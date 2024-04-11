
#include <bits/stdc++.h>

#define ll long long
using namespace std;

const int N = 2e5 + 5;
int n;
int a[N];
vector<int> adj[N], adjr[N];
bool vis[N], vis2[N];
int dist[N], dist2[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        if(i - a[i] >= 0) {
            adj[i].push_back(i - a[i]);
            adjr[i - a[i]].push_back(i);
        }
        if(i + a[i] < n) {
            adj[i].push_back(i + a[i]);
            adjr[i + a[i]].push_back(i);
        }
    }
    fill(dist, dist + n, -1);
    fill(dist2, dist2 + n, -1);
    queue<int> Q, Q2;
    for(int i = 0; i < n; i++) {
        if(a[i] % 2 == 0) {
            Q.push(i);
            dist[i] = 0;
            vis[i] = true;
        }else {
            Q2.push(i);
            dist2[i] = 0;
            vis2[i] = true;
        }
    }
    while(Q.size()) {
        int i = Q.front();
        Q.pop();
        for(int j : adjr[i]) {
            if(!vis[j]) {
                dist[j] = dist[i] + 1;
                Q.push(j);
                vis[j] = true;
            }
        }
    }
    while(Q2.size()) {
        int i = Q2.front();
        Q2.pop();
        for(int j : adjr[i]) {
            if(!vis2[j]) {
                dist2[j] = dist2[i] + 1;
                Q2.push(j);
                vis2[j] = true;
            }
        }
    }
    for(int i = 0; i < n; i++) {
        if(a[i] % 2 == 0) {
            cout << dist2[i] << " ";
        }else {
            cout << dist[i] << " ";
        }
    }
    cout << endl;
}