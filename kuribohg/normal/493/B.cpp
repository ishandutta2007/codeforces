#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<cstring>
#include<queue>
#include<vector>
using namespace std;
const int MAXN=1000010;
int n,last,a[MAXN],alen,b[MAXN],blen,len;
long long asum,bsum;
int main()
{
    scanf("%d",&n);
    for(int i=1,x;i<=n;i++)
    {
        scanf("%d",&x);
        if(x>0) a[++alen]=x,last=1,asum+=(long long)x;
        else b[++blen]=-x,last=2,bsum-=(long long)x;
    }
    if(asum>bsum) {puts("first");return 0;}
    else if(asum<bsum) {puts("second");return 0;}
    len=max(alen,blen);
    for(int i=1;i<=len;i++)
    {
        if(a[i]>b[i]) {puts("first");return 0;}
        else if(a[i]<b[i]) {puts("second");return 0;}
    }
    if(last==1) puts("first");
    else puts("second");
    return 0;
}