#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
const int MAXN=200010;
int n,a[MAXN],suf[MAXN],ans;
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    suf[n+1]=2000000000;
    for(int i=n;i>=1;i--) suf[i]=min(a[i],suf[i+1]);
    int L=1,R=1;
    while(L<=n)
    {
        R=L;
        int now=a[L];
        while(R+1<=n&&now>suf[R+1]) now=max(now,a[R+1]),R++;
        L=R+1,ans++;
    }
    printf("%d\n",ans);
    return 0;
}