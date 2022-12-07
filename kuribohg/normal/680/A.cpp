#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int a,b,c,d,e,res,ans;
int C[101];
int main()
{
    scanf("%d%d%d%d%d",&a,&b,&c,&d,&e);
    C[a]++,C[b]++,C[c]++,C[d]++,C[e]++,res+=a+b+c+d+e,ans=res;
    for(int i=1;i<=100;i++)
    {
        if(C[i]>=2) ans=min(ans,res-i*2);
        if(C[i]>=3) ans=min(ans,res-i*3);
    } 
    printf("%d\n",ans);
    return 0;
}