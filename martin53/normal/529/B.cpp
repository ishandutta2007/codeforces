#include<bits/stdc++.h>
using namespace std;
const int nmax=1e3+42;
int n;
pair<int,int> inp[nmax];
set<int> now;
int req=0;
vector<int> arr;
bool cmp(int p,int q)
{
return p>q;
}
long long test(int mx)
{
    arr={};
    int rot=n/2;
    long long ans=0;
    for(int i=1;i<=n;i++)
    {
        if(inp[i].first>mx&&inp[i].second<=mx)ans=ans+inp[i].first;
        else if(inp[i].first<=mx&&inp[i].second>mx)rot--,ans=ans+inp[i].second;
        else
        {
            if(inp[i].first<=inp[i].second)ans=ans+inp[i].first;
            else arr.push_back(inp[i].first-inp[i].second),ans=ans+inp[i].first;
        }
    }
    if(rot<0)return 1e12;
    sort(arr.begin(),arr.end(),cmp);
    if(rot>arr.size())rot=arr.size();

    for(int j=0;j<rot;j++)
        ans=ans-arr[j];
    return ans;
}
int main()
{
scanf("%i",&n);
for(int i=1;i<=n;i++)
{
    scanf("%i%i",&inp[i].first,&inp[i].second);
    now.insert(inp[i].second);
    now.insert(inp[i].first);
    req=max(req,min(inp[i].first,inp[i].second));
}
long long ans=1e18;
for(auto k:now)
    if(k>=req)ans=min(ans,test(k)*k);
printf("%lld\n",ans);
return 0;
}