#include<iostream> 
#include<cstring>
using namespace std;  
const int INF=1e9;  
int dp[35][35][55]; 
int n,m,k,t,i,j,x,y;  
int main()
{         
    for (i=1;i<=30;i++)
	{
		for (j=1;j<=30;j++)
		{
			for (k=1;k<=50;k++)
			dp[i][j][k]=INF;
		}
	}  
    for(i=1;i<=30;i++)
	{  
        for(j=1;j<=30;j++)
		{  
            for(k=0;k<=50;k++)
			{  
                if(i*j==k || k==0)  
                dp[i][j][k]=0;  
                for(x=0;x<=k;x++)
				{ 
                    for(y=1;y<j;y++)  
                    dp[i][j][k]=min(dp[i][j][k],dp[i][y][x]+dp[i][j-y][k-x]+i*i);  
                    for(y=1;y<i;y++)  
                    dp[i][j][k]=min(dp[i][j][k],dp[y][j][x]+dp[i-y][j][k-x]+j*j);  
                }  
            }  
        }  
    }  
    cin>>t;                             
    while(t--)
	{  
        cin>>n>>m>>k;  
       	cout<<dp[n][m][k]<<endl;
    }  
    return 0;  
}