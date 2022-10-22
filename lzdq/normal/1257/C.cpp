#include<cstdio>
const int MAXN=2e5+5;
int n,a[MAXN];
int pos[MAXN],pre[MAXN];
int ans;
int main(){
	int t;scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++) pos[i]=0;
		ans=n+1;
		for(int i=1;i<=n;i++){
			scanf("%d",a+i);
			pre[i]=pos[a[i]];
			pos[a[i]]=i;
			if(pre[i]&&ans>i-pre[i]+1) ans=i-pre[i]+1; 
		}
		if(ans>n) ans=-1;
		printf("%d\n",ans);
	}
	return 0;
}