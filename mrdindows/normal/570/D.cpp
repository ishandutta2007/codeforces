#include <vector>
#include <cstdio>

using namespace std;

vector<int> v[500010];
vector<int> q[500010];

int g[500010];
char s[500010];
int x[500010];
int res[500010];
void go(int cur, int d = 1) {
    for (int qid : q[cur]) {
        int gl = g[qid];
        res[qid] = x[gl];
    }
    x[d] ^= (1 << (s[cur] - 'a'));
    for (int to : v[cur]) {
        go(to, d + 1);
    }
    for (int qid : q[cur]) {
        int gl = g[qid];
        res[qid] ^= x[gl];
    }
}
int main() {
    int n, m;
    scanf("%d%d",&n,&m);
    for (int i = 1; i < n; ++i) {
        int x;
        scanf("%d",&x);
        --x;
        v[x].push_back(i);
    }
    scanf("%s", s);
    for (int i = 0; i < m; ++i) {
        int v;
        scanf("%d%d",&v, g + i);
        q[--v].push_back(i);
    }
    go(0);
    for (int i = 0; i < m; ++i) {
        puts(((res[i]&(res[i] - 1)) == 0) ? "Yes" : "No");
    }
    
    return 0;
}