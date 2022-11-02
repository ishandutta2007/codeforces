#include <iostream> 
using namespace std;

const int maxN = 4000;
int t[maxN + 1], d[maxN + 1];
int f[maxN + 1][maxN + 1];
int n, k;
const int inf = 100 * 1000;

bool can(int timer) {
     bool ok = false;
     for(int i = 1; timer + i <= 86401 && !ok; ++i) {
             int l = 1, r = n;
             while(l < r - 1) {
                     int m = (l + r) / 2;
                     if(t[m] >= i)
                             r = m;
                     else
                         l = m;
             }
             if(t[l] >= i)
                     r = l;
             int curL = r; 
             l = curL, r = n;
             while(l < r - 1) {
                     int m = (l + r) / 2;
                     if(t[m] < timer + i)
                             l = m;
                      else
                          r = m;
             }
             if(t[r] < timer + i)
                     l = r;
             int curR = l;
             int cnt = (curR - curL + 1);
             if(t[curR] < i || t[curL] >= timer + i)
                        cnt = 0;
             cnt = max(cnt, 0);
             int pos = curL - 1;
             if(t[curL] < i)
                        pos++;
             if(pos <= 0) {
                    ok = (cnt <= k);
                    continue;
             }
             int d = k - cnt;
             if(d >= 0 && f[pos][d] < i) {
                  ok = true;
                  break;
             }
     }
     return ok;
}
             

int main() {
    ios_base::sync_with_stdio(0);
    cin >> n >> k;
    for(int i = 1; i <= n; ++i) 
            cin >> t[i] >> d[i];
    if(k == n) {
         cout << 86400;
         cin >> n;
         return 0;
    }
    for(int i = 0; i <= n; ++i)
            for(int j = 0; j <= k; ++j)
                    f[i][j] = inf;
    f[0][0] = 0;
    for(int i = 1; i <= n; ++i)
            for(int j = 0; j <= k; ++j) {
                    f[i][j] = min(max(t[i], f[i - 1][j] + 1) + d[i] - 1, j == 0 ? inf : f[i - 1][j - 1]);
                    if(f[i][j] > inf)
                               f[i][j] = inf;
            }
    for(int i = 0; i <= n; ++i)
            for(int j = 1; j <= k; ++j)
                  f[i][j] = min(f[i][j], f[i][j - 1]);
    int l = 0, r = 86400;
    while(l < r - 1) {
            int m = (l + r) / 2;
            if(can(m))
                      l = m;
            else
                r = m;
    }
    if(can(r))
              l = r;
    cout << l << endl;
    cin >> n;
    return 0;
}