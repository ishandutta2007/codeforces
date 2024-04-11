#include<cstdio>
const int N=1e5+5;
int v[N<<1],first[N],next[N<<1];
int tree[N]={0,100001},ceng[N];
int n;
double ans=0;
inline void maketree(int now,int step,double hope)
{
	int go,num=0;
	for(go=first[now];go;go=next[go])
		if(!tree[v[go]])
			num++;
	if(!num)
	{
		ans+=hope*ceng[now];
		return;
	}
	for(go=first[now];go;go=next[go])
		if(!tree[v[go]])
		{
			tree[v[go]]=now;
			ceng[v[go]]=step;
			maketree(v[go],step+1,hope/(double)num);
		}
	return;
}
signed main()
{
	int i,j,u;
	scanf("%d",&n);
	for(i=1;i<=2*(n-1);i++)
	{
		scanf("%d%d",&u,&v[i]);
		next[i]=first[u];
		first[u]=i;
		i++;
		v[i]=u;
		u=v[i-1];
		next[i]=first[u];
		first[u]=i;
	}
	maketree(1,1,1);
	printf("%0.9lf\n",ans);
	return 0;
}