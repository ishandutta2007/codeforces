#include<cstdio>
const int N=100002;
int n,i,j,k,A[N],B[N],a,b,h[N],t[N],v[N],ans;
bool vis[N];
void add(int a,int b){
	t[++k]=h[a];
	h[a]=k;
	v[k]=b;
}
void init(){
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		scanf("%d%d",A+i,B+i);
	for(a=1;a<=n;a++)
		for(b=1;b<=n;b++)
			if(a!=b&&B[a]==A[b])
				vis[b]=1;
}
void work(){
	for(i=1;i<=n;i++)
		if(!vis[i])
			ans++;
	printf("%d",ans);
}
int main(){
	init();
	work();
	return 0;
}