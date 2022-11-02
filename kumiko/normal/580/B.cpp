#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
#define ll long long

struct node{
    int m, s;
}p[100100];

int n, d;
ll tot, ans;

bool cmp(node  a, node b){
    return a.m < b.m;
}

int main(){
    scanf("%d%d", &n, &d);
    for(int i = 1; i <= n; i++) scanf("%d%d", &p[i].m, &p[i].s);
    sort(p + 1, p + n + 1, cmp);
    for(int i = 1, l = 1; i <= n; i++){
        tot += p[i].s;
        while(p[i].m - p[l].m >= d) tot -= p[l++].s;
        if (tot > ans) ans = tot;
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