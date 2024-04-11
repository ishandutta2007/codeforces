#include<bits/stdc++.h>
using namespace std;
const int nmax=5e5+42;
int n,r,arr[nmax];
long long k;
long long help[nmax*3];
bool can(long long aim)
{
    memset(help,0,sizeof(help));
    for(int i=1;i<=n;i++)
        help[i+nmax]=arr[i];
    long long sum=0;
    for(int i=0;i<=r;i++)
        sum=sum+help[i+nmax];
    long long war=k;
    for(int i=1;i<=n;i++)
    {
        sum=sum-help[i-r-1+nmax]+help[i+r+nmax];
        //cout<<i<<" "<<sum<<" "<<aim<<" "<<war<<endl;
        if(sum<aim)
        {
            war=war-(aim-sum);
            if(war<0)return 0;
            help[i+r+nmax]=help[i+r+nmax]+aim-sum;
            sum=aim;
        }
        //cout<<"help: ";for(int j=1;j<=n;j++)cout<<help[j+nmax]<<" ";cout<<endl;
    }
    return 1;
}
int main()
{
scanf("%i%i%lld",&n,&r,&k);
for(int i=1;i<=n;i++)scanf("%i",&arr[i]);
long long ok=0,not_ok=2e18;
while(not_ok-ok>1)
{
    long long av=(ok+not_ok)/2;
    if(can(av))ok=av;
    else not_ok=av;
}
printf("%lld\n",ok);
return 0;
}