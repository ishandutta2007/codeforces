#include<bits/stdc++.h>
using namespace std;
#define int long long
const int Mod=1e8;
int n1,n2,k1,k2,ans;
int f[105][105][15][15];
int dfs(int a,int b,int c,int d)
{
	
	if(f[a][b][c][d]>=0)return f[a][b][c][d];
	f[a][b][c][d]=0;
	if(a>n1||b>n2) return 0;
	if(c>k1||d>k2) return 0; 
	//cout<<a<<" "<<b<<" "<<c<<" "<<d<<" "<<f[a][b][c][d]<<endl;
	
	if(a==n1&&b==n2)
	{
		f[a][b][c][d]=1;
		return 1;	
	}
	if(a<n1&&c<k1)f[a][b][c][d]+=dfs(a+1,b,c+1,0);
	if(b<n2&&d<k2)f[a][b][c][d]+=dfs(a,b+1,0,d+1);
	return f[a][b][c][d]%=Mod;

}
signed main()
{
	memset(f,255,sizeof f);
    cin>>n1>>n2>>k1>>k2;
    cout<<dfs(0,0,0,0)%Mod;
	return 0;
}