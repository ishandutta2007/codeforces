#include <bits/stdc++.h>

using namespace std;
const int N = 100005;
int n, m, tab[N], t[N], a, b;
vector<int> V[N];
int size[N];
int cnt[N];
int rep[N];
bool activated[N];
bool cmp(int a, int b) {
    return tab[a] < tab[b];
}
int find(int w) {
    return rep[w] == w? w: rep[w] = find(rep[w]);
}
void Union(int a, int b) {
    a = find(a);
    b = find(b);
    size[b] += size[a];
    rep[a] = b;
}
int main() {
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; i++) {
        scanf("%d", &tab[i]);
        t[i] = i;
    }
    sort(t + 1, t + 1 + n, cmp);
    for(int i = 1; i <= m; i++) {
        scanf("%d %d", &a, &b);
        V[a].push_back(b);
        V[b].push_back(a);
    }
    for(int i = 1; i <= n; i++) {
        rep[i] = i;
        size[i] = 1;
    }
    long long ans = 0;
    for(int i = n; i >= 1; i--) { 
        long long sum = 0;
        int w = t[i];
        int components = 0;
        for(int j = 0; j < V[w].size(); j++) {
            int u = V[w][j];
            if(activated[u]) {
                if(cnt[find(u)] == 0) {
                    components++;
                    sum += size[find(u)];
                }
                cnt[find(u)]++;
            }
        }
        ans += (long long)sum * tab[w];
        sum++;
        for(int j = 0; j < V[w].size(); j++) {
            if(activated[V[w][j]] && cnt[find(V[w][j])] != 0) {
                ans += (long long)(sum - size[find(V[w][j])]) * size[find(V[w][j])] * tab[w];
                cnt[find(V[w][j])] = 0;
            }
        }
        activated[w] = true;
        for(int j = 0; j < V[w].size(); j++) {
            int u = V[w][j];
            if(activated[u] && find(w) != find(u)) {
                Union(w, u);
            }
        }
    }
    printf("%.17lf\n", (double)((long double)ans / ((long long)n * (n - 1))));
    return 0;
}