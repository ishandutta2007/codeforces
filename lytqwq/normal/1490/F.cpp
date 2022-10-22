#include<bits/stdc++.h>
using namespace std;
const int N=200010;
int T,n,a[N];
int vis[N],top,sum[N];
int main(){
	scanf("%d",&T);
	while(T--){
		top=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
		}
		int ans=n;
		sort(a+1,a+n+1);
		for(int i=1;i<=n;i++){
			if(a[i]!=a[i-1]){
				vis[++top]=1;
			}
			else{
				vis[top]++;
			}
		}
		sort(vis+1,vis+top+1);
		sum[top+1]=0;
		for(int i=top;i>=1;i--){
			sum[i]=sum[i+1]+vis[i];
		}
		int res=0;
		for(int i=1;i<=top;i++){
			ans=min(ans,res+sum[i]-vis[i]*(top-i+1));
			res+=vis[i];
		}
		printf("%d\n",ans);
	}
	return 0;
}