#include <cstdio>
#include <cstring>
const int maxn=105;
int k;
long long p,res;
long long calc(int t)
{
    char temp[30];
    int i,len;
    long long ret;
    temp[0]='\0'; sprintf(temp,"%d",t);
    len=strlen(temp);
    temp[len+len]='\0';
    for(i=0;i<len;i++)
        temp[len+len-i-1]=temp[i];
    sscanf(temp,"%I64d",&ret);
    return ret;
}
int main()
{
    int i;
    res=0;
    scanf("%d%I64d",&k,&p);
    for(i=1;i<=k;i++)
        (res+=calc(i)%p)%=p;
    printf("%I64d\n",res);
    return 0;
}