#include<bits/stdc++.h>
#define ll long long
#define db double
#define X first
#define Y second
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define rep0(i,a,b) for(int i=(a);i<(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
#define fore(i,a) for(int i=0;i<a.size();++i)
inline int rd()
{
	char c=getchar();int x=0,w=1;
	while(!isdigit(c)&&c!='-')c=getchar();
	if(c=='-')w=-1,c=getchar();
	while(isdigit(c))x=x*10+c-48,c=getchar();
	return x*w;
}
inline void cmx(int&a,int b){a=a>b?a:b;}
inline void cmn(int&a,int b){a=a<b?a:b;}
const int N=200005,P=1000000007;
int n,m,mm,f[N],g[N],h[N],hh[N],nxt[N][18];char s[N];
inline bool chk(int x)
{
	g[n+1]=m;h[n+1]=0;hh[n+1]=0;
	per(i,n,1)
	{
		g[i]=g[i+1];h[i]=h[i+1]+1;
		if(s[i]!='?')
		{
			if(s[i]!='a'+g[i])g[i]=s[i]-'a',h[i]=1+hh[i+1];
			hh[i]=0;
		}
		else hh[i]=hh[i+1]+1;
	}
	rep0(i,0,m)nxt[n+1][i]=n+1;
	per(i,n,1)
	{
		rep0(j,0,m)nxt[i][j]=nxt[i+1][j];
		rep0(j,0,m)
		{
			if(s[i]=='?'&&hh[i]>=x)nxt[i][j]=i+x-1;
			if(g[i]==j&&h[i]>=x)nxt[i][j]=i+x-1;
		}
	}
	rep0(i,0,mm)f[i]=n+1;f[0]=0;
	rep0(i,0,mm)if(f[i]<=n)rep0(j,0,m)if(~i>>j&1)f[i|(1<<j)]=std::min(f[i|(1<<j)],nxt[f[i]+1][j]);
	return f[mm-1]<=n;
}
int main()
{
	n=rd();m=rd();mm=1<<m;
	scanf("%s",s+1);
	int l=0,r=n/m+1;
	while(r-l>1)
	{
		int mid=l+r>>1;
		if(chk(mid))l=mid;else r=mid;
	}
	printf("%d\n",l);
	return 0;
}