#include<cstdio>
const int N=10002;
int n,a[N],i,t;
void dfs(int i,int s){
	if(i==n+1){
		if(s%360==0)
			t=1;
		return;
	}
	dfs(i+1,s+a[i]);
	dfs(i+1,s-a[i]);
}
int main(){
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		scanf("%d",a+i);
	dfs(1,0);
	printf("%s",t?"YES":"NO");
}