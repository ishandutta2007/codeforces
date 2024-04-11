#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <ios>
#include <cmath>
#include <cstring>

using namespace std;

const int MAXN = 100100;

struct data {
    int lt, rt, k, id;
    data() {}
    data(int lt, int rt, int k, int id) : lt(lt), rt(rt), k(k), id(id) {}
};

int n, m, c[MAXN], ent[MAXN], exi[MAXN], col[2*MAXN], cnt;
vector<int> adj[MAXN];
data arr[MAXN];

void dfs(int cur, int p) {
    col[cnt] = c[cur];
    ent[cur] = cnt++;
    for (int i=0; i<adj[cur].size(); i++) {
        int nxt = adj[cur][i];
        if (nxt == p) continue;
        dfs(nxt, cur);
    }
    exi[cur] = cnt++;
}

int len, freq[MAXN], num[MAXN], ans[MAXN];

bool cmp(data d1, data d2) {
    return d1.lt / len != d2.lt / len ? d1.lt / len < d2.lt / len : d1.rt < d2.rt;
}

int main() {
    ios :: sync_with_stdio(false);

    if (fopen("input.txt", "r")) {
        freopen("input.txt", "r", stdin);
    }

    cin >> n >> m;
    len = int(sqrt(n)) + 1;
    for (int i=0; i<n; i++) cin >> c[i];
    for (int i=0; i<n-1; i++) {
        int a, b; cin >> a >> b;
        a--; b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    memset(col, -1, sizeof(col));
    dfs(0, 0);

    for (int i=0; i<m; i++) {
        int v, k; cin >> v >> k;
        v--;
        arr[i] = data(ent[v], exi[v], k, i);
    }

    sort(arr, arr + m, cmp);

    for (int i=0; i<m; ) {
        memset(freq, 0, sizeof(freq));
        memset(num, 0, sizeof(num));
        int lt = arr[i].lt, rt = arr[i].rt;

        for (int j=arr[i].lt; j<=arr[i].rt; j++) {
            if (col[j] != -1) {
                num[++freq[col[j]]] ++;
            }
        }
        ans[arr[i].id] = num[arr[i].k];

        int j;
        for (j=i+1; j < m && arr[j].lt / len == arr[i].lt / len; j++) {
            while (lt < arr[j].lt) {
                if (col[lt] != -1)
                    num[freq[col[lt++]]--] --;
                else lt++;
            }
            while (lt > arr[j].lt) {
                if (col[lt-1] != -1)
                    num[++freq[col[--lt]]] ++;
                else lt--;
            }
            while (rt < arr[j].rt) {
                if (col[rt+1] != -1)
                    num[++freq[col[++rt]]] ++;
                else rt++;
            }
            ans[arr[j].id] = num[arr[j].k];
        }

        i = j;
    }

    for (int i=0; i<m; i++) cout << ans[i] << endl;
    return 0;
}