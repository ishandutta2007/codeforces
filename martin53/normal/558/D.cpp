#include<bits/stdc++.h>
using namespace std;

vector< pair<long long,long long> > help;

vector< pair<long long,int> > active;
int h,q;
bool cmp(pair<long long,int> a,pair<long long,int> b)
{
    if(a.first!=b.first)return a.first<b.first;
    return a.second>b.second;
}
void no()
{
    printf("Game cheated!\n");
    exit(0);
}
void no_un()
{
    printf("Data not sufficient!\n");
    exit(0);
}
int main()
{
scanf("%i%i",&h,&q);
int i;
long long l,r;
int ans;

long long l_=1LL<<(h-1),r_=(1LL<<h)-1;
for(int j=1;j<=q;j++)
{
    scanf("%i%lld%lld%i",&i,&l,&r,&ans);
    l=l*(1LL<<(h-i));
    r=r*(1LL<<(h-i))+(1LL<<(h-i))-1;
    //cout<<" "<<l<<" "<<r<<" "<<ans<<endl;
    if(ans==1)
    {
        l_=max(l_,l);
        r_=min(r_,r);
    }
    else
    {
    help.push_back({l,r});
    }
}
if(l_>r_)no();

vector< pair<long long,long long> > q={};
for(auto &k:help)
{
    k.first=max(k.first,l_);
    k.second=min(k.second,r_);
    if(k.first<=k.second)
    {
        active.push_back({k.first,1});
        active.push_back({k.second,-1});
    }
}
active.push_back({l_-1,0});
active.push_back({r_+1,0});

sort(active.begin(),active.end(),cmp);
int sum=active[0].second;
int SZ=active.size();
long long total=0,number=-1;
/*
for(auto k:active)
    cout<<k.first<<" "<<k.second<<endl;
*/
for(int i=1;i<SZ;i++)
{
    if(sum==0)
    {
        total=total+max(0LL,active[i].first-active[i-1].first-1);
        if(total>1)no_un();
        if(active[i].first-active[i-1].first-1)number=active[i-1].first+1;
    }
    sum=sum+active[i].second;
}
if(total==0)no();
printf("%lld\n",number);
return 0;
}