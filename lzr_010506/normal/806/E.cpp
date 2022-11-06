#include <bits/stdc++.h>
#define SIZE 500005
#define BT 512*1024*2
#define INF 1000000005

using namespace std;
typedef long long int ll;
typedef pair <int,int> P;

//P(A[i],i) 
vector <P> vt;
struct segtree
{
	int seg[BT],add[BT];
	int mum;
	
	void init(int n)
	{
		mum = 1;
		while(mum < n) mum <<= 1;
		for(int i = 0; i < mum * 2; i ++) seg[i] = INF, add[i]=0;
	}
	void update(int a,int b,int k,int l,int r,int v)
	{
		if(b<=l||r<=a) return;
		if(a<=l&&r<=b)
		{
			add[k]+=v;
			seg[k]+=v;
		}
		else
		{
			update(a,b,k*2+1,l,(l+r)/2,v);
			update(a,b,k*2+2,(l+r)/2,r,v);
			seg[k]=min(seg[k*2+1],seg[k*2+2])+add[k];
		}
	}
	void update(int a,int b,int v)
	{
		update(a,b,0,0,mum,v);
	}
	void ins(int k,int x)
	{
		update(k,k+1,x-INF);
	}
	int get(int a,int b,int k,int l,int r)
	{
		if(b<=l||r<=a) return INF;
		if(a<=l&&r<=b) return seg[k];
		else
		{
			int vl=get(a,b,k*2+1,l,(l+r)/2);
			int vr=get(a,b,k*2+2,(l+r)/2,r);
			return min(vl,vr)+add[k];
		}
	}
	int get(int a,int b)
	{
		return get(a,b,0,0,mum);
	}
};
struct segtree2
{
	int seg[BT];
	int mum;
	
	void init(int n)
	{
		mum=1;
		while(mum<n) mum<<=1;
		for(int i=0;i<mum*2;i++) seg[i]=0;
	}
	void add(int k)
	{
		k+=mum-1;
		seg[k]++;
		while(k>0)
		{
			k=(k-1)/2;
			seg[k]=seg[k*2+1]+seg[k*2+2];
		}
	}
	P search()
	{
		int now=0;
		int l=0,r=mum,k=0;
		while(r-l>1)
		{
			int m=(l+r)/2;
			if(now-seg[k*2+1]>=vt[m].first)
			{
				now-=seg[k*2+1];
				k=k*2+2;
				l=m;
			}
			else
			{
				k=k*2+1;
				r=m;
			}
		}
		if(seg[k]==1&&now>vt[l].first)
		{
			now--;
			l++;
		}
		return P(now,l);
	}
	int get(int a,int b,int k,int l,int r)
	{
		if(b<=l||r<=a) return 0;
		if(a<=l&&r<=b) return seg[k];
		else
		{
			int vl=get(a,b,k*2+1,l,(l+r)/2);
			int vr=get(a,b,k*2+2,(l+r)/2,r);
			return vl+vr;
		}
	}
	int get(int a,int b)
	{
		return get(a,b,0,0,mum);
	}
};
segtree s1;
segtree2 s2;
int A[SIZE];
int id[SIZE];

int main()
{
	int n;
	scanf("%d",&n);
	s1.init(n+2);
	s2.init(n+2);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&A[i]);
		vt.push_back(P(A[i],i));
	}
	while(vt.size()<s2.mum) vt.push_back(P(INF,-1));
	sort(vt.begin(),vt.end());
	for(int i=0;i<n;i++) id[vt[i].second]=i;
	for(int i=0;i<n;i++)
	{
		s1.ins(id[i],A[i]);
		if(id[i]>0) s1.update(0,id[i],1);
		s2.add(id[i]);
		P p=s2.search();
		//printf("%d : %d %d\n",id[i],p.first,p.second);
		int ret=p.first+s2.get(p.second,s2.mum);
		ret=min(ret,s1.get(p.second,s1.mum));
		printf("%d\n",ret);
	}
	return 0;
}