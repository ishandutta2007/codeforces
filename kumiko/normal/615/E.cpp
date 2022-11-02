#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
#define ll long long

ll n;

int main(){
    scanf("%I64d", &n);
    int l = 0, r = 1000000000;
    while(l + 1 < r){
        int mid = (l + r) / 2;
        if ((ll)mid * (mid + 1) * 3 >= n) r = mid;
        else l = mid;
    }l++;
    
    ll re = n - (ll)l * (l - 1) * 3;
    int x, y;
    int quan = (re - 1) / l;
    int wei = re - (ll)l * quan;
    
    if (quan == 5){
        x = l, y = -2 * l;
        x += wei, y += 2 * wei;
    }else if (quan == 4){
        x = -l, y = -2 * l;
        x += 2 * wei;
    }else if (quan == 3){
        x = -2 * l, y = 0;
        x += wei, y -= 2 * wei;
    }else if (quan == 2){
        x = -l, y = 2 * l;
        x -= wei, y -= 2 * wei;
    }else if (quan == 1){
        x = l, y = 2 * l;
        x -= 2 * wei;
    }else if (quan == 0){
        x = 2 * l, y = 0;
        if (wei == 0){
            x -= 2;
        }else{
            x -= wei, y += 2 * wei;
        }
    }
    if (n == 0) x = 0, y = 0;
    printf("%d %d\n", x, y);
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