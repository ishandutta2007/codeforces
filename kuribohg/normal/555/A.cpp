#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN=100010;
int n,k,tot,a[MAXN],ans;
int main()
{
    scanf("%d%d",&n,&k);
    ans=n+n-1-k;
    while(k--)
    {
        scanf("%d",&tot);
        for(int i=1;i<=tot;i++) scanf("%d",&a[i]);
        if(a[1]!=1) continue;
        int sub=1;
        while(sub+1<=tot&&a[sub+1]==sub+1) sub++;
        ans-=2*(sub-1);
    }
    printf("%d\n",ans);
    return 0;
}