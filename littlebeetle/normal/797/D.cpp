#include<cstdio>
#include<map>
using namespace std;
const int N=100002;
int n,i,val[N],L[N],R[N],deg[N],rt,ans;
int x[N],y[N];
map<int,int>P;
int min(int x,int y){
	return x<y?x:y;
}
int max(int x,int y){
	return x>y?x:y;
}
void init(){
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d%d%d",val+i,L+i,R+i);
		if(~L[i])deg[L[i]]++;
		if(~R[i])deg[R[i]]++;
		P[val[i]]++;
	}
	for(i=1;i<=n;i++)
		if(deg[i]==0)
			rt=i;
}
void dfs(int i){
	if(x[i]<=val[i]&&val[i]<=y[i]){
		ans-=P[val[i]];
		P[val[i]]=0;
	}
	if(~L[i]){
		x[L[i]]=x[i];
		y[L[i]]=min(val[i]-1,y[i]);
		dfs(L[i]);
	}
	if(~R[i]){
		y[R[i]]=y[i];
		x[R[i]]=max(val[i]+1,x[i]);
		dfs(R[i]);
	}
}
int main(){
	init();
	x[rt]=-1;y[rt]=1<<30;
	ans=n;
	dfs(rt);
	printf("%d",ans);
}