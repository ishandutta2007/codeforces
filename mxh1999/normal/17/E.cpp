//Author:mxh1999
//
#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

const int mo=51123987;
const int maxn=2000010;
typedef long long ll;

char s[maxn];
int p[maxn],d[maxn];
int sum,tmp1[maxn],tmp2[maxn],tmp3[maxn],tmp4[maxn];
int start[maxn],final[maxn];
int n;

int main()
{
    //freopen("A1393.in","r",stdin);
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
    {
        char ch=getchar();
        while (ch<'a' || ch>'z')    ch=getchar();
        s[i]=ch;
    }
    int l=0,r=0;
    for (int i=1;i<=n;i++)
    {
        if (i<=r)
        {
            int pos=l+r-i;
            if (pos-p[pos]+1>l) p[i]=p[pos];else
            if (pos-p[pos]+1<l) p[i]=r-i+1;else
            {
                int rr=r,ll=2*i-r;
                p[i]=r-i;
                while (rr<=n && ll>0 && s[ll]==s[rr])   p[i]++,rr++,ll--;
                if (rr>r)   l=ll+1,r=rr-1;
            }
        }   else
        {
            int ll=i,rr=i;p[i]=0;
            while (rr<=n && ll>0 && s[ll]==s[rr])   p[i]++,rr++,ll--;
            if (rr>r)   l=ll+1,r=rr-1;
        }
        if (i<r)
        {
            int mid=(l+r)/2;
            int pos=mid*2-i-(l+r+1)%2;
            if (pos-d[pos]+1>l) d[i]=d[pos];else
            if (pos-d[pos]+1<l) d[i]=r-i;else
            {
                int rr=r,ll=2*i-r+1;
                d[i]=r-i-1;
                while (rr<=n && ll>0 && s[ll]==s[rr])   d[i]++,rr++,ll--;
                if (rr>r)   l=ll+1,r=rr-1;
            }
        }   else
        {
            int ll=i,rr=i+1;
            d[i]=0;
            while (rr<=n && ll>0 && s[ll]==s[rr])   d[i]++,rr++,ll--;
            if (rr>r)   l=ll+1,r=rr-1;
        }
    }
    for (int i=1;i<=n;i++)
    {
        int ll=i-p[i]+1,rr=i+p[i]-1;
        if (ll<=i)  tmp1[ll]++,tmp2[i]++,tmp3[i]++,tmp4[rr]++;
        sum+=p[i];
        sum%=mo;
        ll=i-d[i]+1,rr=i+d[i];
        if (ll<=i)  tmp1[ll]++,tmp2[i]++,tmp3[i+1]++,tmp4[rr]++;
        sum+=d[i];
        sum%=mo;
    }
    //for (int i=1;i<=n;i++)    printf("%d %d\n",p[i],d[i]);
    ll ans=0;
    ans=sum-1;
    ans*=sum;
    ans/=2;
    ans%=mo;
    //cout<<ans<<endl;
    int q=0;
    for (int i=1;i<=n;i++)
    {
        q+=tmp1[i];
        start[i]=q;
        q-=tmp2[i];
        //cout<< start[i] << " ";
    }
    //cout << endl;
    q=0;
    for (int i=n;i>=1;i--)
    {
        q+=tmp4[i];
        final[i]=q;
        q-=tmp3[i];
        //cout<< final[i] << " ";
    }
    //cout<<endl;
    q=0;
    for (int i=1;i<=n;i++)
    {
        ll tmp=start[i];
        tmp*=q;
        tmp%=mo;
        ans-=tmp;
        ans%=mo;
        q+=final[i];
        q%=mo;
    }
    while (ans<0)   ans+=mo;
    cout<<ans<<endl;
}