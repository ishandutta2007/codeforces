#include<bits/stdc++.h>
using namespace std;
const int nmax=1e5+42,LIM=1<<20,bucket=400;
int n,m,k;
struct query
{
int l,r,index;
};
query inp[nmax];
int a[nmax];
long long outp[nmax];
bool cmp(query a,query b)
{
if(a.l/bucket!=b.l/bucket)return a.l/bucket<=b.l/bucket;
if((a.l/bucket)%2==0)return a.r<b.r;
return a.r>b.r;
}
int seen[LIM];
long long ans=0;
void add(int index)
{
ans=ans+seen[a[index]^k];
seen[a[index]]++;
}
void unadd(int index)
{
seen[a[index]]--;
ans=ans-seen[a[index]^k];
}
int main()
{
ios_base::sync_with_stdio(false);
cin.tie();
cin>>n>>m>>k;
for(int i=1;i<=n;i++)
{
cin>>a[i];
a[i]=a[i-1]^a[i];
}
for(int i=1;i<=m;i++)
{
cin>>inp[i].l>>inp[i].r;
inp[i].l--;
inp[i].index=i;
}
sort(inp+1,inp+m+1,cmp);
int prev_l=1,prev_r=1;
add(1);
for(int i=1;i<=m;i++)
{
    while(prev_l>inp[i].l)
    {
    prev_l--;
    add(prev_l);
    }

    while(prev_l<inp[i].l)
    {
    unadd(prev_l);
    prev_l++;
    }


    while(prev_r<inp[i].r)
    {
    prev_r++;
    add(prev_r);
    }

    while(prev_r>inp[i].r)
    {
    unadd(prev_r);
    prev_r--;
    }

    //cout<<prev_l<<" "<<prev_r<<endl;
    outp[inp[i].index]=ans;
}
for(int i=1;i<=m;i++)cout<<outp[i]<<endl;
return 0;
}