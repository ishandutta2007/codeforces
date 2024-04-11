#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
#define ll long long

const int maxn = 2015;
int n, s[maxn], p[maxn], w[maxn];
int rt[maxn * 8], xx[maxn * maxn / 2], yy[maxn * maxn / 2], ans1, ans2;

void build(int t, int l, int r){
    if (l == r){
        rt[t] = p[l];
        return;
    }
    int mid = (l + r) >> 1;
    build(t << 1, l, mid);
    build((t << 1) + 1, mid + 1, r);
    rt[t] = min(rt[t << 1], rt[(t << 1) + 1]);
}

int ask(int t, int l, int r, int x, int y){
    if (x <= l && y >= r) return rt[t];
    int mid = (l + r) >> 1;
    if (x <= mid && y > mid) return min(ask(t << 1, l, mid, x, y), ask((t << 1) + 1, mid + 1, r, x, y));
    else if (x <= mid) return ask(t << 1, l, mid, x, y);
    else return ask((t << 1) + 1, mid + 1, r, x, y);
}

void modify(int t, int l, int r, int x, int y){
    if (l == r){
        rt[t] = y;
        return;
    }
    int mid = (l + r) >> 1;
    if (x <= mid) modify(t << 1, l, mid, x, y);
    else modify((t << 1) + 1, mid + 1, r, x, y);
    rt[t] = min(rt[t << 1], rt[(t << 1) + 1]);
}

int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) scanf("%d", p + i);
    for(int i = 1; i <= n; i++) scanf("%d", s + i), w[s[i]] = i;
    for(int i = 1; i <= n; i++) p[i] = w[p[i]], s[p[i]] = i;
    build(1, 1, n);
    for(int i = n, j; i >= 1; i--){
        j = s[i];
        while(j != i){
            int t = ask(1, 1, n, j + 1, i); t = s[t];
            ans1 += t - j;
            xx[++ans2] = t, yy[ans2] = j;
            swap(p[j], p[t]);
            s[p[j]] = j, s[p[t]] = t;
            modify(1, 1, n, j, p[j]);
            modify(1, 1, n, t, p[t]);
            j = t;
        }
    }
    printf("%d\n", ans1);
    printf("%d\n", ans2);
    for(int i = 1; i <= ans2; i++) printf("%d %d\n", xx[i], yy[i]);
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