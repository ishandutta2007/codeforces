#include<bits/stdc++.h>
using namespace std;
const int maxn=100005;
int n,m,T,ans,flg;
int a[maxn],b[maxn],u[maxn],v[maxn];
int main(){
	scanf("%d",&T);
	while(T--){
		ans=flg=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		for(int i=1;i<=n;i++)
			scanf("%d",&b[i]);
		int ans=0;
		for(int t=29;t>=0;t--){
			ans^=(1<<t);
			for(int i=1;i<=n;i++)
				u[i]=a[i]&ans,v[i]=(b[i]&ans)^ans;
			sort(u+1,u+1+n),sort(v+1,v+1+n);
			int flg=1;
			for(int i=1;i<=n;i++)
				flg&=(u[i]==v[i]);
			if(flg==0)
				ans^=(1<<t);
		}
		printf("%d\n",ans);
	}
	return 0;
}