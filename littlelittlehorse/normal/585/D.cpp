#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

struct node {
     int l, m, w, value;
     bool operator < (const node &A) const {
          if (l - m != A.l - A.m) return l - m < A.l - A.m;
          if (m - w != A.m - A.w) return m - w < A.m - A.w;
          return l < A.l;
     }  
} c[5000001];
map< pair<int, int>, pair<int, int> > events;
int n, a[101][3], cnt, r[101];

inline void soso(int step, int n, int l, int m, int w, int value) {
     if (step == n + 1) {
          c[++cnt].l = l; c[cnt].m = m; c[cnt].w = w; c[cnt].value = value;
          return;
     }
     soso(step + 1, n, l + a[step][0], m + a[step][1], w, value * 3);
     soso(step + 1, n, l + a[step][0], m, w + a[step][2], value * 3 + 1);
     soso(step + 1, n, l, m + a[step][1], w + a[step][2], value * 3 + 2);
}

int main() {
     //freopen("d.in", "r", stdin);
     //freopen("d.out", "w", stdout);
     scanf("%d", &n);
     for (int i = 1; i <= n; i++) 
          for (int j = 0; j < 3; j++) scanf("%d", &a[i][j]);
     cnt = 0;
     soso(1, n / 2, 0, 0, 0, 0);
     events.clear();
     for (int i = 1; i <= cnt; i++) {
          pair<int, int> num = make_pair(c[i].l - c[i].m, c[i].m - c[i].w),
                         in = make_pair(c[i].l, c[i].value);
          if (events.find(num) == events.end() || events[num].first < in.first)
               events[num] = in;
     }
     cnt = 0;
     soso(n / 2 + 1, n, 0, 0, 0, 0);
     int ans = -1 << 30, value1 = 0, value2 = 0;
     for (int i = 1; i <= cnt; i++) {
          pair<int, int> num = make_pair(c[i].m - c[i].l, c[i].w - c[i].m),
                         in = make_pair(c[i].l, c[i].value);
          if (events.find(num) == events.end()) continue;
          if (events[num].first + c[i].l > ans) ans = events[num].first + c[i].l,
          value1 = events[num].second, value2 = c[i].value;
     }
     if (ans == -1 << 30) printf("Impossible\n");
     else {
          int len = 0;
          for (int i = n; i > n / 2; --i) r[++len] = value2 % 3, value2 /= 3;
          for (int i = n / 2; i; --i) r[++len] = value1 % 3, value1 /= 3;
          for (int i = len; i; --i) 
               if (!r[i]) printf("LM\n");
               else if (r[i] == 1) printf("LW\n");
               else printf("MW\n");
     }
}