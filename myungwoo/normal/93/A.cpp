#include <stdio.h>

int N,M,A,B,ans;

int main()
{
    int s,e,t1,t2,nt;
    scanf("%d%d%d%d",&N,&M,&A,&B);
    s = (A-1)%M+1; t1 = (A-1)/M+1;
    e = (B-1)%M+1; t2 = (B-1)/M+1;
    nt = (N-1)/M+1;
    if (t2 == nt && B == N) e = M;
    if (t1 == t2){ puts("1"); return 0; }
    else if (t2-t1 == 1){
        if (s == 1 && e == M) puts("1");
        else puts("2");
        return 0;
    }
    if (s == 1 && e == M){ puts("1"); return 0; }
    if (e+1 == s){ puts("2"); return 0; }
    if (s != 1) ans++;
    else s = M+1;
    if (t1 != t2 && e != M) ans++;
    else e = 0;
    if (t2-t1 > 1) ans++;
    printf("%d",ans);
}