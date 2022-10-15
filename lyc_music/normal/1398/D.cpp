#include<bits/stdc++.h>
#define int long long
#define N 205
#define inf 
#define mod 
int s1[N],s2[N],s3[N],f[N][N][N],ans,a,b,c;
bool CMp(int x,int y)
{
	return x>y;
}
using namespace std;
signed main()
{
	cin>>a>>b>>c;
	for (int i=1;i<=a;i++) cin>>s1[i];
	for (int i=1;i<=b;i++) cin>>s2[i];
	for (int i=1;i<=c;i++) cin>>s3[i];
	sort(s1+1,s1+a+1,CMp);
	sort(s2+1,s2+b+1,CMp);
	sort(s3+1,s3+c+1,CMp);
	f[0][0][0]=0;
	for (int i=0;i<=a;i++)
	  for (int j=0;j<=b;j++)
	    for (int k=0;k<=c;k++)
	      if (i+j+k!=0)
	      {
	      	if (i!=0&&j!=0) f[i][j][k]=max(f[i][j][k],f[i-1][j-1][k]+s1[i]*s2[j]);
	      	if (i!=0&&k!=0) f[i][j][k]=max(f[i][j][k],f[i-1][j][k-1]+s1[i]*s3[k]);
	      	if (j!=0&&k!=0) f[i][j][k]=max(f[i][j][k],f[i][j-1][k-1]+s2[j]*s3[k]);
	      	ans=max(ans,f[i][j][k]);
	      }
	cout<<ans<<endl;
}