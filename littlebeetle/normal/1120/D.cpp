#include<cstdio>
#include<algorithm>
using namespace std;
const int N=600002;
struct P{
	int x,y,z,id;
	bool operator<(const P &k)const{
		return k.z>z;
	}
}e[N];
int n,m,cnt,i,j,k,a,b,val[N],h[N],t[N],v[N],L[N],R[N],fa[N],x,y,X[N],Y[N],g[N],sum;
long long ans;
int max(int x,int y){
	return x>y?x:y;
}
int min(int x,int y){
	return x<y?x:y;
}
void dfs(int i,int fa){
	int s=0;L[i]=1<<30,R[i]=0;
	for(int j=h[i];j;j=t[j])
		if(v[j]!=fa){
			dfs(v[j],i);
			s++;
			L[i]=min(L[i],L[v[j]]);
			R[i]=max(R[i],R[v[j]]);
		}
	if(!s)
		L[i]=R[i]=++cnt;
	e[++m]=(P){L[i],R[i]+1,val[i],i};
}
int p(int x){
	return x==fa[x]?x:fa[x]=p(fa[x]);
}
int main(){
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		scanf("%d",val+i);
	for(i=1;i<n;i++){
		scanf("%d%d",&a,&b);
		t[++k]=h[a];h[a]=k;v[k]=b;
		t[++k]=h[b];h[b]=k;v[k]=a;
	}
	dfs(1,0);
	cnt++;
	for(i=1;i<=cnt;i++)
		fa[i]=i;
	sort(e+1,e+m+1);
	for(i=1;i<=m;i++){
		for(j=0;e[i+j].z==e[i].z;j++){
			X[j]=e[i+j].x;Y[j]=e[i+j].y;
		}
		for(k=0;k<j;k++){
			x=X[k];y=Y[k];
			if(p(x)!=p(y))
				g[e[i+k].id]=1,sum++;
		}
		for(k=0;k<j;k++){
			x=X[k];y=Y[k];		
			if(p(x)!=p(y)){
				ans+=e[i+k].z;
				fa[p(x)]=y;
			}
		}
		i+=j-1;
	}
	printf("%I64d %d\n",ans,sum);
	for(i=1;i<=n;i++)
		if(g[i])
			printf("%d ",i);
}