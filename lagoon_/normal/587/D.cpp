#include<bits/stdc++.h>
#define re register
std::vector<int>to[500100];
inline void addE(re int a,re int b)
{//printf("***%d %d\n",a,b);
	to[a].push_back(b);
}
inline void addE1(re int a,re int b)
{
	addE(a,b);addE(b^1,a^1);
}
int dfn[500100],low[500100],tot,sta[500100],tta,numm;
bool in[500100],on[500100],as[500100],ok;
void tar(re int a)
{
	re int x;
	low[a]=dfn[a]=++tot;
	in[a]=1;sta[++tta]=a;
	for(re int i=0;i<to[a].size();i++)if(!dfn[x=to[a][i]])
	{
		tar(x);low[a]=std::min(low[a],low[x]);
	}else if(in[x])low[a]=std::min(low[a],dfn[x]);
	if(low[a]==dfn[a])
	{
		re bool an=0;
		re int tta1=tta;
		do{an|=as[sta[tta]^1];on[sta[tta]]=1;in[sta[tta]]=0;numm++;}while(sta[tta--]!=a);
		tta=tta1;
		//printf("***%d %d %d %d\n",a,tta,sta[tta],ok);
		do{as[sta[tta]]=!an;if(on[sta[tta]^1])ok=0;on[sta[tta]]=0;numm++;}while(sta[tta--]!=a);
	}
}
bool SAT(re int n)
{
	ok=1;tot=0;tta=0;
	for(re int i=2;i<=2*n+1;i++)dfn[i]=as[i]=in[i]=on[i]=0;
	for(re int i=2;i<=2*n+1;i++)if(!dfn[i])tar(i);
	return ok;
}
int x[100100],y[100100],c[100100],t[100100],hd[100100],ta[100100],cnt;
std::unordered_map<int,int>mp[100100];
#define IT std::unordered_map<int,int>::iterator
int main()
{
	re int n,m,cl=clock(),lim=1;
	re IT it;
	scanf("%d%d",&n,&m);
	for(re int i=1;i<=m;i++)
	{
		scanf("%d%d%d%d",&x[i],&y[i],&c[i],&t[i]);
		re int xx=mp[x[i]][c[i]];
		if(xx==-1){puts("No");return 0;}
		else if(xx)addE1(i*2,xx*2+1),mp[x[i]][c[i]]=-1;
		else mp[x[i]][c[i]]=i;
		xx=mp[y[i]][c[i]];
		if(xx==-1){puts("No");return 0;}
		else if(xx)addE1(i*2,xx*2+1),mp[y[i]][c[i]]=-1;
		else mp[y[i]][c[i]]=i;
	}
	cnt=m;
	for(re int i=1;i<=m;i++)
	{
		cnt++;
		addE1(i*2+1,cnt*2+1);
		if(hd[x[i]])addE1(i*2+1,hd[x[i]]*2),addE1(cnt*2,hd[x[i]]*2);
		hd[x[i]]=cnt;
		cnt++;
		addE1(i*2+1,cnt*2+1);
		if(hd[y[i]])addE1(i*2+1,hd[y[i]]*2),addE1(cnt*2,hd[y[i]]*2);
		hd[y[i]]=cnt;
		cnt++;
		addE1(i*2+1,cnt*2);
		if(ta[x[i]])addE1(i*2+1,ta[x[i]]*2+1),addE1(ta[x[i]]*2,cnt*2);
		ta[x[i]]=cnt;
		cnt++;
		addE1(i*2+1,cnt*2);
		if(ta[y[i]])addE1(i*2+1,ta[y[i]]*2+1),addE1(ta[y[i]]*2,cnt*2);
		ta[y[i]]=cnt;
	}
	if(!SAT(cnt)){puts("No");return 0;}
	re int l=0,r=1e9,mid;
	for(mid=(l+r)/2;l<r;mid=(l+r)/2)
	{
		for(re int i=1;i<=m;i++)if(t[i]>mid)addE(i*2+1,i*2);
		if(SAT(cnt))r=mid;
		else l=mid+1;
		for(re int i=1;i<=m;i++)if(t[i]>mid)to[i*2+1].pop_back();
	}
	for(re int i=1;i<=m;i++)if(t[i]>l)addE(i*2+1,i*2);
	SAT(cnt);
	//if(n==220&&m==50000&&x[1]==45)printf("**%d\n",numm);
	re int n1=0;
	for(re int i=1;i<=m;i++)if(as[i*2+1])n1++;
	printf("Yes\n%d %d\n",l,n1);
	for(re int i=1;i<=m;i++)if(as[i*2+1])printf("%d ",i);puts("");
}