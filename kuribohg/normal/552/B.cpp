#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long LL;
LL n,Pow[20],ans;
int main()
{
    scanf("%I64d",&n);
    Pow[0]=1;
    for(int i=1;i<=10;i++) Pow[i]=Pow[i-1]*10;
    for(int i=0;i<=10;i++) if(n>=Pow[i]) ans+=n-Pow[i]+1;
    printf("%I64d\n",ans);
    return 0;
}