#include<iostream>
#include<map>
#include<cstdio>
#define N 1000000000
using namespace std;
int n,i,a[1000005],p[1000005],s[1000001];
long long ans;
map<int,int> mp;
map<int,int> t;
void add(int v,int p)
{
    while (v<=N)
    {
       t[v]+=p;
       v|=v+1;
    }
}
int get(int v)
{
    int s=0;
    while (v>0)
    {
        s+=t[v];
        v=(v & (v+1))-1;
    }
     return s;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin>>n;
    for (i=1;i<=n;i++)
    {
        cin>>a[i];
        mp[a[i]]++;
        p[i]=mp[a[i]];
    }
    mp.clear();
    for (i=n;i>0;i--)
    {
        mp[a[i]]++;
        s[i]=mp[a[i]];
    }
    for (i=n;i>1;i--)
        add(s[i],1);
    ans=0;
    for (i=1;i<n;i++)
    {
        ans+=get(p[i]-1);
        add(s[i+1],-1);
    }
    cout<<ans;
}