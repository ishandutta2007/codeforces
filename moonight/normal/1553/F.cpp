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
const int N=300005;
int n,m,a[N],b[N],w1[N*4],w3[N*4];ll w2[N*4],w4[N*4];
#define ls x<<1,l,m
#define rs x<<1|1,m+1,r 
void upd(int x,int l,int r,int p)
{
	if(l==r){w1[x]=1;w2[x]=l;return;}
	int m=l+r>>1;p<=m?upd(ls,p):upd(rs,p);
	w1[x]=w1[x<<1]+w1[x<<1|1];
	w2[x]=w2[x<<1]+w2[x<<1|1];
}
ll qry(int x,int l,int r,int tl,int tr)
{
	if(tl<=l&&r<=tr)return w2[x]-1ll*w1[x]*tl;
	int m=l+r>>1;
	if(tr<=m)return qry(ls,tl,tr);
	if(tl>m)return qry(rs,tl,tr);
	return qry(ls,tl,tr)+qry(rs,tl,tr);
}
void upd2(int x,int l,int r,int tl,int tr)
{
	if(tl<=l&&r<=tr){w3[x]++;w4[x]+=tl;return;}
	int m=l+r>>1;
	if(tl<=m)upd2(ls,tl,tr);
	if(tr>m)upd2(rs,tl,tr);
}
ll qry2(int x,int l,int r,int p)
{
	ll ans=1ll*w3[x]*p-w4[x];
	if(l==r)return ans;int m=l+r>>1;
	return ans+(p<=m?qry2(ls,p):qry2(rs,p));
}
int main()
{
	n=rd();m=300000;
	rep(i,1,n)a[i]=rd();
	ll ans=0;
	rep(i,1,n)
	{
		int x=a[i],t=m/x;
		rep(j,0,t)
		{
			int l=j*x,r=min(m,j*x+x-1);
			if(l>r)continue;
			ans+=qry(1,0,m,l,r);
			upd2(1,0,m,l,r);
		}
		ans+=qry2(1,0,m,x);
		upd(1,0,m,x);
		printf("%lld ",ans);
	}
    return 0;
}