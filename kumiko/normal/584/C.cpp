#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
#define ll long long

int n, t;
char s1[100100], s2[100100], s3[100100];

int main(){
    scanf("%d%d", &n, &t);
    t = n - t;
    scanf("%s", s1 + 1);
    scanf("%s", s2 + 1);
    int m = 0;
    for(int i = 1; i <= n; i++) if (s1[i] == s2[i]) m++;
    if (t > m + (n - m) / 2) printf("-1");
    else{
        for(int i = 1; i <= n; i++)
            if (s1[i] == s2[i] && t){
                t--;
                s3[i] = s1[i];
            }else{
                s3[i] = 'a';
                while(s3[i] == s1[i]) s3[i]++;
            }
        bool tag = 0;
        for(int i = 1; i <= n; i++)
            if (s1[i] != s2[i]){
                if (t){
                    if (tag){
                        t--;
                        s3[i] = s2[i];
                        tag = 0;
                    }else{
                        s3[i] = s1[i];
                        tag = 1;
                    }
                }else{
                    s3[i] = 'a';
                    while(s3[i] == s1[i] || s3[i] == s2[i]) s3[i]++;
                }
            }
        printf("%s", s3 + 1);
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