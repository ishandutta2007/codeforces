#include<cstdio>
const int MAXN=1e5+5;
int n,k;
int pre[MAXN];
int fnd(int x){
	if(x!=pre[x]) pre[x]=fnd(pre[x]);
	return pre[x];
}
int ans;
int main(){
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
		pre[i]=i;
	for(int i=1;i<=k;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		x=fnd(x),y=fnd(y);
		if(x!=y) pre[x]=y;
		else ans++;
	}
	printf("%d\n",ans);
	return 0;
}