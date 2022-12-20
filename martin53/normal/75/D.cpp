#include<bits/stdc++.h>
using namespace std;
const int mmax=25e4+42,lmax=5e3+42,nmax=55;
int n,m;
int arr[mmax];
int l,inp[lmax];
long long pref[nmax],suf[nmax],alone[nmax];
long long total[nmax];
int maxi[nmax];
long long divide_and_conquer(int l,int r)
{
    if(l==r)
    {
    //cout<<l<<" -> "<<alone[arr[l]]<<endl;
    return alone[arr[l]];
    }
    int av=(l+r)/2;
    long long ans=max(divide_and_conquer(l,av),divide_and_conquer(av+1,r));
    long long max_left=0,sum_left=0;
    for(int j=av;j>=l;j--)
    {
        max_left=max(max_left,sum_left+suf[arr[j]]);
        sum_left=sum_left+total[arr[j]];
    }

    long long max_right=0,sum_right=0;
    for(int j=av+1;j<=r;j++)
    {
        max_right=max(max_right,sum_right+pref[arr[j]]);
        sum_right=sum_right+total[arr[j]];
    }
    ans=max(ans,max_left+max_right);
    //cout<<l<<" "<<r<<" -> "<<ans<<endl;
    return ans;
}
int main()
{
scanf("%i%i",&n,&m);
for(int i=1;i<=n;i++)
{
    scanf("%i",&l);
    for(int j=1;j<=l;j++)scanf("%i",&inp[j]);
    maxi[i]=inp[1];
    for(int j=2;j<=l;j++)
        maxi[i]=max(maxi[i],inp[j]);
    long long sum=0;
    for(int j=1;j<=l;j++)
    {
        sum=sum+inp[j];
        pref[i]=max(pref[i],sum);
    }
    sum=0;
    for(int j=l;j>=1;j--)
    {
        sum=sum+inp[j];
        suf[i]=max(suf[i],sum);
    }
    total[i]=sum;
    sum=0;
    long long best=0;
    for(int j=1;j<=l;j++)
    {
        sum=max(sum+inp[j],1LL*inp[j]);
        best=max(best,sum);
    }
    alone[i]=best;
}
bool non_neg=0;
int MAXI=-1e9;
for(int i=1;i<=m;i++)
{
scanf("%i",&arr[i]);
MAXI=max(MAXI,maxi[arr[i]]);
}
if(MAXI<0)printf("%i\n",MAXI);
else printf("%lld",divide_and_conquer(1,m));
return 0;
}