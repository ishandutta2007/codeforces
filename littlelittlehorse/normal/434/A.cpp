#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, m, a[100001], c[200001];
vector<int> events[100001];

int main(){
     //freopen("a.in", "r", stdin);
     //freopen("a.out", "w", stdout);
     scanf("%d%d", &n, &m);
     for (int i = 1; i <= n; i++) events[i].clear();
     for (int i = 1; i <= m; ++i) scanf("%d", &a[i]), events[a[i]].push_back(i);
     long long ans = 0;
     for (int i = 1; i < m; i++) ans += abs(a[i] - a[i + 1]); 
     long long init = ans;
     for (int Q = 1; Q <= n; Q++)
          if (events[Q].size())
          {
               int cnt = 0;
               for (int j = 0; j < events[Q].size(); j++)
               {
                    if (events[Q][j] != 1) c[++cnt] = a[events[Q][j] - 1];
                    if (events[Q][j] != m) c[++cnt] = a[events[Q][j] + 1];
               }
               sort(c + 1, c + cnt + 1);
               long long now = init;
               for (int i = 1; i <= cnt; i++) now -= abs(Q - c[i]);                     
               int L = 1, R = n, Mid1 = (R - L) / 3 + L, Mid2 = (R - L) / 3 * 2 + L;
               for (; L + 2 < R;)
               {
                    long long now1 = now, now2 = now;
                    for (int i = 1; i <= cnt; i++) 
                         if (c[i] != Q) now1 += abs(Mid1 - c[i]), now2 += abs(Mid2 - c[i]);
                    if (now1 > now2) L = Mid1;
                    else R = Mid2;
                     Mid1 = (R - L) / 3 + L; Mid2 = (R - L) / 3 * 2 + L;
               }
               for (int j = L; j <= R; j++)
               {
                    long long now1 = now;
                    for (int i = 1; i <= cnt; i++) 
                         if (c[i] != Q) now1 += abs(j - c[i]);
                    ans = min(ans, now1);
               }
          }
     cout << ans << endl;
}