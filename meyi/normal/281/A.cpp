#include<cstdio>
main(){
    char ch=getchar();
    putchar(ch>96?ch-32:ch);
    while(~(ch=getchar()))putchar(ch);
}