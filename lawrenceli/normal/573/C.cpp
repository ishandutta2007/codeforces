#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cassert>

using namespace std;

const int maxn = 100100;

int n;
vector<int> adj[maxn];
int type[maxn]; //0: single branch, 1: double branch, 2: single side, 3: double side, 4: special case 0, 5: special case 1

void end() {
    cout << "No\n";
    exit(0);
}

void dfs(int cur, int p=-1) {
    vector<int> v;
    for (int i : adj[cur])
        if (i != p)
            v.push_back(i);
    adj[cur] = v;

    for (int i : adj[cur]) dfs(i, cur);

    if (adj[cur].size() == 0 || adj[cur].size() == 1 && type[adj[cur][0]] == 0) {
        type[cur] = 0;
        return;
    }

    if (adj[cur].size() == 2 && type[adj[cur][0]] == 0 && type[adj[cur][1]] == 0) {
        type[cur] = 1;
        return;
    }

    int num[10] = {0, 0, 0, 0, 0, 0};

    for (int i : adj[cur])
        num[type[i]]++;

    if (num[4]) {
        if (num[4] > 1 || num[0] > 1 || num[1] || num[2] || num[3] || num[5] || num[6]) end();

        if (num[0] == 1) type[cur] = 5;
        else type[cur] = 4;
        return;
    }

    if (num[5]) end();

    if (num[2] <= 1 && num[3] == 0) {
        type[cur] = 2;
        return;
    }

    if (num[2] == 2 && num[3] == 0) {
        type[cur] = 3;
        return;
    }

    if (num[0] <= 2 && num[1] == 0 && num[2] == 0 && num[3] == 1) {
        if (num[0] == 2) type[cur] = 5;
        else type[cur] = 4;
        return;
    }

    end();
}

int main() {
    ios_base::sync_with_stdio(0);
    cin >> n;
    for (int i = 0; i < n - 1; ++i) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    memset(type, -1, sizeof(type));
    dfs(1);

    cout << "Yes\n";
}