#include <stdio.h>
#include <string.h>

int N,sc,ans=-1e9;
char buf[99],str[99];

int main()
{
    int i,j,k;
    scanf("%d",&N);
    for (i=1;i<=N;i++){
        scanf("%s%d%d",buf,&j,&k);
        sc = 100*j-50*k;
        for (j=0;j<5;j++) scanf("%d",&k), sc += k;
        if (ans < sc) ans = sc, strcpy(str,buf);
    }
    printf("%s",str);
}