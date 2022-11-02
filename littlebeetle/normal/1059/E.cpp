#include<cstdio>
#include<algorithm>
using namespace std;
const int N=100002;
typedef long long ll;
int n,L,i,j,k,w[N],dep[N],fa[N],h[N],v[N],t[N],id[N],anc[N],a,b,f[N],ans,o[N];
ll S,s[N];
void dfs(int i,int l){
	id[dep[i]]=i;
	s[dep[i]]=w[i]+s[dep[i]-1];
	if(w[i]>S)
		anc[i]=n+1;
	else{
		while(s[dep[i]]-s[l-1]>S)
			l++;
		while(dep[i]-l+1>L)
			l++;
		anc[i]=id[l];
	}
	for(int j=h[i];j;j=t[j])
		dep[v[j]]=dep[i]+1,dfs(v[j],l);
}
bool cmp(int x,int y){
	return dep[x]>dep[y];
}
int p(int x){
	return x==f[x]?x:f[x]=p(f[x]);
}
int main(){
	scanf("%d%d%I64d",&n,&L,&S);
	for(i=1;i<=n;i++)
		scanf("%d",w+i),o[i]=i,f[i]=i;
	for(b=2;b<=n;b++){
		scanf("%d",&a);
		t[++k]=h[a];
		h[a]=k;
		v[k]=b;
		fa[b]=a;
	}
	dep[1]=1;
	dfs(1,1);
	dep[n+1]=n+1;
	/*for(i=1;i<=n;i++)
		printf("%d %d\n",i,anc[i]);*/
	sort(o+1,o+n+1,cmp);
	for(k=1;k<=n;k++){
		i=o[k];
		if(p(i)==i){
			ans++;
			j=i;
			while(dep[p(j)]>=dep[anc[i]]){
				j=p(j);
				f[j]=fa[j];
			}
		}
	}
	for(i=1;i<=n;i++)
		if(p(i)){
			printf("-1"); 
			return 0;
		}
	printf("%d",ans);
	//while(1);
}