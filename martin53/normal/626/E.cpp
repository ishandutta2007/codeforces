#include<bits/stdc++.h>
using namespace std;
const int nmax=2e5+42;
int n,arr[nmax];
long long pref[nmax];
long long sum(int l,int r)
{
    return pref[r]-pref[l-1];
}
pair<long long,long long> take(int i,int ok)
{
    pair<long long,long long> diff;
    diff={sum(i-ok,i-1)+arr[i]+sum(n-ok+1,n),(ok+1+ok)};
    diff.first=diff.first-1LL*arr[i]*(ok+1+ok);
    return diff;
}
pair<long long,long long> ter(int &ok,int i)
{
    //cout<<i<<" -> ";
    int l=0,r=min(i,n+1-i)-1;
    //cout<<l<<" "<<r<<" ";
    while(r-l>3)
    {
        int l1=l+(r-l)/3,r1=r-(r-l)/3;
        pair<long long,long long> p=take(i,l1),q=take(i,r1);
        if(p.first*q.second>p.second*q.first)//p>q
            r=r1;
        else l=l1;
    }
    ok=0;
    pair<long long,long long> diff={0,1};
    for(int j=l;j<=r;j++)
    {
        pair<long long,long long> p=take(i,j);
        if(p.first*diff.second>p.second*diff.first)
        {
            ok=j;
            diff=p;
        }
    }
    //cout<<ok<<endl;
    return diff;
}
int main()
{
scanf("%i",&n);
for(int i=1;i<=n;i++)scanf("%i",&arr[i]);
sort(arr+1,arr+n+1);
for(int j=1;j<=n;j++)
    pref[j]=pref[j-1]+arr[j];
int best=1;
pair<long long,long long> best_diff={0,1},diff;
for(int i=2;i<=n;i++)
{
    int ok;
    diff=ter(ok,i);
    /*
    diff={sum(i-ok,i-1)+arr[i]+sum(n-ok+1,n),(ok+1+ok)};
    diff.first=diff.first-1LL*arr[i]*(ok+1+ok);
    */
    //cout<<i<<" "<<ok<<" "<<diff<<endl;
    if(diff.first*best_diff.second>diff.second*best_diff.first)
    {
        best_diff=diff;
        best=i;
    }
}

int i=best;
int ok;
ter(ok,i);
    /*
    int ok=0,not_ok=min(i,n+1-i);
    while(not_ok-ok>1)
    {
        int av=(ok+not_ok)/2;
        if(arr[i-av]+arr[n-av+1]>2*arr[i])ok=av;
        else not_ok=av;
    }
    */
printf("%i\n",ok+1+ok);
for(int j=i-ok;j<i;j++)
    printf("%i ",arr[j]);
printf("%i",arr[i]);
for(int j=n-ok+1;j<=n;j++)
    printf(" %i",arr[j]);
return 0;
}