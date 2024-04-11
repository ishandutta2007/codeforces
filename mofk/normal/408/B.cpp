#include<stdio.h>
#include<ctype.h>
#include<string.h>
int main(void)
{
    char s[1005],p[1005];int a[27]={0},b[27]={0};
    int i,ans=0,flag=0;
    scanf("%s%s",&s,&p);
    for(i=0;i<strlen(s);i++) a[toascii(s[i])-96]++;
    for(i=0;i<strlen(p);i++) b[toascii(p[i])-96]++;
    for(i=1;i<=26;i++)
    {
        if(a[i]==0&&b[i]!=0) flag=1;
        if(a[i]>=b[i]) ans+=b[i];
        else ans+=a[i];
    }
    if(flag==1) printf("-1");
    else printf("%d",ans);
}