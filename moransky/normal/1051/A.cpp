#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int N = 110;
char str[N];
int sum[3][N], n;
int inline get(char x){
    if(x <= '9' && x >= '0') return 0;
    else if(x >= 'a' && x <= 'z') return 1;
    return 2;
}
void change(int pos, int x){
    if(x == 0) str[pos] = '0';
    else if(x == 1) str[pos] = 'a';
    else str[pos] = 'A';
}
int main(){
    int T; scanf("%d", &T);
    while(T--){
        scanf("%s", str + 1);
        n = strlen(str + 1);
        for(int i = 1; i <= n; i++){
            for(int j = 0; j < 3; j++) sum[j][i] = sum[j][i - 1];
            sum[get(str[i])][i]++; 
        }
        int cnt = 0;
        for(int i = 0; i < 3; i++) if(!sum[i][n]) cnt++;
        if(cnt){
            int tot = 0, l = 1, r = 1 + cnt - 1;
            for(int i = l; i <= r; i++){
                if(sum[get(str[i])][n] == 1) {
                    r++; continue;
                }
                while(sum[tot][n]) tot ++;
                change(i, tot++);
            }
        }
        printf("%s\n", str + 1);
    }
    return 0;
}