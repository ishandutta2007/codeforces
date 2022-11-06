#include<bits/stdc++.h>
using namespace std;

int n,m,a[10005],ans[10005],sum[10005];
int main(){
	scanf("%d%d",&n,&m);
	int i,j,tmp;
	for (i=1; i<=m; i++){
		scanf("%d",&a[i]);
		if (i>1){
			tmp=(a[i]-a[i-1]+n-1+n)%n+1;
			if (ans[a[i-1]]>0 && ans[a[i-1]]!=tmp){ puts("-1"); return 0; }
			ans[a[i-1]]=tmp;
		}
	}
	for (i=1; i<=n; i++) if (ans[i]){
		if (sum[ans[i]]>0){ puts("-1"); return 0; }
		sum[ans[i]]++;
	}
	for (i=1; i<=n; i++) if (!ans[i]){
		for (j=1; j<=n; j++) if (!sum[j]){
			sum[j]=1; ans[i]=j; break;
		}
	}
	for (i=1; i<=n; i++) printf("%d%c",ans[i],(i<n)?' ':'\n');
	return 0;
}