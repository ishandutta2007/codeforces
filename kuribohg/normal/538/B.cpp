#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n,ans,pow[10],con[10];
char str[10];
int main()
{
    scanf("%s",str);
    n=strlen(str);
    for(int i=0;i<n;i++) ans=max(ans,str[i]-'0');
    pow[0]=1;
    for(int i=1;i<=9;i++) pow[i]=pow[i-1]*10;
    for(int i=0;i<n;i++)
        for(int j=1;j<=str[i]-'0';j++)
            con[j]+=pow[n-i-1];
    printf("%d\n",ans);
    for(int i=1;i<=ans;i++) printf("%d ",con[i]);
    return 0;
}