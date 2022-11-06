#include <bits/stdc++.h>

using namespace std;
const int N = 100005;
int n, a, b, answer;
int init[N], goal[N];
vector<int> result;
vector<int> V[N];
bool odw[N];
void DFS(int w, int depth, int x1, int x2) {
    odw[w] = true;
    if(depth % 2 == 0 && (init[w] ^ x2) != goal[w]) {
        answer++;
        result.push_back(w);
        x2 ^= 1;
    }
    if(depth % 2 == 1 && (init[w] ^ x1) != goal[w]) {
        answer++;
        result.push_back(w);
        x1 ^= 1;
    }   
    for(int i = 0; i < V[w].size(); i++) {
        int u = V[w][i];
        if(!odw[u]) {
            DFS(u, depth + 1, x1, x2);
        }
    }
}

int main() {
    scanf("%d", &n);
    for(int i = 1; i < n; i++) {
        scanf("%d %d", &a, &b);
        V[a].push_back(b);
        V[b].push_back(a);
    }
    for(int i = 1; i <= n; i++) {
        scanf("%d", &init[i]);
    }
    for(int i = 1; i <= n; i++) {
        scanf("%d", &goal[i]);
    }
    DFS(1, 0, 0, 0);
    printf("%d\n", answer);
    for(int i = 0; i < result.size(); i++) {
        printf("%d\n", result[i]);
    }
    return 0;
}