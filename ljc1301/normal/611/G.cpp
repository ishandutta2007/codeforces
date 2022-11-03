#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=500005;
const int kcz=1000000007;
int n;
ll x[maxn<<1],y[maxn<<1],sx[maxn<<1],sy[maxn<<1],ss[maxn<<1],ssk[maxn<<1];
inline ll area(ll xa,ll ya,ll xb,ll yb) { return xb*ya-xa*yb; }
int main()
{
    int i,j;
    ll ans,s=0,cur=0;
    scanf("%d",&n);
    for(i=1;i<=n;i++) scanf("%lld%lld",&x[i],&y[i]),x[i+n]=x[i],y[i+n]=y[i];
    for(i=1;i<=n;i++) s+=area(x[i],y[i],x[i+1],y[i+1]);
    // printf("%lld %lld\n",s,n*(ll)(n-3ll)/2%kcz);
    ans=s%kcz*(n*(ll)(n-3ll)/2%kcz)%kcz;
    for(i=1,sx[0]=sy[0]=ss[0]=ssk[0]=0;i<=(n<<1);i++)
    {
        sx[i]=(sx[i-1]+x[i]%kcz+kcz)%kcz,sy[i]=(sy[i-1]+y[i]%kcz+kcz)%kcz;
        if(i<(n<<1))
        {
            ss[i]=(ss[i-1]+area(x[i],y[i],x[i+1],y[i+1])%kcz+kcz)%kcz;
            ssk[i]=(ssk[i-1]+area(x[i],y[i],x[i+1],y[i+1])%kcz*i%kcz+kcz)%kcz;
        }
    }
    for(i=j=1;i<=n;i++)
    {
        while(j+1<n+i && (cur+area(x[j]-x[i],y[j]-y[i],x[j+1]-x[i],y[j+1]-y[i]))<=s/2)
            cur+=area(x[j]-x[i],y[j]-y[i],x[j+1]-x[i],y[j+1]-y[i]),j++;
        if(cur*2==s) (ans+=cur)%=kcz;
        // sum(k:i+1->j-1,(area(x[i],y[i],x[k],y[k])+area(x[k],y[k],x[k+1],y[k+1])+area(x[k+1],y[k+1],x[i],y[i]))*(j-k))
        // =-sum(k:i+2->j,S(i,k))+S(i,i+1)(k-i-1)+sum(k:i+1->j-1,S(k,k+1)(j-k))
        // ll temp=0;
        // for(int k=i+1;k<j;k++)
        // {
        //     printf("%lld ",area(x[i],y[i],x[k],y[k])+area(x[k],y[k],x[k+1],y[k+1])+area(x[k+1],y[k+1],x[i],y[i]));
        //     (temp+=(area(x[i],y[i],x[k],y[k])+area(x[k],y[k],x[k+1],y[k+1])+area(x[k+1],y[k+1],x[i],y[i]))*(j-k))%=kcz;
        // }
        // ans=(ans-2*temp%kcz+kcz)%kcz;
        // printf(": %lld\n",temp);
        ans=(ans-2*(-y[i]*(sx[j]-sx[i+1])%kcz+x[i]*(sy[j]-sy[i+1])%kcz+area(x[i],y[i],x[i+1],y[i+1])%kcz*(j-i-1)%kcz-(ssk[j-1]-ssk[i])%kcz+j*(ss[j-1]-ss[i])%kcz)%kcz+kcz)%kcz;
        // printf("%d %d %lld\n",i,j,(-y[i]*(sx[j]-sx[i+1])%kcz+x[i]*(sy[j]-sy[i+1])%kcz+area(x[i],y[i],x[i+1],y[i+1])%kcz*(j-i-1)%kcz-(ssk[j-1]-ssk[i])%kcz+j*(ss[j-1]-ss[i])%kcz)%kcz);
        cur-=area(x[i+1]-x[i],y[i+1]-y[i],x[j]-x[i],y[j]-y[i]);
    }
    printf("%lld\n",ans);
    return 0;
}