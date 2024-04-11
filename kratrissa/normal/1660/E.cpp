#include<bits/stdc++.h>
using namespace std;
const int N=2005;
int T,n,tot,c[N],ans;bool a[N][N];char s[N];
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n),tot=0,ans=1e9;fill(c,c+n,0);
		for(int i=1;i<=n;i++){
			scanf("%s",s+1);
			for(int j=1;j<=n;j++)a[i][j]=(s[j]=='1'),tot+=a[i][j],c[(j-i+n)%n]+=a[i][j];
		}
		for(int i=0;i<n;i++)ans=min(ans,n+tot-2*c[i]);
		printf("%d\n",ans);
	}
	return 0;
}