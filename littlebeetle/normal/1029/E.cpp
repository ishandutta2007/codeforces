#include<cstdio>
const int N=400002;
int n,i,j,k,a,b,c,h[N],t[N],v[N],p[N],q[N],r[N],d[N];
int min(int x,int y){
	return x<y?x:y;
}
void dfs(int i,int fa){
	int s=0;
	for(int j=h[i];j;j=t[j])
		if(v[j]!=fa){
			d[v[j]]=d[i]+1;
			dfs(v[j],i);
			s+=min(p[v[j]],q[v[j]]);
		}
	q[i]=1<<30;
	for(int j=h[i];j;j=t[j])
		if(v[j]!=fa){
			r[i]+=min(p[v[j]],q[v[j]]);
			q[i]=min(s-min(p[v[j]],q[v[j]])+p[v[j]],q[i]);
			p[i]+=min(p[v[j]],min(q[v[j]],r[v[j]]));
		}
	if(d[i]>1)
		p[i]++;
	//printf("%d %d %d %d\n",p[i],q[i],r[i],d[i]);
}
int main(){
	scanf("%d",&n);
	for(i=1;i<n;i++){
		scanf("%d%d",&a,&b);
		t[++k]=h[a];h[a]=k;v[k]=b;
		t[++k]=h[b];h[b]=k;v[k]=a;
	}
	dfs(1,0);
	printf("%d",min(p[1],min(q[1],r[1])));
	return 0;
}