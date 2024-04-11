#include<bits/stdc++.h>
#define int long long
using namespace std;
const long long inf=4e18+42;
const int nmax=2e5+42,C=70;
int n,k;
int a[nmax];
deque< pair<int/*value*/,int/*index*/> >seen;
signed main()
{
ios_base::sync_with_stdio(false);
cin.tie();
cin>>n>>k;
for(int i=1;i<=n;i++)cin>>a[i];
long long ans=0;

seen.push_back({1,0});
for(int i=1;i<=n;i++)
{
    long long p=a[i],s=a[i];
    if(k==1)ans++;
    int SZ=seen.size();
    int prev=i-1;
    for(int j=SZ-1;j>=0;j--)
    {
        //cout<<"i= "<<i<<" j= "<<j<<endl;
        if(p%k==0)
        {
            long long target=p/k;
            //cout<<"target "<<target<<" "<<s<<" "<<prev<<endl;
            if(target-s>=1&&target-s<=prev-seen[j].second)ans++;
        }
        //prev=seen[j].second-1;
        if(inf/seen[j].first<p)break;
        //cout<<p<<" "<<s<<endl;
        if(seen[j].second==0)break;
        p=p*seen[j].first;
        s=s+seen[j].first+(prev-seen[j].second);
        //cout<<p<<" "<<s<<endl;
        if(p%s==0&&p/s==k)
        {
        //cout<<"i= "<<i<<" j= "<<j<<endl;
        //cout<<"p= "<<p<<" s= "<<s<<endl;
        ans++;
        }
        prev=seen[j].second-1;
    }
    if(a[i]!=1)seen.push_back({a[i],i});
    if(seen.size()>C)seen.pop_front();
    //cout<<"i= "<<i<<endl;
}
cout<<ans<<endl;
return 0;
}