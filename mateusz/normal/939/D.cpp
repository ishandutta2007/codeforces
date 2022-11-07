#include <bits/stdc++.h>

using namespace std;

const int N = 100005;

int n;
char wordA[N], wordB[N];
vector<pair<int, int> > edges;
bool edge[30][36];
bool vis[36];

void DFS(int w) {
    vis[w] = true;
    for (int i = 0; i < 26; i++) {
        if (edge[w][i] && !vis[i]) {
            edges.push_back({w, i});
            DFS(i);
        }
    }
}

int main() {
    
    scanf("%d", &n);
    scanf("%s", &wordA[1]);
    scanf("%s", &wordB[1]);
    
    for (int i = 1; i <= n; i++) {
        edge[wordA[i] - 'a'][wordB[i] - 'a'] = edge[wordB[i] - 'a'][wordA[i] - 'a'] = true;
    }
    
    for (int i = 0; i < 26; i++) {
        if (!vis[i]) {
            DFS(i);
        }
    }
    
    printf("%d\n", edges.size());
    
    for (auto p : edges) {
        printf("%c %c\n", p.first + 'a', p.second + 'a');
    }
    
    
    return 0;
}