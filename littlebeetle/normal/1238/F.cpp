#include<cstdio>
const int N=600002;
int q,n,a,b,d[N],i,j,k,x,y;
int h[N],t[N],v[N],dep[N];
void add(int a,int b){
	t[++k]=h[a];
	h[a]=k;
	v[k]=b;
	d[b]++;
}
void init(){
	scanf("%d",&n);
	k=0;
	for(i=1;i<=n;i++)
		h[i]=0,d[i]=0;
	for(i=1;i<n;i++){
		scanf("%d%d",&a,&b);
		add(a,b);
		add(b,a);
	}
	for(i=1;i<=n;i++)
		d[i]--;
}
void dfs(int i,int fa){
	if(dep[i]>dep[x])
		x=i;
	for(int j=h[i];j;j=t[j])
		if(v[j]!=fa){
			dep[v[j]]=dep[i]+d[v[j]];
			dfs(v[j],i);
		}
}
void work(){
	x=y=0;
	dep[1]=d[1];
	dfs(1,0);
	y=x;x=0;
	dep[y]=d[y];
	dfs(y,0);
	printf("%d\n",dep[x]+2);
}
int main(){
	scanf("%d",&q);
	while(q--){
		init();
		work();
	}
	//while(1);
	return 0;
}