#ifdef debug
#define _GLIBCXX_DEBUG
#endif

#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) begin(x), end(x)

typedef unsigned int ui;
typedef long long ll;
typedef long double ld;
typedef pair< int, int > pii;
typedef pair< long long, long long > pll;

const int inf = 1e9;
const ll inf64 = 1e18;

const int N = 2e5 + 5;

int n;
vec< int > g[N];
int a[N];
int used[N];
int pos[N];

inline void no() {
    puts("No");
    exit(0);
}

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    scanf("%d", &n);

    for(int u, v, i = 1;i < n;i++) {
        scanf("%d %d", &u, &v);
        g[u].push_back(v);
        g[v].push_back(u);
    }

    for(int i = 0;i < n;i++) {
        scanf("%d", &a[i]);
        pos[a[i]] = i;
    }

    if(a[0] != 1) no();

    {
        for(int i = 0;i < n;i++) used[a[i]] = 1;
        for(int i = 1;i <= n;i++) if(!used[i]) no();
        for(int i = 1;i <= n;i++) used[i] = 0;
    }

    queue< int > q;
    q.push(1);
    int ptr = 0;
    used[1] = 1;

    while(!q.empty()) {
        int v = q.front();
        q.pop();
        if(a[ptr] != v) no();
        ptr++;
        vec< int > to_add;
        for(int to : g[v]) {
            if(!used[to]) {
                to_add.push_back(to);
                used[to] = 1;
            }
        }
        sort(ALL(to_add), [&](int u1, int u2){
            return pos[u1] < pos[u2];
        });
        for(int to : to_add) {
            q.push(to);
        }
    }

    puts("Yes");

    return 0;
}