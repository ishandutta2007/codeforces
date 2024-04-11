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
const int N=200005;
int n,a[N],b[N],c[N],d[N],v[N],s[N],tg[N];
std::vector<int>g[N];
void dfs(int x,int p)
{
	v[x]=1;
	fore(i,g[x])
	{
		int y=g[x][i];
		if(!v[y])continue;
		if(y!=p)
		{
//			std::cout<<x<<" "<<y<<std::endl; 
			y=x;do{b[y]=1;y=a[y];}while(y!=x);
		}
	}
	fore(i,g[x])
	{
		int y=g[x][i];
		if(v[y])continue;
		dfs(y,x);
	}
} 
int main()
{
	int T=rd();
	while(T--)
	{
		n=rd();
		rep(i,1,n){a[i]=rd();d[a[i]]++;}
		rep(i,1,n)
		{
			if(a[a[i]]!=i)
			{
				g[a[i]].push_back(i);
				g[i].push_back(a[i]);
			}
			else
			{
				b[i]=1;b[a[i]]=1;
			}
		}
		rep(i,1,n)if(!v[i])dfs(i,0);
//		rep(i,1,n)printf("%d ",b[i]);puts("");
		rep(i,1,n)if(!b[i]&&!tg[a[i]]&&!b[a[i]])c[i]=1,tg[a[i]]=1;
		rep(i,1,n)if(b[i]||c[i])s[i]=a[i];
		int ss=0;
		std::vector<std::pair<int,int> >V;V.clear();
		rep(i,1,n)if(!d[i])
		{
			int t=i;ss++;
			while(c[t]){t=a[t];ss++;}
			V.push_back(std::make_pair(t,i));
		}
		if(ss==1)
		{
			int x=V[0].X;s[x]=a[x];
			rep(i,1,n)if(b[i]&&a[i]==a[x])s[i]=x;
		}
		else
		{
			int nn=V.size();
			rep0(i,0,nn-1)s[V[i+1].X]=V[i].Y;
			if(nn)s[V[0].X]=V[nn-1].Y;
		}
		int k=0;rep(i,1,n)if(s[i]==a[i])k++;
		printf("%d\n",k);
		rep(i,1,n)printf("%d ",s[i]);puts("");
		rep(i,1,n)v[i]=0,b[i]=0,c[i]=0,d[i]=0,tg[i]=0;
		rep(i,1,n)g[i].clear();
	}
	return 0;
}