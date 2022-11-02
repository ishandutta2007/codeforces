#include<bits/stdc++.h>
using namespace std;
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
const int N=205;
int n,nn,m,k,s,a[N],b[N];
int main()
{
	int T=rd();
	while(T--)
	{
		n=rd();k=rd();nn=n*2;m=0;s=0;
		rep(i,1,n*2)a[i]=0;
		vector<pair<int,int> >V;
		V.clear();
		rep(i,1,k)
		{
			int u=rd(),v=rd();
			if(u>v)swap(u,v);
			a[u]=v;a[v]=u;
			V.push_back(make_pair(u,v));
		}
		rep(i,1,nn)if(!a[i])b[++m]=i;
		sort(b+1,b+m+1);
		rep(i,1,n-k)V.push_back(make_pair(b[i],b[n-k+i]));
		rep0(i,0,n)rep0(j,i+1,n)
		{
			int xa=V[i].X,xb=V[i].Y;
			int ya=V[j].X,yb=V[j].Y;
			if(xa>ya)swap(xa,ya),swap(xb,yb);
			if(ya<xb&&xb<yb)s++;
		}
		printf("%d\n",s);
	}
	return 0;
}