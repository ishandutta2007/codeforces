#include<cstdio>
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
int n,a[N],l[2*N],r[2*N],d[2*N],cnt=1,ll[N],rr[N],ans,L,R;
bool vis[2*N];
struct cmp
{
	bool operator()(int u,int v)const
	{
		return d[u]!=d[v]?d[u]<d[v]:l[u]>l[v];
	}
};
priority_queue<int,vector<int>,cmp> q;
int main()
{
	read(n);F(i,0,n)read(a[i]);
	F(i,0,n)
	{
		if(a[i]==a[l[cnt-1]])++r[cnt-1];
		else l[cnt]=i,r[cnt++]=i+1;
	}
	F(i,0,cnt)d[i]=r[i]-l[i],q.push(i);
	F(i,0,cnt)ll[l[i]]=i,rr[r[i]]=i;
	L=0,R=n;
	while(!q.empty())
	{
		int u=q.top();q.pop();
		if(vis[u])continue;
		if(l[u]!=L&&r[u]!=R)
		{
			int v1=rr[l[u]],v2=ll[r[u]];
			if(a[l[v1]]==a[l[v2]])
			{
				vis[v1]=vis[v2]=true;
				l[cnt]=l[v1],r[cnt]=r[v2];
				d[cnt]=d[v1]+d[v2];
				ll[l[cnt]]=cnt,rr[r[cnt]]=cnt;
				q.push(cnt++);
			}
			else rr[r[v1]=l[v2]]=v1;
		}
		if(l[u]==L)L=r[u];
		if(r[u]==R)R=l[u];
		++ans;
	}
	printf("%d\n",ans);
	return 0;
}