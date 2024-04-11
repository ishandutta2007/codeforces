#include <bits/stdc++.h>

int n,arr[105],vis[105]={0},cnt=0;

int main(){
	int n;scanf("%d",&n);
	for (int i=1;i<=n;++i)scanf("%d",&arr[i]);
	std::sort(arr+1,arr+n+1);
	for (int i=1;i<=n;++i){
		if (!vis[i]){
			cnt++;
			for (int j=i;j<=n;++j){
				if (arr[j]%arr[i]==0)vis[j]=1;
			}
		}
	}printf("%d",cnt);
	return 0;
}