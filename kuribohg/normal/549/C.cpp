#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n,k,x,ft,st,oddn,even;
void lastwin()
{
    if((n-k)&1) puts("Stannis");
    else puts("Daenerys");
}
void firstwin()
{
    if((n-k)&1) puts("Daenerys");
    else puts("Stannis");
}
int main()
{
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&x);
        if(x&1) oddn++;
        else even++;
    }
    if(n==k)
    {
        if(oddn&1) puts("Stannis");
        else puts("Daenerys");
        return 0;
    }
    ft=(n-k)/2;
    st=n-k-ft;
    if(ft<oddn&&ft<even) {lastwin();return 0;}
    if(ft>=oddn) {puts("Daenerys");return 0;}
    if(ft>=even)
    {
        oddn-=n-k-even;
        if(oddn&1) puts("Stannis");
        else puts("Daenerys");
    }
    return 0;
}