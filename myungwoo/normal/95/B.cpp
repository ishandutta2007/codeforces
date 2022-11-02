#include <stdio.h>
#include <string.h>

#define MAXN 100005

int N,four[MAXN],svn[MAXN];
char buf[MAXN];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
#endif
    int i,j,k,a=0,b=0;
    scanf("%s",buf), N = strlen(buf);
    if (N&1){
        for (i=N;i;i--) buf[i] = buf[i-1];
        buf[0] = '0';
        buf[++N] = 0;
    }
    for (i=0;i<N;i++){
        four[i] = a, svn[i] = b;
        if (buf[i] == '4') a++;
        else if (buf[i] == '7') b++;
    }
    if (a+b == N && a == b){ puts(buf); return 0; }
    for (i=N;i--;){
        a = four[i], b = svn[i];
        if (a+b != i || a > N/2 || b > N/2) continue;
        k = 0;
        if (buf[i] < '4' && a < N/2) k = 4;
        else if (buf[i] < '7' && b < N/2) k = 7;
        if (!k) continue;
        for (j=0;j<i;j++) printf("%c",buf[j]);
        printf("%c",'0'+k);
        if (k == 4) a++;
        else b++;
        for (j=i+1;j<N;j++){
            if (a < N/2) a++, printf("4");
            else b++, printf("7");
        }
        return 0;
    }
    for (i=0;i<N/2+1;i++) printf("4");
    for (i=0;i<N/2+1;i++) printf("7");
}