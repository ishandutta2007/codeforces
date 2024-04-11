#include<stdio.h>
#include<string.h>
int main(void)
{
    int a,b,c,d;
    long int ans=0;
    char s[100005];
    scanf("%d%d%d%d%s",&a,&b,&c,&d,&s);
    for(int i=0;i<strlen(s);i++)
    {
        if(s[i]=='1') ans+=a;
        else if(s[i]=='2') ans+=b;
        else if(s[i]=='3') ans+=c;
        else if(s[i]=='4') ans+=d;
    }
    printf("%ld",ans);
}