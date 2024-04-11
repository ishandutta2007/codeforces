#include<bits/stdc++.h>
using namespace std;
const int nmax=1e2+5,tmax=2e3+42;
int n;
struct item
{
int t,d,p,index;
};
item inp[nmax];
int dp[nmax][tmax];
int rec(int item,int time_now)
{
if(item==n+1)dp[item][time_now]=0;
if(dp[item][time_now]!=-1)return dp[item][time_now];
int ans=rec(item+1,time_now);//ignore item
if(time_now+inp[item].t<inp[item].d)ans=max(ans,inp[item].p+rec(item+1,time_now+inp[item].t));//take item
dp[item][time_now]=ans;
return ans;
}
bool cmp(item a,item b)
{
return a.d<b.d;
}
vector<int> outp;
void recover()
{

//for(int i=1;i<=n;i++)cout<<inp[i].t<<" "<<inp[i].d<<" "<<inp[i].p<<" "<<inp[i].index<<endl;

int time_now=0;
int value=dp[1][0];
for(int item=1;item<=n;item++)
{
    assert(value==dp[item][time_now]);
    //cout<<"item "<<item<<" "<<value<<" "<<dp[item+1][time_now]<<endl;
    if(dp[item+1][time_now]==value)continue;
    outp.push_back(inp[item].index);
    time_now=time_now+inp[item].t;
    value=value-inp[item].p;
}

}
int main()
{
cin>>n;
for(int i=1;i<=n;i++)
{
cin>>inp[i].t>>inp[i].d>>inp[i].p;
inp[i].index=i;
}
sort(inp+1,inp+n+1,cmp);
memset(dp,-1,sizeof(dp));
cout<<rec(1,0)<<endl;

recover();
cout<<outp.size()<<endl;
for(auto k:outp)cout<<k<<" ";cout<<endl;
return 0;
}