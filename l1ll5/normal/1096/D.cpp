#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <algorithm>
#define rep(i,a,b) for(int i=a;i<=b;++i)
#define per(i,a,b) for(int i=a;i>=b;--i)
#define rvc(i,S) for(int i=0;i<S.size();++i)
#define mp make_pair
#define pb push_back
#define fi first
#define se second
using namespace std;
inline int read()
{
	char c=getchar(); int ret=0;
	int f=1;
	while(c<48||c>57){if(c=='-')f=-1;c=getchar();}
	while(c>=48&&c<=57)ret=ret*10+c-48,c=getchar();
	return ret*f;
}
#define ll long long
#define N 100005
int n;
char s[N];
char t[]={" hard"};
int w[N];
ll f[N][7];
int main()
{
	n=read();
	scanf("%s",s+1);
	rep(i,1,n)w[i]=read();
	memset(f,0x3f,sizeof(f));
	f[0][0]=0;
	rep(i,1,n)
	{
		rep(j,0,4)
		{
			if(s[i]==t[j+1])
			{
				f[i][j]=min(f[i][j],f[i-1][j]+w[i]);
				f[i][j+1]=f[i-1][j];
			}
			else f[i][j]=min(f[i][j],f[i-1][j]);
		}
	}
	
	ll ans=1e18;
	
	rep(i,0,3)
	ans=min(ans,f[n][i]);
	cout<<ans<<endl;
	
}