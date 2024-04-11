#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
#define ll long long
#define M 1000000007

const int maxn = 200100;
int m, p[maxn], tot;
int pri[maxn], num[maxn];
int cal[maxn];
int pre[maxn], nex[maxn];

int pow(int a, int b, int mm){
    int ans = 1;
    for(; b; b >>= 1, a = (ll)a * a % mm)
        if (b & 1) ans = (ll)ans * a % mm;
    return ans;
}

int main(){
    scanf("%d", &m);
    for(int i = 1; i <= m; i++) scanf("%d", p + i);
    sort(p + 1, p + m + 1);
    for(int i = 2, j = 1; i <= m + 1; i++){
        if (p[i] == p[i - 1]) j++;
        else{
            pri[++tot] = p[i - 1];
            num[tot] = j;
            cal[j]++;
            j = 1;
        }
    }
    
    pre[0] = nex[200001] = 1;
    for(int i = 1; i <= 200000; i++){
        pre[i] = pre[i - 1];
        for(int j = 1; j <= cal[i]; j++)
            pre[i] = (ll)pre[i] * (i + 1) % (M - 1);
    }
    for(int i = 200000; i >= 1; i--){
        nex[i] = nex[i + 1];
        for(int j = 1; j <= cal[i]; j++)
            nex[i] = (ll)nex[i] * (i + 1) % (M - 1);
    }
 
    int ans = 1;
    for(int i = 1; i <= tot; i++){
        int ta = (ll)pre[num[i] - 1] * nex[num[i] + 1] % (M - 1) * pow(num[i] + 1, cal[num[i]] - 1, M - 1) % (M - 1);
        int tb = (ll)num[i] * (num[i] + 1) / 2 % (M - 1);
        tb = (ll)ta * tb % (M - 1);
        ans = (ll)ans * pow(pri[i], tb, M) % M;
    }
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