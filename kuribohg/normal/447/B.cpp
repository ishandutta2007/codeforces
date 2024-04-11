#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<cstring>
#include<queue>
#include<vector>
using namespace std;
char str[100010];
long long ans,w[30],len,k,p;
int main()
{
    scanf("%s%I64d",str,&k);
    len=strlen(str);
    for(int i=0;i<26;i++) scanf("%I64d",&w[i]);
    for(int i=0;i<len;i++) ans+=w[str[i]-'a']*(i+1);
    for(int i=0;i<26;i++) if(w[i]>p) p=w[i];
    ans+=p*(len+1+len+k)*k/2;
    printf("%I64d\n",ans);
    return 0;
}