#include<cstdio>
const int N=200002;
int n,a,b,i,j,k;
int col[N],h[N],t[N],v[N];
int cnt[N],sz[N],e[N];
int maxcnt;
long long sum,Ans[N];
void add(int a,int b){
	t[++k]=h[a];
	h[a]=k;
	v[k]=b;
}
void init(){
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		scanf("%d",col+i);
	for(i=1;i<n;i++){
		scanf("%d%d",&a,&b);
		add(a,b);
		add(b,a);
	}
}
void dfs1(int i,int fa){
	sz[i]=1;
	for(int j=h[i];j;j=t[j])
		if(v[j]!=fa){
			dfs1(v[j],i);
			sz[i]+=sz[v[j]];
			if(sz[v[j]]>sz[e[i]])
				e[i]=v[j];
		}
}
void clr(int i,int fa){
	cnt[col[i]]--;
	for(int j=h[i];j;j=t[j])
		if(v[j]!=fa)
			clr(v[j],i);
}
void Add(int x){
	cnt[x]++;
	if(cnt[x]==maxcnt)
		sum+=x;
	else
		if(cnt[x]>maxcnt)
			maxcnt=cnt[x],sum=x;
}
void Cover(int i,int fa){
	Add(col[i]);
	for(int j=h[i];j;j=t[j])
		if(v[j]!=fa)
			Cover(v[j],i);
}
void dfs2(int i,int fa){
	if(sz[i]==1){
		Add(col[i]);
		Ans[i]=sum;
		return;
	}
	for(int j=h[i];j;j=t[j])
		if(v[j]!=fa&&v[j]!=e[i]){
			dfs2(v[j],i);
			clr(v[j],i);
			maxcnt=sum=0;
		}
	dfs2(e[i],i);
	for(int j=h[i];j;j=t[j])
		if(v[j]!=fa&&v[j]!=e[i])
			Cover(v[j],i);	
	Add(col[i]);
	Ans[i]=sum;
}
void work(){
	dfs1(1,0);
	dfs2(1,0);
	for(i=1;i<=n;i++)
		printf("%lld ",Ans[i]);
}
int main(){
	init();
	work();
	return 0;
}