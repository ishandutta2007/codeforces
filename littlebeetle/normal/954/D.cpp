#include<cstdio>
#include<cstring>
const int N=1002,M=20002;
int n,m,S,T,i,j,k,a,b,c,h[N],t[M],v[M],q[N],s,e,d1[N],d2[N],len,ans;
bool p[N][N];
void add(int a,int b){
	t[++k]=h[a];h[a]=k;v[k]=b;
}
void bfs(int S,int *d){
	for(i=1;i<=n;i++)d[i]=1<<29;
	d[q[s=e=0]=S]=0;
	while(s<=e)
		for(j=h[i=q[s++]];j;j=t[j])
			if(d[v[j]]>d[i]+1)
				d[v[j]]=d[i]+1,q[++e]=v[j];
}
int main(){
	scanf("%d%d%d%d",&n,&m,&S,&T);
	while(m--){
		scanf("%d%d",&a,&b);
		p[a][b]=p[b][a]=1;
		add(a,b);add(b,a);
	}
	bfs(S,d1);
	bfs(T,d2);
	len=d1[T];
	for(i=1;i<=n;i++)
		for(j=i+1;j<=n;j++)
			if(!p[i][j]&&d1[i]+d2[j]+1>=len&&d1[j]+d2[i]+1>=len)
				ans++;
	printf("%d",ans);
}