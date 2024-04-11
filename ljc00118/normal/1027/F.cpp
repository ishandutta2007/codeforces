#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 2000010;

vector<int> abc[N], edg[N];
int a[N], x[N], y[N], used[N];
int tot, n;
int ioi, cstc, mx1, mx2;
int tt[N];

void addedge(int x,int y) {
    abc[x].push_back(y);
    abc[y].push_back(x);
    edg[x].push_back(++tot);
    edg[y].push_back(tot);
}

void dfs(int x) {
    used[x] = 1;
    
    ioi++;
    
    if(a[x] + 1 >= mx1 + 1) {
        mx2 = mx1;
        mx1 = a[x];
    }
    else mx2 = max(mx2, a[x]);
    
    for(int i = 0; i < abc[x].size(); i++) {
    	int v = edg[x][i];
        if(tt[v] == 0) {
            tt[v] = 1;
            cstc++;
            if(!used[abc[x][i]]) dfs(abc[x][i]);
        }
    }
}

int main() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        scanf("%d %d", &x[i], &y[i]);
        a[i * 2] = x[i];
        a[i * 2 - 1] = y[i];
    } 
    sort(a + 1, a + (n << 1) + 1);
    int m = unique(a + 1, a + (n << 1) + 1) - a - 1;
    for(int i = 1; i <= n; i++) {
        x[i] = lower_bound(a + 1, a + m + 1, x[i]) - a;
        y[i] = lower_bound(a + 1, a + m + 1, y[i]) - a;
    }  
    for(int i = 1; i <= n; i++) addedge(x[i], y[i]);
    int ans = 0;
    for(int i = 1; i <= m; i++) {
    	if(!used[i]) used[i] = 1, used[i] = 0;
        if(!used[i]) {
            ioi = cstc = mx1 = mx2 = 0; dfs(i);
            if(ioi - 1 == cstc) ans = max(ans, mx2);
            else if(ioi == cstc) ans = max(ans, mx1);
            else {
                puts("-1");
                return 0;
            }
        }
    }
    cout << ans << endl;
    return 0;
}