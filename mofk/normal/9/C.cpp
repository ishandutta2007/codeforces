#include<stdio.h>
#include<string.h>
#include<math.h>
int main(void)
{
    int i,ans=0;
    long int in;
    char n[13];
    scanf("%s",&n);
    for(i=0;i<strlen(n);i++) if(n[i]>'1') break;
    for(;i<strlen(n);i++) n[i]='1';
    for(i=0;i<strlen(n);i++) if(n[i]=='1') ans+=pow(2,strlen(n)-1-i);
    printf("%d",ans);
}