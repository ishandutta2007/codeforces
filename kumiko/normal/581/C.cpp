#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
#define ll long long

const int maxn = 100100;
int n, k, a[maxn], b[maxn], c[maxn], tot;

int main(){
    scanf("%d%d", &n, &k);
    for(int i = 1; i <= n; i++){
        scanf("%d", &a[i]);
        b[i] = a[i] / 10;
        c[i] = (b[i] + 1) * 10 - a[i];
        tot += b[i];
    }
    sort(c + 1, c + n + 1);
    for(int i = 1; i <= n; i++){
        if (k >= c[i]) k -= c[i], tot++;
    }
    if (k) tot += k / 10;
    if (tot > 10 * n) tot = 10 * n;
    printf("%d\n", tot);
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