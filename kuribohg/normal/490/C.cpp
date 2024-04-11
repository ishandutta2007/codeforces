#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<cstring>
#include<queue>
#include<vector>
using namespace std;
typedef long long LL;
int len;
LL pw[2000010],a,b;
LL suf[2000010],pre[2000010];
char str[2000010];
int main()
{
    scanf("%s%I64d%I64d",str,&a,&b);
    len=strlen(str);
    pw[0]=1;
    for(int i=1;i<=len;i++) pw[i]=(pw[i-1]*10)%b;
    pre[0]=(str[0]-'0')%a;
    for(int i=1;i<len;i++) pre[i]=(pre[i-1]*10+str[i]-'0')%a;
    for(int i=len-1;i>=0;i--) suf[i]=(suf[i+1]+(str[i]-'0')*pw[len-i])%b;
    for(int i=len-2;i>=0;i--)
        if(str[i+1]!='0'&&pre[i]==0&&suf[i+1]==0)
        {
            puts("YES");
            for(int j=0;j<=i;j++) putchar(str[j]);
            puts("");
            for(int j=i+1;j<len;j++) putchar(str[j]);
            return 0;
        }
    puts("NO");
    return 0;
}