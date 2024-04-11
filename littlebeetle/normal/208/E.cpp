#include<cstdio>
#include<vector>
using namespace std;
const int N=100002;
struct Q{
	int id,p;
};
int n,m,a,b,i,j,k,h[N],t[N],v[N],dep[N],Lst[N],ans[N],sum[N];
vector<Q>x[N],y[N];
void dfs(int i){
	Lst[dep[i]]=i;
	for(int j=0;j<x[i].size();j++)
		if(x[i][j].p<=dep[i])
			y[Lst[dep[i]-x[i][j].p]].push_back(x[i][j]);
	for(int j=h[i];j;j=t[j])
		dep[v[j]]=dep[i]+1,
		dfs(v[j]);
}
void DFS(int i){
	sum[dep[i]]++;
	for(int j=0;j<y[i].size();j++)
		ans[y[i][j].id]-=sum[dep[i]+y[i][j].p];
	for(int j=h[i];j;j=t[j])
		dep[v[j]]=dep[i]+1,
		DFS(v[j]);
	for(int j=0;j<y[i].size();j++)
		ans[y[i][j].id]+=sum[dep[i]+y[i][j].p];	
}	
int main(){
	scanf("%d",&n);
	for(b=1;b<=n;b++){
		scanf("%d",&a);
		if(a)
			t[++k]=h[a],h[a]=k,v[k]=b;
	}
	scanf("%d",&m);
	for(i=1;i<=m;i++){
		scanf("%d%d",&a,&b);
		x[a].push_back((Q){i,b});
	}
	for(i=1;i<=n;i++)
		if(!dep[i]){
			dep[i]=1;
			dfs(i);
		}
	for(i=1;i<=n;i++)
		dep[i]=0;
	for(i=1;i<=n;i++)
		if(!dep[i]){
			dep[i]=1;
			DFS(i);
		}
	for(i=1;i<=m;i++)
		printf("%d ",ans[i]?ans[i]-1:0);
	return 0;
}