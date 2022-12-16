#include<bits/stdc++.h>
#define int long long
using namespace std;
const int nmax=1e5+42,mod=1e9+7,LIM=1e6+42;
int n,a[nmax];
int previous[nmax];
map<int,int> seen;
long long fenwick[LIM];
int sum[nmax],sum_prev[nmax];
int lsb(int x)
{
return x&(-x);
}
void add(int pos,int value)
{
while(pos<LIM)
{

fenwick[pos]+=value;
pos=pos+lsb(pos);
}

}
int query(int pos)
{
long long ans=0;
while(pos)
{
ans=ans+fenwick[pos];
pos=pos-lsb(pos);
}
return ans%mod;
}
signed main()
{
ios_base::sync_with_stdio(false);
cin.tie();
cin>>n;
for(int i=1;i<=n;i++)cin>>a[i];
for(int i=1;i<=n;i++)
{
    if(seen.count(a[i]))
        previous[i]=seen[a[i]];
    else sum[i]++;
    seen[a[i]]=i;
}

for(int i=1;i<=n;i++)
{
    sum_prev[i]=query(a[i]);
    sum[i]=(sum[i]+query(a[i])-sum_prev[previous[i]]+mod)%mod;
    sum[i]=(sum[i]*a[i])%mod;
    add(a[i],sum[i]);
    //cout<<i<<" -> "<<sum[i]<<endl;
}

long long ans=0;
for(int i=1;i<=n;i++)
    ans=(ans+1LL*sum[i])%mod;
cout<<ans<<endl;
return 0;
}