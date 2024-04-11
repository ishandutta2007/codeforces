#include <bits/stdc++.h>

int vis[200005]={0},arr[200005],n,tail=0,arr2[200005],q;

int main() {
	scanf("%d",&q);
	while (q--) {
		scanf("%d",&n);
		for (int i=1;i<=n;++i) {
			scanf("%d",&arr[i]);vis[arr[i]]++;
		}tail=0;
		for (int i=1;i<=n;++i) {
			if (vis[i]!=0) {
				arr2[++tail]=vis[i];vis[i]=0;
			}
		}std::sort(arr2+1,arr2+tail+1);
		int last=n+1,ans=0;
		for (int i=tail;i>=1;i--) {
			int det=std::max(0,std::min(arr2[i],last-1));
			last=det;ans+=det;
		}printf("%d\n",ans);
	}return 0;
}