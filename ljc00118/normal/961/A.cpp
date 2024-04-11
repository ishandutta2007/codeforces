#include<cstdio>
#define MAXN 1001
#define Rint register int
using namespace std;
int n, m, t, c[MAXN], ans = MAXN; 
int main(){
    scanf("%d%d", &n, &m);
    while(m --){
        scanf("%d", &t);
        c[t] ++;
    }
    for(Rint i = 1;i <= n;i ++)
        if(ans > c[i]) ans = c[i];
    printf("%d", ans); 
}