#include <functional>
#include <algorithm>
#include <stdexcept>
#include <iostream>
#include <sstream>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <cstdlib>
#include <cstring>
#include <utility>
#include <cctype>
#include <vector>
#include <string>
#include <bitset>
#include <cmath>
#include <queue>
#include <stdio.h>
#include <stack>
#include <ctime>
#include <list>
#include <map>
#include <set>
#include <assert.h>
#define REP(i,n) for(int i=0;i<n;i++)
#define TR(i,x) for(__typeof(x.begin()) i=x.begin();i!=x.end();i++)
#define ALL(x) x.begin(),x.end()
#define SORT(x) sort(ALL(x))
#define CLEAR(x) memset(x,0,sizeof(x))
#define FILL(x,c) memset(x,c,sizeof(x))

#include <unordered_set>
#include <unordered_map>

using namespace std;

const double eps = 1e-12;

#define PB push_back
#define MP make_pair

typedef map<int,int> MII;
typedef map<string,int> MSI;
typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<long double> VD;
typedef pair<int,int> PII;
typedef long long int64;
typedef long long LL;
typedef unsigned int UI;
typedef long double LD;
typedef unsigned long long ULL;

const int N = 1000007;

int ne[N * 2][26];
int sz[N * 2];
int recycle[N * 2];
int last;

int next_node() {
    int nid = recycle[--last];

    CLEAR(ne[nid]);
    sz[nid] = 1;

    return nid;
}

inline void return_node(int x) {
    recycle[last++] = x;
}

void append(int node, char c) {
    if (ne[node][c - 'a']) {
        return;
    }

    int nid = next_node();
    ne[node][c - 'a'] = nid;
    ++sz[node];
}

// r2->r1
int do_merge(int r1, int r2) {
    int delta = 0;
    REP(i, 26) {
        if (ne[r2][i]) {
            if (!ne[r1][i]) {
                delta += sz[ne[r2][i]];
                ne[r1][i] = ne[r2][i];
            } else {
                delta += do_merge(ne[r1][i], ne[r2][i]);
            }
        }
    }
    sz[r1] += delta;
    return_node(r2);
    
    return delta;
}

int merge_trees(int r1, int r2) {
    if (sz[r1] < sz[r2]) {
        do_merge(r2, r1);
        return r2;
    }
    do_merge(r1, r2);
    return r1;
}

int ci[N];
char str[N];

int maxv, num_maxv;

VI edge[N];

int dfs(int x, int fa) {
    int root = next_node();
    append(root, str[x]);

    TR(it, edge[x]) {
        if (*it == fa) continue;
        int ni = dfs(*it, x);
        ne[root][str[x] - 'a'] = merge_trees(ne[root][str[x] - 'a'], ni);
    }

    sz[root] = 1 + sz[ne[root][str[x] - 'a']];

    int score = sz[root] + ci[x] - 1;
    if (score > maxv) {
        maxv = score;
        num_maxv = 0;
    }

    if (score == maxv) {
        ++num_maxv;
    }

    return root;
}

int main(){
    int n;
    cin >> n;
    last = 0;
    REP(i, n * 2 + 100) recycle[last++] = i;
    maxv = -1;
    REP(i, n) scanf("%d", &ci[i]);
    scanf("%s", str);
    REP(i, n - 1) {
        int u, v;
        scanf("%d%d", &u, &v);
        --u; --v;
        edge[u].PB(v);
        edge[v].PB(u);
    }
    dfs(0, -1);
    cout << maxv << endl;
    cout << num_maxv << endl;


    return 0;
}