#include <iostream>
#include <stdio.h>
#include <vector>
#include <set>
#include <string>
#include <string.h>
#include <queue>
#include <set>
#include <algorithm>
#include <assert.h>
#include <math.h>
#include <stdlib.h>
#include <map>
#include <stack>
using namespace std;
const int mod=1000000009;
void chadd(int &x,int v) {x+=v;if(x>=mod) x-=mod;}
int fib[300005][2][2];
int sumfib[300005][2][2];
int fn[300005];
int invAB1[300005];
int n;
int nn;

struct node
{
	int sum;
	int sumtag;
	int fis1;
	int fi;
}data[300005*4];

inline int mul(int a,int b)
{
	return 1LL*a*b%mod;
}

inline int add(int a,int b)
{
	return (a+b>=mod?a+b-mod:a+b);
}

inline int sub(int a,int b)
{
	return (a>=b?a-b:a-b+mod);
}

inline int fastpow(int basic,int exp)
{
	int res=1;
	while(exp)
	{
		if(exp&1) res=mul(res,basic);
		basic=mul(basic,basic);
		exp>>=1;
	}
	return res;
}

int calc(int fis1,int fi,int k)
{
	return add(mul(fi,fib[k][0][0]),mul(fis1,fib[k][0][1]));
}

inline void pushdown(int x,int l,int r,bool debug=false)
{
	if(x>=nn) return;
	int k=r-l>>1;
	int A=fib[k][0][0],B=fib[k][0][1];
	int fis1=data[x].fis1;
	int fi=data[x].fi;
	int sumtag=data[x].sumtag;
	int lfis1=fis1;
	int lfi=fi;
	int rfis1=calc(fis1,fi,k-1);
	int rfi=calc(fis1,fi,k);
//	if(debug) cout<<'d'<<A<<' '<<B<<endl;
//	if(debug) cout<<'d'<<fis1<<' '<<fi<<' '<<k-1<<endl;
//	if(debug) cout<<'d'<<sumtag<<' '<<add(sumtag,sub(mul(rfis1,B),mul(fis1,B)))<<endl;
	int lsum=mul(add(sumtag,sub(mul(rfis1,B),mul(fis1,B))),invAB1[k]);
	int rsum=sub(sumtag,lsum);
	chadd(data[x*2].fi,lfi);
	chadd(data[x*2].fis1,lfis1);
	chadd(data[x*2].sum,lsum);
	chadd(data[x*2].sumtag,lsum);
	chadd(data[x*2+1].fi,rfi);
	chadd(data[x*2+1].fis1,rfis1);
	chadd(data[x*2+1].sum,rsum);
	chadd(data[x*2+1].sumtag,rsum);
	data[x].fi=data[x].fis1=data[x].sumtag=0;
}

int query(int x,int l,int r,int ql,int qr)
{
	if(qr<=l || ql>=r) return 0;
	if(l>=ql && r<=qr) return data[x].sum;
	pushdown(x,l,r);
	return add(query(x*2,l,l+r>>1,ql,qr),query(x*2+1,l+r>>1,r,ql,qr));
}

void update(int x,int l,int r,int ql,int qr,int L)
{
	if(qr<=l || ql>=r) return;
	if(l>=ql && r<=qr)
	{
		int st=l-L+1;
//		cout<<x<<' '<<l<<' '<<r<<' '<<ql<<' '<<qr<<' '<<st<<' ';
		data[x].fi=add(data[x].fi,fn[st]);
		data[x].fis1=add(data[x].fis1,fn[st-1]);
		int sm=add(mul(fn[st],sumfib[r-l-1][0][0]),mul(fn[st-1],sumfib[r-l-1][0][1]));
		chadd(data[x].sum,sm);
		chadd(data[x].sumtag,sm);
//		cout<<data[x].sum<<endl;
//		exit(0);
		return;
	}
	pushdown(x,l,r);
	update(x*2,l,l+r>>1,ql,qr,L);
	update(x*2+1,l+r>>1,r,ql,qr,L);
	data[x].sum=add(data[x*2].sum,data[x*2+1].sum);
}

void init()
{
	nn=1;
	while(nn<n) nn<<=1;
	fib[0][0][0]=1;
	fib[0][1][1]=1;
	fib[1][0][0]=fib[1][0][1]=fib[1][1][0]=1;
	for(int id=2;id<=n;id++)
	{
		for(int i=0;i<2;i++)
		{
			for(int j=0;j<2;j++)
			{
				for(int k=0;k<2;k++)
				{
					fib[id][i][j]=add(fib[id][i][j],mul(fib[id-1][i][k],fib[1][k][j]));
				}
			}
		}
	}
	for(int id=1;id<=n;id++)
	{
		invAB1[id]=fastpow(add(fib[id][0][0],add(fib[id][0][1],1)),mod-2);
	}
	fn[0]=0;
	fn[1]=1;
	for(int i=2;i<=n;i++)
	{
		fn[i]=add(fn[i-1],fn[i-2]);
	}
	sumfib[0][0][0]=sumfib[0][1][1]=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<2;j++)
		{
			for(int k=0;k<2;k++)
			{
				sumfib[i][j][k]=add(sumfib[i-1][j][k],fib[i][j][k]);
			}
		}
	}
}

void build(int n,int a[])
{
	for(int i=nn;i<nn+n;i++)
	{
		data[i].sum=a[i-nn];
	}
	for(int i=nn-1;i>=1;i--)
	{
		data[i].sum=add(data[i*2].sum,data[i*2+1].sum);
	}
}

int main()
{
//	freopen("input.txt","r",stdin);
	ios_base::sync_with_stdio(false);
	int q;
	cin>>n>>q;
	init();
	int a[300005];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	build(n,a);
	int type,l,r;
	for(int i=0;i<q;i++)
	{
		cin>>type>>l>>r;
		l--;
		if(type==1)
		{
			update(1,0,nn,l,r,l);
//			cout<<data[1].sum<<endl;
//			cout<<data[3].sum<<endl;
//			pushdown(3,2,4,true);
//			cout<<data[6].sum<<endl;
		}
		else
		{
			cout<<query(1,0,nn,l,r)<<endl;
		}
	}
	return 0;
}