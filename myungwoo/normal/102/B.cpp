#include <stdio.h>

int ans=1;
char buf[100005];

int main()
{
    int i,n,k;
    scanf("%s",buf);
    for (i=n=0;buf[i];i++) n += buf[i]-'0';
    if (i == 1) puts("0");
    else{
        while (n >= 10){
            k = 0;
            for (;n;n/=10) k += n%10;
            n = k;
            ans++;
        }
        printf("%d",ans);
    }
}