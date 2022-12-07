#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<set>
using namespace std;
const int MAXN=200010;
const int N=2000000;
int pre[N+1];
int n,a[MAXN],ans;
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++) pre[a[i]]=a[i];
    for(int i=1;i<=N;i++)
        if(!pre[i]) pre[i]=pre[i-1];
    for(int i=1;i<=n;i++)
    {
        if(a[i]==a[i-1]) continue;
        for(int j=a[i]+a[i];j<=N;j+=a[i])
            ans=max(ans,a[i]-j+pre[j-1]);
    }
    printf("%d\n",ans);
    return 0;
}