#include<bits/stdc++.h>
using namespace std;
const int nmax=3*1e5+42;
int n,d;
long long h[nmax];
long long sorted[nmax];
int dp[nmax];

int find_lower(long long lower_x)
{
int j=upper_bound(sorted+1,sorted+3*n+1,lower_x)-sorted;
j--;
return j;
}

int find_upper(long long upper_x)
{
int k=lower_bound(sorted+1,sorted+3*n+1,upper_x)-sorted;
return k;
}
int tree[4*nmax];
int query(int node,int l,int r,int lq,int rq)
{
if(l==lq&&r==rq)return tree[node];
int av=(l+r)/2,ans=0;
if(lq<=av)ans=max(ans,query(node*2,l,av,lq,min(av,rq)));
if(av<rq)ans=max(ans,query(node*2+1,av+1,r,max(av+1,lq),rq));
return ans;
}

void update(int node,int l,int r,int pos,int value)
{
if(l==r)
{
tree[node]=max(tree[node],value);
return;
}
int av=(l+r)/2;
if(pos<=av)update(node*2,l,av,pos,value);
else update(node*2+1,av+1,r,pos,value);
tree[node]=max(tree[node*2],tree[node*2+1]);
}


int q(long long x)
{
int j=find_lower(x-d);
int k=find_upper(x+d);
//cout<<"q "<<"j= "<<j<<" k= "<<k<<endl;
//cout<<" --- "<<endl;

int ans=0;
ans=max(ans,query(1,1,3*n,1,j));
ans=max(ans,query(1,1,3*n,k,3*n));
return ans;
}
void up(int value,long long x)
{
//cout<<"up "<<value<<" "<<x<<endl;
int j=find_lower(x);

//cout<<"j= "<<j<<endl;

//cout<<" --- "<<endl;
update(1,1,3*n,j,value);
}
int main()
{
ios_base::sync_with_stdio(false);
cin.tie();

cin>>n>>d;
for(int i=1;i<=n;i++)cin>>h[i];
for(int i=1;i<=n;i++)
{
sorted[3*i-2]=h[i]-d;
sorted[3*i-1]=h[i];
sorted[3*i]=h[i]+d;
}
sort(sorted+1,sorted+3*n+1);

//cout<<"sorted: ";for(int i=1;i<=3*n;i++)cout<<sorted[i]<<" ";cout<<endl;

for(int i=n;i>=1;i--)
{
    dp[i]=q(h[i])+1;
    up(dp[i],h[i]);
}

//cout<<"dp: ";for(int i=1;i<=n;i++)cout<<dp[i]<<" ";cout<<endl;

int ans=0,index=0;
for(int i=1;i<=n;i++)
    if(dp[i]>ans)
    {
    ans=dp[i];
    index=i;
    }


cout<<ans<<endl;
cout<<index;
for(int i=1;i<=n;i++)
    if(ans-1==dp[i]&&abs(h[index]-h[i])>=d)
    {
    cout<<" "<<i;
    ans--;
    index=i;
    }
return 0;
}