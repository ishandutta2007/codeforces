#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[309][309];
signed main(){
	int T; cin>>T;
	while(T--) {
		int n,k; scanf("%lld%lld",&n,&k);
		int q=k/n; int p=k%n;
		memset(a,0,sizeof(a));
		for(int i=1;i<=q;i++){
			int x=i,y=1;
			for(;y<=n;y++,x=((x+1)%n==0?n:(x+1)%n))
				a[x][y]=1;
		} 
		for(int x=q+1,y=1,i=1;i<=p;i++,y++,x=((x+1)%n==0?n:(x+1)%n))
			a[x][y]=1;
		if(p==0) puts("0");
		else puts("2");
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++) printf("%d",a[i][j]);
			putchar('\n');
		}
	}
	return 0;
}