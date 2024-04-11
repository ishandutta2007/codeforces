#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int n,q;
int a[N],b[N];
int fi[N],cnt[N],se[N],tag[N];
void push_up(int x)
{
	fi[x]=min(fi[x<<1],fi[x<<1|1]);
	cnt[x]=(fi[x]==fi[x<<1])*cnt[x<<1]+(fi[x]==fi[x<<1|1])*cnt[x<<1];
	se[x]=min(se[x<<1],se[x<<1|1]);
	if(fi[x]!=fi[x<<1])
		se[x]=min(se[x],fi[x<<1]);
	if(fi[x]!=fi[x<<1|1])
		se[x]=min(se[x],fi[x<<1|1]);
	return;
}
void push_down(int x)
{
	if(!tag[x])
		return;
	if(fi[x<<1]<tag[x])
		fi[x<<1]=tag[x],tag[x<<1]=tag[x];
	if(fi[x<<1|1]<tag[x])
		fi[x<<1|1]=tag[x],tag[x<<1|1]=tag[x];
	tag[x]=0;
	return;
}
void getmax(int x,int lp,int rp,int k)
{
	if(k<fi[x])
		return;
	if(k<se[x])
		return fi[x]=k,tag[x]=k,void();
	int mid=(lp+rp)>>1;
	push_down(x);
	getmax(x<<1,lp,mid,k);
	getmax(x<<1|1,mid+1,rp,k);
	push_up(x);
	return;
}
void modify(int x,int lp,int rp,int pos,int k)
{
	if(lp==rp)
		return fi[x]=k,void();
	int mid=(lp+rp)>>1;
	push_down(x);
	if(pos<=mid)
		modify(x<<1,lp,mid,pos,k);
	else
		modify(x<<1|1,mid+1,rp,pos,k);
	push_up(x);
	return;
}
void build(int x,int lp,int rp)
{
	if(lp==rp)
		return fi[x]=a[lp],cnt[x]=1,se[x]=0x3f3f3f3f,void();
	int mid=(lp+rp)>>1;
	build(x<<1,lp,mid);
	build(x<<1|1,mid+1,rp);
	push_up(x);
	return;
}
void print(int x,int lp,int rp)
{
	if(lp==rp)
		return b[lp]=fi[x],void();
	int mid=(lp+rp)>>1;
	push_down(x);
	print(x<<1,lp,mid);
	print(x<<1|1,mid+1,rp);
//	push_up(x);
	return;
}
signed main()
{
	int opt,p,x;
	register int i;
	ios::sync_with_stdio(0);
	cin>>n;
	for(i=1;i<=n;i++)
		cin>>a[i];
	build(1,1,n);
	cin>>q;
	while(q--)
		if(cin>>opt,opt==1)
			cin>>p>>x,modify(1,1,n,p,x);
		else
			cin>>x,getmax(1,1,n,x);
	print(1,1,n);
	for(i=1;i<=n;i++)
		cout<<b[i]<<' ';
	cout<<endl;
	return 0;
}