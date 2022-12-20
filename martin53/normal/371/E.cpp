#include<bits/stdc++.h>
using namespace std;
const int nmax=3e5+42;
int n,k;
pair<int/*value*/,int/*index*/> inp[nmax];
int main()
{
scanf("%i",&n);
for(int i=1;i<=n;i++)
{
    scanf("%i",&inp[i].first);
    inp[i].second=i;
}
scanf("%i",&k);
sort(inp+1,inp+n+1);
long long ans=0,sum=0,ind=1;
for(int i=1;i<=k;i++)
{
    sum=sum+inp[i].first;
    ans=ans+1LL*i*inp[i].first-sum;
}
//cout<<1<<" "<<ans<<endl;
long long now=ans;
for(int i=2;i+k-1<=n;i++)
{
    now=now-(sum-1LL*k*inp[i-1].first);
    sum=sum-inp[i-1].first+inp[i+k-1].first;
    now=now+(1LL*k*inp[i+k-1].first-sum);
    if(now<ans)
    {
        ans=now;
        ind=i;
    }
    //cout<<i<<" "<<now<<" "<<sum<<endl;
}
for(int i=ind;i<ind+k;i++)
    printf("%i ",inp[i].second);
printf("\n");
return 0;
}