#include <stdio.h>
#include <algorithm>
#define pb push_back

int main(){
    #pragma comment(linker, "/STACK:268435456")
    #ifndef ONLINE_JUDGE
    freopen("input.txt","rt",stdin);
    freopen("output.txt","wt",stdout);
    #endif
    int a,b;
    scanf("%d%d",&a,&b);
    printf("%d",a+b);
}