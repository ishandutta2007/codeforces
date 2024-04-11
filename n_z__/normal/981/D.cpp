#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[51],s[51];
int n,k;
int dp[51][51];
bool check(int q)
{
    memset(dp,0,sizeof(dp));
    dp[0][0]=1;
    for(int x=0;x<=n;x++)
    for(int y=1;y<=k;y++)
    for(int z=0;z<x;z++)
    if(((s[x]-s[z])&q)==q)
    dp[x][y]|=dp[z][y-1];
    return dp[n][k];
}
//mt19937_64 mt(time(0));
main()
{
	//while(1)
	{
		/*{
			freopen("10.in","w",stdout);
			int n=mt()%50+1,k=mt()%n+1;
			cout<<n<<' '<<k<<endl;
			for(int x=1;x<=n;x++)
			cout<<mt()%((1ll<<50)-1)+1<<' ';
		}
		freopen("10.in","r",stdin);
		freopen("10.out","w",stdout);*/
	    cin>>n>>k;
	    for(int x=1;x<=n;x++)
	    cin>>a[x],s[x]=s[x-1]+a[x];
	    int nowans=0;
	    for(int x=60;x>=0;x--)
	    if(check(nowans|(1ll<<x)))nowans|=(1ll<<x);
	    cout<<nowans<<endl;
	    //if(nowans!=0)return 0;
	}
}
/*
B
*/