#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
#define ll long long

const int maxn = 200100;
int a[maxn], to[maxn], he[maxn], ne[maxn], n, m, ans, tot;

void link(int x, int y){
    to[++tot] = y, ne[tot] = he[x], he[x] = tot;
}

void dfs(int t, int c, int fa){
    if (a[t]) c++;
    else c = 0;
    if (c > m) return;
    bool ok = 1;
    for(int i = he[t]; i; i = ne[i])
        if (to[i] != fa){
            dfs(to[i], c, t);
            ok = 0;
        }
    if (ok) ans++;
}

int main(){
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++) scanf("%d", a + i);
    int x, y;
    for(int i = 1; i < n; i++){
        scanf("%d%d", &x, &y);
        link(x, y);
        link(y, x);
    }
    dfs(1, 0, 0);
    printf("%d\n", ans);
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