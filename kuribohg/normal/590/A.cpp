#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN=500010;
int n,a[MAXN],b[MAXN],l,r,ans;
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]),b[i]=a[i];
    for(int i=2;i<=n;i+=2) b[i]^=1;
    l=1;
    while(l<=n)
    {
        r=l;
        while(r+1<=n&&b[r+1]==b[l]) r++;
        int len=r-l+1;
        ans=max(ans,(len-1)>>1);
        if(a[l]==a[r])
        {
            for(int i=l+1;i<=r;i++)
                a[i]=a[l];
        }
        else
        {
            for(int i=l;i<l+(len>>1);i++)
                a[i]=a[l];
            for(int i=r;i>r-(len>>1);i--)
                a[i]=a[r];
        }
        l=r+1;
    }
    printf("%d\n",ans);
    for(int i=1;i<=n;i++) printf("%d ",a[i]);
    puts("");
    return 0;
}