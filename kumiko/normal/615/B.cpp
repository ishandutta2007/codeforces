#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
#define ll long long

const int maxn = 200100;
int n, m, x, y, f[maxn], du[maxn];
vector<int> g[maxn];

int main(){
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= m; i++){
        scanf("%d%d", &x, &y);
        if (y < x) swap(x, y);
        g[y].push_back(x);
        du[x]++, du[y]++;
    }
    ll ans = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 0; j < (int)g[i].size(); j++)
            f[i] = max(f[i], f[g[i][j]] + 1);
        ans = max(ans, (ll)du[i] * (f[i] + 1));
    }
    printf("%I64d\n", ans);
  return 0;
}
/*
                   _ooOoo_
                  o8888888o
                  88" . "88
                  (| -_- |)
                  O\  =  /O
               ____/`---'\____
             .'  \\|     |//  `.
            /  \\|||  :  |||//  \
           /  _||||| -:- |||||-  \
           |   | \\\  -  /// |   |
           | \_|  ''\---/''  |   |
           \  .-\__  `-`  ___/-. /
         ___`. .'  /--.--\  `. . __
      ."" '<  `.___\_<|>_/___.'  >'"".
     | | :  `- \`.;`\ _ /`;.`/ - ` : | |
     \  \ `-.   \_ __\ /__ _/   .-` /  /
======`-.____`-.___\_____/___.-`____.-'======
                   `=---='
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
                BUG
*/