#include<bits/stdc++.h>
#define int long long
using namespace std;
const int nmax=1e5+42;
int n;
int a[nmax];
int b[nmax];
long long dp[nmax];

int s=0;
pair<long long/*coef*/,long long> lines[nmax];
pair<long long,long long> meet(pair<long long,long long> a,pair<long long,long long> b)
{
pair<long long,long long> ans={b.second-a.second,a.first-b.first};
if(ans.second<0)ans.first=-ans.first,ans.second=-ans.second;
//cout<<a.first<<" "<<a.second<<" and "<<b.first<<" "<<b.second<<" meet at "<<ans.first<<"/"<<ans.second<<endl;
return ans;
}
bool check(pair<long long/*coef*/,long long>x)
{
if(lines[s].second>=x.second)return 1;
if(s>=2)
{
    pair<long long,long long> p=meet(x,lines[s-1]);
    pair<long long,long long> q=meet(lines[s],lines[s-1]);

    long long whole_p=p.first/p.second,whole_q=q.first/q.second;
    if(whole_p!=whole_q)return whole_p<whole_q;

    return p.first%p.second<=q.first%q.second;
    //return p.first*q.second<=p.second*q.first;
}
return 0;
}
void add_line(pair<long long/*coef*/,long long>x)
{
while(s&&check(x))s--;
s++;
lines[s]=x;
}

long long query(long long x)
{
/*
cout<<"lines: "<<endl;
for(int i=1;i<=s;i++)cout<<lines[i].first<<" "<<lines[i].second<<endl;
cout<<"searching: "<<x<<endl;
cout<<endl;
*/
int ok=s,not_ok=0;
while(ok-not_ok>1)
{
int i=(ok+not_ok)/2;
long long p=lines[i+1].second-lines[i].second;
long long q=lines[i].first-lines[i+1].first;
    if(p/q>=x)ok=i;
    else not_ok=i;
}
return lines[ok].first*x+lines[ok].second;
}
signed main()
{
ios_base::sync_with_stdio(false);
cin.tie();

cin>>n;
for(int i=1;i<=n;i++)cin>>a[i];
for(int i=1;i<=n;i++)cin>>b[i];

dp[1]=0;
add_line({b[1],dp[1]});
for(int i=2;i<=n;i++)
{
dp[i]=query(a[i]);
/*
dp[i]=1e18;
    for(int j=1;j<=s;j++)
        dp[i]=min(dp[i],lines[j].first*a[i]+lines[j].second);
*/
add_line({b[i],dp[i]});
//cout<<i<<" -> "<<dp[i]<<endl;
}
//cout<<endl;
/*
for(int i=2;i<=n;i++)
    {
    dp[i]=1e18;
    for(int j=1;j<i;j++)
        dp[i]=min(dp[i],dp[j]+1LL*b[j]*a[i]);
    //cout<<i<<" -> "<<dp[i]<<endl;
    }
*/
cout<<dp[n]<<endl;
return 0;
}