#include <cstdio>
#include <iostream>
#include <string>
using namespace std;
const int N = 310;
int n;
char s[N];
int main(){
    int T; scanf("%d", &T);
    while(T--){
        scanf("%d%s", &n, s + 1);
        if(n == 2){
            if(s[1] >= s[2]) puts("NO");
            else printf("YES\n2\n%c  %c\n", s[1], s[2]);
        }else{

            printf("YES\n2\n%c ", s[1]);
            for(int i = 2; i <= n; i++) putchar(s[i]);
            puts("");
        }
    }
    return 0;
}