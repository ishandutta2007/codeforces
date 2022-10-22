#include <bits/stdc++.h>
using namespace std;
template <typename T> inline void chmin(T &x,const T &b) {x=min(x,b);}
int n;
double p[1005][1005];
double f[1005],g[1005],s[1005];
int has[1005];

int main()
{
	// freopen("input.txt","r",stdin);
	cin>>n;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			int x;
			scanf("%d",&x);
			p[i][j]=(double)x/100;
		}
	}
	has[n-1]=1;f[n-1]=0;
	for(int i=0;i<n;i++) g[i]=1,s[i]=0;
	int lst=n-1;
	for(int _=0;_<n-1;_++)
	{
		double mn=1e100;
		for(int i=0;i<n;i++)
		{
			if(has[i]) continue;
			s[i]+=g[i]*p[i][lst]*f[lst];
			g[i]*=(1.0-p[i][lst]);
			f[i]=(s[i]+1)/(1.0-g[i]);
			chmin(mn,f[i]);
		}
		for(int i=0;i<n;i++) if(!has[i] && f[i]==mn) 
		{
			has[i]=1;
			lst=i;
			break;
		}
	}
	cout.precision(10);
	cout<<fixed;
	cout<<f[0]<<endl;
	return 0;
}