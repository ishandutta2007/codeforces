#include <bits/stdc++.h>

using namespace std;

const int N = 2020;

int n;
int x[N], y[N];
bool used[N];

long long ccw(int o,int u,int v) {
   return (long long) (x[u] - x[o]) * (y[v] - y[o]) - (long long) (x[v] - x[o]) * (y[u] - y[o]);
}

char dir[N];

int main() {
   scanf("%d", &n);
   for (int i = 1; i <= n; ++i) scanf("%d %d", x + i, y + i);
   vector<int> ans;
   int lst = 1;
   for (int i = 1; i <= n; ++i) {
      if (x[i] < x[lst]) lst = i;
   }
   ans.push_back(lst); used[lst] = true;
   scanf("%s", dir + 1);
   for (int i = 1; i <= n - 2; ++i) {
      int nxt = -1;
      if (dir[i] == 'L') {
         for (int j = 1; j <= n; ++j) if (!used[j]) {
            if (nxt == -1) nxt = j;
            else if (ccw(lst, j, nxt) > 0) nxt = j;
         }
      } else {
         for (int j = 1; j <= n; ++j) if (!used[j]) {
            if (nxt == -1) nxt = j;
            else if (ccw(lst, j, nxt) < 0) nxt = j;
         }
      }
      lst = nxt;
      ans.push_back(lst); used[lst] = true;
   }

   for (int i = 1; i <= n; ++i) if (!used[i]) ans.push_back(i);

   for (int v : ans) printf("%d ", v);
}