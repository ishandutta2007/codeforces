#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using std::max;
using std::sort;
using std::unique;
using std::lower_bound;
using std::vector;
inline int lowbit(int x)
{
	return x&-x;
}
struct cell
{
	int *f,v;
};
const int N=1e6+5;
int n,k,ans;
int a[N],b[N];
vector<int> V;
vector<cell> C;
int bit[N];
inline void undo()
{
	while(!C.empty())
		(*C.back().f)=C.back().v,C.pop_back();
	return;
}
inline void add(int x,int k)
{
	while(x<=n)
		C.push_back(cell{&bit[x],bit[x]}),bit[x]=max(bit[x],k),x+=lowbit(x);
	return;
}
inline int ask(int x)
{
	int res=0xc0c0c0c0;
	while(x)
		res=max(bit[x],res),x-=lowbit(x);
	return res;
}
signed main()
{
	int res,cur;
	register int i,j;
	scanf("%d%d",&n,&k);
	for(i=1;i<=n;i++)
		scanf("%d",&a[i]),a[i]-=i,V.push_back(a[i]);
	for(i=1;i<=k;i++)
		scanf("%d",&b[i]);
	sort(V.begin(),V.end());
	int _=unique(V.begin(),V.end())-V.begin();
	while((int)V.size()>_)
		V.pop_back();
	for(i=1;i<=n;i++)
		a[i]=lower_bound(V.begin(),V.end(),a[i])-V.begin()+1;
	for(i=2;i<=k;i++)
		if(a[b[i-1]]>a[b[i]])
			return puts("-1"),0;
	memset(bit,0xc0,sizeof(bit));
	if(k==0)
	{
		add(1,0);cur=0;
		for(i=1;i<=n;i++)
		{
			res=ask(a[i]);
			cur=max(cur,res+1);
			add(a[i],res+1);
		}
		printf("%d\n",n-cur);
		return 0;
	}
	add(1,0);cur=0;
	for(j=1;j<b[1];j++)
	{
		if(a[j]>a[b[1]])
			continue;
		res=ask(a[j]);
		cur=max(cur,res+1);
		add(a[j],res+1);
	}
	ans+=(b[1]-1)-cur;
	for(i=2;i<=k;i++)
	{
		undo();add(a[b[i-1]],0);cur=0;
		for(j=b[i-1]+1;j<b[i];j++)
		{
			if(a[j]>a[b[i]])
				continue;
			res=ask(a[j]);
			cur=max(cur,res+1);
			add(a[j],res+1);
		}
		ans+=(b[i]-b[i-1]-1)-cur;
	}
	undo();add(a[b[k]],0);cur=0;
	for(j=b[k]+1;j<=n;j++)
	{
		res=ask(a[j]);
		cur=max(cur,res+1);
		add(a[j],res+1);
	}
	ans+=(n-b[k])-cur;
	printf("%d\n",ans);
	return 0;
}