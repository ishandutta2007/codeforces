#include<cstdio>
using namespace std;
#include<vector>
struct lazysegtree{
	int n;
	vector<int>dat,lazy;
	vector<bool>lazyflag;
	lazysegtree(int n_=0)
	{
		n=1;
		while(n<n_)n<<=1;
		dat.assign(2*n-1,0);
		lazy.assign(2*n-1,0);
		lazyflag.assign(2*n-1,false);
	}
	void copy(const vector<int>&v)
	{
		for(int i=0;i<v.size();i++)dat[i+n-1]=v[i];
		for(int i=n-2;i>=0;i--)dat[i]=min(dat[2*i+1],dat[2*i+2]);
	}
	void eval(int i,int l,int r)
	{
		if(lazyflag[i])
		{
			dat[i]+=lazy[i];
			if(r-l>1)
			{
				lazy[2*i+1]+=lazy[i];
				lazy[2*i+2]+=lazy[i];
				lazyflag[2*i+1]=lazyflag[2*i+2]=true;
			}
			lazy[i]=0;
			lazyflag[i]=false;
		}
	}
	void update(int a,int b,int x,int k=0,int l=0,int r=-1)//[a,b)
	{
		if(r<0)r=n;
		eval(k,l,r);
		if(b<=l||r<=a)return;
		else if(a<=l&&r<=b)
		{
			lazy[k]+=x;
			lazyflag[k]=true;
			eval(k,l,r);
		}
		else
		{
			update(a,b,x,2*k+1,l,(l+r)/2);
			update(a,b,x,2*k+2,(l+r)/2,r);
			dat[k]=min(dat[2*k+1],dat[2*k+2]);
		}
	}
	int query(int a,int b,int k=0,int l=0,int r=-1)//[a,b)
	{
		if(r<0)r=n;
		eval(k,l,r);
		if(b<=l||r<=a)return 0;
		else if(a<=l&&r<=b)return dat[k];
		else return min(
			query(a,b,2*k+1,l,(l+r)/2),
			query(a,b,2*k+2,(l+r)/2,r)
		);
	}
};
int N,p[3<<17],q[3<<17];
int pinv[3<<17];
main()
{
	scanf("%d",&N);
	for(int i=0;i<N;i++)
	{
		scanf("%d",&p[i]);
		pinv[p[i]]=i;
	}
	for(int i=0;i<N;i++)scanf("%d",&q[i]);
	lazysegtree P(N);
	int ans=N+1;
	for(int i=0;i<N;i++)
	{
		while(P.query(0,N)>=0)
		{
			ans--;
			P.update(0,pinv[ans]+1,-1);
		}
		printf("%d%c",ans,i+1==N?'\n':' ');
		P.update(0,q[i],1);
	}
}