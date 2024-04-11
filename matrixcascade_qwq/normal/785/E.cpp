#include <bits/stdc++.h>
#pragma GCC optimize("Ofast", "unroll-loops")
#pragma GCC target("sse", "sse2", "sse3", "ssse3", "sse4", "avx")
#pragma GCC optimize(2)
#define ll long long
#define up(i,x,y) for(int i=x,i##end=y;i<=i##end;++i)
#define pu(i,x,y) for(int i=x,i##end=y;i>=i##end;--i)
using namespace std;
int read()
{//
    int s = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9')
    {
        if (ch == '-')
            f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
    {
        s = s * 10 + ch - '0';
        ch = getchar();
    }
    return s * f;
}
int h[201010];
int n,m;
struct BST
{
	vector<pair<int,int> >V[20];
	int siz,tp;
	BST(){siz=tp=0;}
	void clear() 
	{
		while(tp--)V[tp].clear();
		siz=tp=0;
	}
	void merge()
	{
		if(tp<2)return;
		auto&Q=V[--tp];auto P=V[--tp];auto&W=V[tp];
		for(int i=P.size()-1;i;i--)P[i].second-=P[i-1].second;
		for(int i=Q.size()-1;i;i--)Q[i].second-=Q[i-1].second;
		W.resize(P.size()+Q.size()),std::merge(P.begin(),P.end(),Q.begin(),Q.end(),W.begin()); // ?
		for(int i=1;i<(int)W.size();i++)W[i].second+=W[i-1].second;
		V[++tp].clear();
	}
	void insert(int v)
	{
		V[tp++].push_back(pair<int,int>(v,1)),siz++;
		int w=siz&-siz;while(w>>=1)merge();
	}
	void cut(int v)
	{
		V[tp++].push_back(pair<int,int>(v,-1)),siz++;
		int w=siz&-siz;while(w>>=1)merge();
	}
	int rank(int v)
	{
		int ans=0;for(int i=0;i<tp;i++){auto w=lower_bound(V[i].begin(),V[i].end(),std::pair<int,int>(v,-114514));if(w!=V[i].begin())ans+=w[-1].second;}
		return ans;
	}
	void brute(int l,int r)
	{
		up(i,l,r)insert(h[i]);
	}
}T[808080];
#define ls (x<<1)
#define rs (x<<1|1)
#define mid ((l+r)>>1)
struct segt
{
	void build(int x,int l,int r){T[x].brute(l,r);if(l==r)return;build(ls,l,mid);build(rs,mid+1,r);}
	int qrank(int x,int l,int r,int ql,int qr,int val)
	{
		if(ql<=l&&r<=qr)return T[x].rank(val);
		int ans=0;
		if(ql<=mid)ans+=qrank(ls,l,mid,ql,qr,val);
		if(mid<qr)ans+=qrank(rs,mid+1,r,ql,qr,val);
		return ans;
	}
	void qadd(int x,int l,int r,int p,int q)
	{
		T[x].insert(q);
		if(l^r)
		{
			if(p<=mid)qadd(ls,l,mid,p,q);
			else qadd(rs,mid+1,r,p,q);
		}
	}
	void qdel(int x,int l,int r,int p,int q)
	{
		T[x].cut(q);
		if(l^r)
		{
			if(p<=mid)qdel(ls,l,mid,p,q);
			else qdel(rs,mid+1,r,p,q);
		}
	}

}st;
int main()
{
	int Tt=1;
	while(Tt--)
	{
		n=read(),m=read();
		up(i,1,n)h[i]=i;
		ll pa=0;
		st.build(1,1,n);
		
		up(i,1,m)
		{
		//	if(i==30000)return 0;
			int x,y;
			x=read(),y=read();
			if(x>y)x^=y^=x^=y; 
			if(h[x]==h[y])
			{
				printf("%lld\n",pa);continue;
			}int del2;
			pa+=2*(st.qrank(1,1,n,x+1,y-1,h[y])-st.qrank(1,1,n,x+1,y-1,h[x]));
			if(h[x]>h[y])pa--;
			else pa++;
			printf("%lld\n",pa);//
		//	if(n==200000)continue;
			st.qdel(1,1,n,y,h[y]);
			st.qdel(1,1,n,x,h[x]);
			st.qadd(1,1,n,x,h[y]);
			st.qadd(1,1,n,y,h[x]);
			swap(h[x],h[y]);
			
		}
	}
	return 0;
}