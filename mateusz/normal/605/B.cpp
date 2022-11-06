#include <bits/stdc++.h>

using namespace std;

const int N = 100005;

int n, m;
int weight[N], inTree[N];
vector<int> V[2];
pair<int, int> ans[N];

bool cmp(int a, int b) {
    return weight[a] < weight[b];
}



int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= m; i++) {
        scanf("%d %d", &weight[i], &inTree[i]);
        V[inTree[i]].push_back(i);
    }
    
    sort(V[0].begin(), V[0].end(), cmp);
    sort(V[1].begin(), V[1].end(), cmp);
    
    for (int i = 0; i < V[1].size(); i++) {
        ans[V[1][i]] = make_pair(i + 1, i + 2);
    } 
    
    int kon = 1;
    int poc = 0;
    for (int i = 0; i < V[0].size(); i++) {
        int w = V[0][i];
        int u = V[1][kon];
        if (weight[w] < weight[u]) {
            printf("-1\n");
            return 0;
        }
        ans[w] = make_pair(poc + 1, kon + 2);
        poc++;
        if (poc == kon) {
            poc = 0;
            kon++;
        }
    }
    
    for (int i = 1; i <= m; i++) {
        printf("%d %d\n", ans[i].first, ans[i].second);
    }
    
    return 0;
}