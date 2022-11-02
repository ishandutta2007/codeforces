#include<cstdio>
const int N=200002;
int n,i,j,k,a,b,c,h[N],t[N],v[N],w[N],s[N],p;
bool dfs(int i,int fa){
	bool x=0,y;
	for(int j=h[i];j;j=t[j])
		if(v[j]!=fa){
			y=dfs(v[j],i);
			if(w[j]==2&&!y){
				s[++p]=v[j];
				x=1;
			}
			if(y)
				x=1;
		}
	return x;
}
int main(){
	scanf("%d",&n);
	for(i=1;i<n;i++){
		scanf("%d%d%d",&a,&b,&c);
		t[++k]=h[a];h[a]=k;v[k]=b;w[k]=c;
		t[++k]=h[b];h[b]=k;v[k]=a;w[k]=c;
	}
	dfs(1,0);
	printf("%d\n",p);
	for(i=1;i<=p;i++)
		printf("%d ",s[i]);
	return 0;
}