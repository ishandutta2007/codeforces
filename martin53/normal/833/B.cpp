#include<bits/stdc++.h>
using namespace std;
const int nmax=35000+42,kmax=51;
int n,k;
int arr[nmax];
long long dp[nmax][kmax];
int seen[nmax];
long long add=1;
int l_=1,r_=1;
void update(int l,int r)
{
    //cout<<"I want "<<l<<" "<<r<<endl;

    while(r>r_)
    {
        r_++;
        add=add+(seen[arr[r_]]==0);
        seen[arr[r_]]++;
    }

    while(l<l_)
    {
        l_--;
        add=add+(seen[arr[l_]]==0);
        seen[arr[l_]]++;
    }

    while(l>l_)
    {
        seen[arr[l_]]--;
        add=add-(seen[arr[l_]]==0);
        l_++;
    }



    while(r<r_)
    {
        seen[arr[r_]]--;
        add=add-(seen[arr[r_]]==0);
        r_--;
    }
    //cout<<l_<<" "<<r_<<" -> "<<add<<endl;
    //system("pause");
}
int ask(int ind,int pos,int l,int r)
{
    r=min(r,pos);
    int ret=-1;
    update(r+1,pos);
    for(int i=r;i>=l;i--)
    {
    update(i,pos);
        if(dp[pos][ind]<dp[i-1][ind-1]+add)
        {
            ret=i;
            dp[pos][ind]=dp[i-1][ind-1]+add;
        }
    }
    //cout<<ind<<" "<<pos<<" -> "<<dp[pos][ind]<<" "<<ret<<endl;
    //system("pause");
    return ret;
}
void solve(int k_,int lq,int rq,int l,int r)
{
    if(lq>rq)return;
    r=min(r,rq);
    int av=(lq+rq)/2;
    int pos=ask(k_,av,l,r);
    solve(k_,lq,av-1,l,pos);
    solve(k_,av+1,rq,pos,r);
}
int main()
{
cin>>n>>k;
for(int i=1;i<=n;i++)cin>>arr[i];
seen[arr[1]]=1;
/*
for(int i=0;i<=n;i++)
    for(int j=0;j<=k;j++)
    dp[i][j]=1e18;
*/
dp[0][0]=0;
for(int i=1;i<=k;i++)
    solve(i,i,n,i,n);

cout<<dp[n][k]<<endl;
return 0;
}