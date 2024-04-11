#include<cstdio>
#include<vector>
using namespace std;
const int N=1002;
int n,i,j,k,L[N],R[N],d[N],ans,sum;
vector<int>t[N];
void dfs(int i,int fa){
	for(int j=0;j<t[i].size();j++)
		if(t[i][j]!=fa){
			d[t[i][j]]=d[i]+1;
			dfs(t[i][j],i);
		}
}
void work(int i){
	int x,y;
	for(x=1;x<=n;x++)
		d[x]=0;
	d[i]=1;
	dfs(i,0);
	for(y=0,x=1;x<=n;x++)
		if(d[x]>d[y])
			y=x;
	for(x=1;x<=n;x++)
		d[x]=0;
	d[y]=1;
	dfs(y,0);
	for(y=0,x=1;x<=n;x++)
		if(d[x]>d[y])
			y=x;
	sum*=d[y]-1;
}
int main(){
	scanf("%d",&n);
	for(i=1;i<n;i++)
		scanf("%d%d",L+i,R+i);
	for(k=1;k<n;k++){
		for(i=1;i<=n;i++)
			t[i].clear();
		for(i=1;i<n;i++)
			if(i!=k){
				t[L[i]].push_back(R[i]);
				t[R[i]].push_back(L[i]);
			}
		sum=1;
		work(L[k]);
		work(R[k]);
		if(sum>ans)
			ans=sum;
	}
	printf("%d",ans);
}