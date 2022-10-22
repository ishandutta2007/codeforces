#include<cstdio>
#include<algorithm>
#include<queue>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=2e5+5;
template<typename T>void read(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
struct seg
{
	int l,r,ind;
}s[N];
struct cmpl
{
	bool operator()(seg a,seg b)const{return a.l<b.l;}
};
struct cmpr
{
	bool operator()(seg a,seg b)const{return a.r<b.r;}
};
priority_queue<seg,vector<seg>,cmpr> q;
int n,k,v[2*N],a[2*N],c,j,ans;
bool d[N];
int dis(int x)
{
	int l=0,r=2*n;
	while(r-l>1)
	{
		int mid=(l+r)>>1;
		if(x<v[mid])r=mid;
		else l=mid;
	}
	return l;
}
int main()
{
	read(n);read(k);
	F(i,0,n)
	{
		read(s[i].l);read(s[i].r);s[i].ind=i;
		v[2*i]=--s[i].l;v[2*i+1]=s[i].r;
	}
	sort(v,v+2*n);
	F(i,0,n)s[i].l=dis(s[i].l),s[i].r=dis(s[i].r);
	sort(s,s+n,cmpl());
	F(i,0,n)++a[s[i].l],--a[s[i].r];
	F(i,0,2*n)
	{
		while(j<n&&s[j].l==i)q.push(s[j++]);
		c+=a[i];
		while(c>k)
		{
			--c;
			d[q.top().ind]=true;
			++a[q.top().r];
			q.pop();
			++ans;
		}
	}
	printf("%d\n",ans);
	F(i,0,n)if(d[i])printf("%d ",i+1);
	printf("\n");
	return 0;
}