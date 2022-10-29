#include<set>
#include<map>
#include<deque>
#include<queue>
#include<stack>
#include<cmath>
#include<ctime>
#include<bitset>
#include<string>
#include<vector>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<climits>
#include<complex>
#include<iostream>
#include<algorithm>
#define ll long long
using namespace std;

inline void read(int &x)
{
	char c; while(!((c=getchar())>='0'&&c<='9'));
	x=c-'0';
	while((c=getchar())>='0'&&c<='9') (x*=10)+=c-'0';
}
const int maxn = 410000;
const int maxc = 110;

int n,m;
int a[maxn];
struct segment
{
	queue<int>q;
	int root[maxc],lc[maxn*25],rc[maxn*25],tot;
	int loc;
	void ins(int &x,const int l,const int r)
	{
		if(!x) x=++tot;
		if(l==r) return;
		int mid=l+r>>1;
		if(loc<=mid) ins(lc[x],l,mid);
		else ins(rc[x],mid+1,r);
	}
	int lx,rx;
	int split(int x,int l,int r,int &y)
	{
		if(rx<l||r<lx||!x) return 0;
		if(lx<=l&&r<=rx) { y=x; return 1; }
		y=++tot;
		int mid=l+r>>1;
		if(split(lc[x],l,mid,lc[y])) lc[x]=0;
		if(split(rc[x],mid+1,r,rc[y])) rc[x]=0;
		if(!lc[x]&&!rc[x]) return 1;
		return 0;
	}
	void merge(int &x,const int &y)
	{
		if(!y) return;
		if(!x) { x=y;return; }
		merge(lc[x],lc[y]);
		merge(rc[x],rc[y]);
	}
	void change(int c1,int c2,int l,int r)
	{
		int tmp=0; lx=l,rx=r; if(split(root[c1],1,n,tmp)) root[c1]=0;
		merge(root[c2],tmp);
	}
	int c;
	void recover(int x,const int l,const int r)
	{
		if(!x) return;
		if(l==r) { a[l]=c; return; }
		int mid=l+r>>1;
		recover(lc[x],l,mid); recover(rc[x],mid+1,r);
	}
}seg;

int main()
{
	read(n);
	for(int i=1;i<=n;i++) 
	{
		read(a[i]);
		seg.loc=i;
		seg.ins(seg.root[a[i]],1,n);
	}
	read(m);
	while(m--)
	{
		int c1,c2,l,r; read(l),read(r),read(c1),read(c2);
		if(c1!=c2) seg.change(c1,c2,l,r);
	}
	for(int i=1;i<=n;i++) a[i]=0;
	for(int i=1;i<=100;i++) seg.c=i,seg.recover(seg.root[i],1,n);
	
	for(int i=1;i<n;i++) printf("%d ",a[i]);
	printf("%d\n",a[n]);
	
	return 0;
}