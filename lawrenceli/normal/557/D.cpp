#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int maxn = 100100;

int n, m;
vector<int> adj[maxn];
int col[maxn], num[2];
ll ans;

void dfs(int cur, int c=0) {
    if (col[cur] != -1) {
        if (col[cur] != c) {
            cout << "0 1\n";
            exit(0);
        }
        return;
    }

    col[cur] = c;
    num[c]++;
    for (int i : adj[cur])
        dfs(i, !c);
}

int main() {
   cin >> n >> m;
   for (int i=0; i<m; i++) {
       int a, b;
       cin >> a >> b;
       adj[a].push_back(b);
       adj[b].push_back(a);
    }

   if (m == 0) {
       cout << 3 << ' ' << ll(n)*(n-1)*(n-2)/6 << '\n';
       return 0;
    }

   memset(col, -1, sizeof(col));
   int ma = 0;
   for (int i=1; i<=n; i++)
       if (col[i] == -1) {
           num[0] = num[1] = 0;
           dfs(i);
           ans += ll(num[0])*(num[0]-1)/2;
           ans += ll(num[1])*(num[1]-1)/2;
           ma = max(ma, num[0]+num[1]);
        }

    if (ma > 2) {
        cout << 1 << ' ' << ans << '\n';
    } else cout << 2 << ' ' << ll(m)*(n-2) << '\n';
}