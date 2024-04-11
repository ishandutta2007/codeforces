#include<bits/stdc++.h>
using namespace std;
const int N=100;
int t,n,a[N];
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		int ans=0;
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
			if(i>=2){
				int minn=min(a[i-1],a[i]),maxn=max(a[i-1],a[i]);
				while(maxn>2*minn){
					minn*=2;
					ans++;
				}
				
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}