#include<bits/stdc++.h>
using namespace std;
void solve()
{
    long long int r,c;cin>>r>>c;
    int arr[r][c];
    bool dp[r][c];
    bool dp1[r][c];
    char t;
    for(long long int i=0;i<r;i++)
    {
        for(long long int j=0;j<c;j++)
        {
            cin>>t;
            if(t=='#')
            {
                arr[i][j]=1;
                dp[i][j]=false;
                dp1[i][j]=false;
            }    
            else
                arr[i][j]=0;
        }
    }
    long long int count=0;
    for(long long int i=r+c-2;i>=0;i--)
    {
        for(long long int j=min(c-1,i);j>=0 && i-j<r;j--)
        {
            if(j==c-1 && i ==r+c-2) 
            {
                dp[i-j][j]=true;
            }
            else if(j==c-1 && arr[i-j][j]!=1)
            {
                dp[i-j][j]=dp[i-j+1][j];
            }
            else if(i-j==r-1 && arr[i-j][j]!=1)
            {
                dp[i-j][j]=dp[i-j][j+1];
            }
            else if(arr[i-j][j]!=1)
            {
                dp[i-j][j]=dp[i-j+1][j]+dp[i-j][j+1];
            }
            count++;
            //cout<<dp[i-j][j];
        }
        //cout<<endl;
    }
    dp1[0][0]=true;
    for(long long int i=1;i<=r+c-2;i++)
    {
        for(long long int j=min(c-1,i);j>=0 && i-j<r;j--)
        {
            if(j==0 && arr[i-j][j]!=1)
            {
                dp1[i-j][j]=dp1[i-j-1][j];
            }
            else if(i-j==0 && arr[i-j][j]!=1)
            {
                dp1[i-j][j]=dp1[i-j][j-1];
            }
            else if(arr[i-j][j]!=1)
            {
                dp1[i-j][j]=dp1[i-j-1][j]+dp1[i-j][j-1];
            }
           // cout<<i<<" "<<j<<" "<<dp1[i-j][j]<<endl;
            //cout<<dp[i-j][j];
        }
        //cout<<endl;
    }
    //cout<<count<<endl;
    long long int answer=2;
    for(long long int i=r+c-3;i>0;i--)
    {
        long long int count=0;
        for(long long int j=min(c-1,i);j>=0 && i-j<=r-1;j--)
        {
            if(dp[i-j][j] && dp1[i-j][j])
            {
                count++;
            }    
        }
        //cout<<count<<endl;
        if(count<answer)
        {
            answer=count;
        }    
    }
    cout<<answer<<endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	solve(); 
}