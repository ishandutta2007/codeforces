#include <stdio.h>
#include <vector>
using namespace std;
#define S 1000005

int n;
char s[S];
int arr[S];

int main(void){
    int i, cnt = 0;
    scanf(" %s", s+1); n = strlen(s+1);
    for(i=1; i<=n; i++) arr[i] = s[i]-'0';
    i = n;
    while(n>1 && i>=1){
        int inc = 0;
        while(arr[i] == 1){
            i --;
            inc ++;
            n --;
        }
        if(inc > 0){ arr[i] = 1; cnt += inc+1;}
        while(arr[i] == 0){
            i --;
            n --;
            cnt ++;
        }
    }
    printf("%d\n", cnt);
    return 0;
}