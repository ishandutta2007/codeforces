#include<bits/stdc++.h>
using namespace std;
const int nmax=1e2+42;
int n,m;
int arr[nmax];
pair<char/*type*/,int/*person*/> inp[nmax];
int dp[20][1<<20];
bool solved[20][1<<20];
int rec(int pos,int mask)
{
    if(pos==n)return 0;
    if(solved[pos][mask])return dp[pos][mask];
    int ans=-1e9;
    if(inp[pos].first=='p')
    {
        for(int i=0;i<n;i++)
            if(((1<<i)&mask)==0)
            {
                if(inp[pos].second==1)ans=rec(pos+1,mask+(1<<i))+arr[i];
                else ans=rec(pos+1,mask+(1<<i))-arr[i];
                break;
            }
    }
    else
    {
        ans=rec(pos+1,mask);
        for(int i=0;i<n;i++)
            if(((1<<i)&mask)==0)
            {
                if(inp[pos].second==1)ans=max(ans,rec(pos+1,mask+(1<<i)));
                else ans=min(ans,rec(pos+1,mask+(1<<i)));
            }
    }
    dp[pos][mask]=ans;
    solved[pos][mask]=1;
    //cout<<pos<<" "<<mask<<" -> "<<ans<<endl;
    return ans;
}
int main()
{
cin>>n;
for(int i=0;i<n;i++)cin>>arr[i];
sort(arr,arr+n);
reverse(arr,arr+n);
cin>>m;
for(int i=0;i<m;i++)cin>>inp[i].first>>inp[i].second;
n=m;
cout<<rec(0,0)<<endl;
return 0;
}