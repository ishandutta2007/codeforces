#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
#define ll long long

int x[4], y[4];

int main(){
    for(int i = 1; i <= 3; i++) scanf("%d%d", x + i, y + i);
    bool ok = 0;
    for(int i = 0; i <= 7; i++){
        if (i & 1) swap(x[1], y[1]);
        if (i & 2) swap(x[2], y[2]);
        if (i & 4) swap(x[3], y[3]);
        
        if (x[1] == x[2] && x[2] == x[3] && x[1] == y[1] + y[2] + y[3]){
            ok = 1;
            printf("%d\n", x[1]);
            for(int j = 1; j <= y[1]; j++){
                for(int k = 1; k <= x[1]; k++) printf("A");
                printf("\n");
            }
            for(int j = 1; j <= y[2]; j++){
                for(int k = 1; k <= x[1]; k++) printf("B");
                printf("\n");
            }
            for(int j = 1; j <= y[3]; j++){
                for(int k = 1; k <= x[1]; k++) printf("C");
                printf("\n");
            }
            break;
        }else if (x[1] == x[2] + x[3] && y[2] == y[3] && y[1] + y[2] == x[1]){
            ok = 1;
            printf("%d\n", x[1]);

            for(int j = 1; j <= y[1]; j++){
                for(int k = 1; k <= x[1]; k++)
                    printf("A");
                printf("\n");
            }

            for(int j = 1; j <= y[2]; j++){
                for(int k = 1; k <= x[2]; k++) printf("B");
                for(int k = 1; k <= x[3]; k++) printf("C");
                printf("\n");
            }

            break;
        }else if(x[2] == x[1] + x[3] && y[1] == y[3] && y[2] + y[1] == x[2]){
            ok = 1;
            printf("%d\n", x[2]);
            for(int j = 1; j <= y[2]; j++){
                for(int k = 1; k <= x[2]; k++)
                    printf("B");
                printf("\n");
            }

            for(int j = 1; j <= y[1]; j++){
                for(int k = 1; k <= x[1]; k++) printf("A");
                for(int k = 1; k <= x[3]; k++) printf("C");
                printf("\n");
            }
            break;
        }else if(x[3] == x[1] + x[2] && y[1] == y[2] && y[3] + y[1] == x[3]){
            ok = 1;

            printf("%d\n", x[3]);
            for(int j = 1; j <= y[3]; j++){
                for(int k = 1; k <= x[3]; k++)
                    printf("C");
                printf("\n");
            }

            for(int j = 1; j <= y[1]; j++){
                for(int k = 1; k <= x[1]; k++) printf("A");
                for(int k = 1; k <= x[2]; k++) printf("B");
                printf("\n");
            }
            break;
        }
        if (i & 1) swap(x[1], y[1]);
        if (i & 2) swap(x[2], y[2]);
        if (i & 4) swap(x[3], y[3]);
    }
    if (!ok) printf("-1\n");
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