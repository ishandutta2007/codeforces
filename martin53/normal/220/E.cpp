#include<bits/stdc++.h>
using namespace std;
const int nmax=1e5+42;
int n;
long long k;
int arr[nmax];
void compress()
{
    set<int> seen={};
    for(int i=1;i<=n;i++)
        seen.insert(arr[i]);
    map<int,int> c={};
    int val=0;
    for(auto k:seen)
    {
        val++;
        c[k]=val;
    }
    for(int i=1;i<=n;i++)
        arr[i]=c[arr[i]];
}
int fenwick[nmax][2];//0-> left; 1-> right
int sum(int pos,int index)
{
    int ret=0;
    while(pos)
    {
        ret=ret+fenwick[pos][index];
        pos=pos-(pos&(-pos));
    }
    return ret;
}
int query(int l,int r,int index)
{
    return sum(r,index)-sum(l-1,index);
}
void update(int pos,int add,int index)
{
    while(pos<=n)
    {
        fenwick[pos][index]+=add;
        pos=pos+(pos&(-pos));
    }
}
int main()
{
scanf("%i%lld",&n,&k);
for(int i=1;i<=n;i++)scanf("%i",&arr[i]);
compress();
int r=n+1;
long long now=0;
while(r>1&&now<=k)
{
    r--;
    now=now+query(1,arr[r]-1,1);
    if(now>k)
    {
        now=now-query(1,arr[r]-1,1);
        r++;
        break;
    }
    update(arr[r],1,1);
}

long long ans=0;
for(int l=1;l<n;l++)
{
    //insert l-th
    now=now+query(arr[l]+1,n,0)+query(1,arr[l]-1,1);
    update(arr[l],1,0);
    //remove r-th
    while(l>=r||(now>k&&r<=n))
    {
        now=now-query(arr[r]+1,n,0)-query(1,arr[r]-1,1);
        update(arr[r],-1,1);
        r++;
    }
    ans=ans+(n-r+1);
}
printf("%lld\n",ans);
return 0;
}