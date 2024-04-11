#include<bits/stdc++.h>
using namespace std;
const int nmax=1e6+42;
int n,a[nmax];
void compress()
{
set<int> nums;
nums.clear();
for(int i=1;i<=n;i++)nums.insert(a[i]);
map<int,int> seen;
seen.clear();
int p=0;
for(auto k:nums)
{
p++;
seen[k]=p;
}
for(int i=1;i<=n;i++)a[i]=seen[a[i]];
}
int lsb(int x)
{
return x&(-x);
}
long long dp[nmax][3];
long long fenwick[nmax];

long long sum(int index)
{
long long ans=0;
//cout<<"sum"<<endl;
while(index)
{
ans=ans+fenwick[index];
index=index-lsb(index);
}
return ans;
}
void update(int index,long long value)
{
//cout<<"update"<<endl;
while(index<=n)
{
fenwick[index]+=value;
index=index+lsb(index);
}

}
long long query(int l,int r)
{
if(l>r)return 0;
return sum(r)-sum(l-1);
}
int main()
{
ios_base::sync_with_stdio(false);
cin.tie();
cin>>n;
for(int i=1;i<=n;i++)cin>>a[i];
compress();
for(int i=1;i<=n;i++)dp[i][0]=1;
for(int k=1;k<3;k++)
{
    memset(fenwick,0,sizeof(fenwick));
        for(int i=1;i<=n;i++)
        {
        dp[i][k]=query(a[i]+1,n);
        update(a[i],dp[i][k-1]);
        }
}
long long ans=0;
for(int i=1;i<=n;i++)ans=ans+dp[i][2];
cout<<ans<<endl;
return 0;
}