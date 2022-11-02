#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
#define ll long long

bool nop[1000100];
int pri[500000], tot;
int n;

void init(){
    ll ta;
    int n = 1000000;
    for(int i = 2; i <= n; i++){
        if (!nop[i]) pri[++tot] = i;
        for(int j = 1; j <= tot && (ta = (ll)pri[j] * i) <= n; j++){
            nop[ta] = 1;
            if (i % pri[j] == 0) break;
        }
    }
}

bool isp(int n){
    if (n <= 1) return 0;
    if (n <= 1000000) return !nop[n];
    int lim = (int)sqrt(n + 0.5);
    for(int i = 2; i <= lim; i++)
        if (n % i == 0) return 0;
    return 1;
}

int main(){
    scanf("%d", &n);
    init();
    if (isp(n)){
        printf("1\n%d", n);
    }else if (isp(n - 2)){
        printf("2\n2 %d", n - 2);
    }else{
        int i = 2;
        while(i <= tot && 2 * pri[i] <= n - 3 && !isp(n - 2 * pri[i])) i++;
        if (i > tot || 2 * pri[i] > n - 3 || !isp(n - 2 * pri[i])){
            for(int i = n / 2 - 1; i > 2; i--)
                if (isp(i) && isp(n - i * 2)){
                    printf("3\n");
                    printf("%d %d %d", n - i * 2, i, i);
                    break;
                }
        }else{
            printf("3\n");
            printf("%d %d %d", pri[i], pri[i], n - 2 * pri[i]);
        }
    }
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