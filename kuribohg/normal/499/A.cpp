#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<cstring>
#include<queue>
#include<vector>
using namespace std;
const int MAXN=100010;
int n,x,l[MAXN],r[MAXN],t=1,sub,ans;
int main()
{
    scanf("%d%d",&n,&x);
    for(int i=1;i<=n;i++) scanf("%d%d",&l[i],&r[i]);
    sub=1;
    while(t<=r[n])
    {
        if(t+x<=l[sub]) t+=x;
        else t++,ans++;
        if(t>r[sub]) sub++;
    }
    printf("%d\n",ans);
    return 0;
}