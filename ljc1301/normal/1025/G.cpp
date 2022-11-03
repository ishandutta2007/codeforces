#include <bits/stdc++.h>
using namespace std;
const int maxn=505;
const int kcz=1000000007;
int n,a[maxn],cnt[maxn],p2[maxn];
// n=1: 0=0
// n=2: 00=1 1=0
// n=3: 000=3 01=2 2=0
// n=4: (solve equations) 0000=7 100=6 11=5 20=4 3=0
// n=5: 00000=15 1000=14 200=12 110=13 30=8 21=11 4=0
// 2^(n-1)-1-sum(2^x-1)
// a,b(-2^a+1-2^b+1) -> 1/2*(-2^(a+1)+1-2^(b+1)+1)
//                    = -2^a-2^b+1
int main()
{
    int i,ans;
    scanf("%d",&n);
    for(i=1,p2[0]=1;i<=n;i++) cnt[i]=0,p2[i]=(p2[i-1]<<1)%kcz;
    for(i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        if(a[i]!=-1) cnt[a[i]]++;
    }
    ans=p2[n-1]-1;
    for(i=1;i<=n;i++)
        if(a[i]==-1)
            ans=(ans+kcz-p2[cnt[i]]+1)%kcz;
    printf("%d\n",ans);
    return 0;
}