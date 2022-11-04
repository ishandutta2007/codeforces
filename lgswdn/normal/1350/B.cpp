#include<bits/stdc++.h>
using namespace std;
const int N=1e5+9;
int a[N],f[N];
int main(){
	int T; cin>>T;
	while(T--){
		int n; scanf("%d",&n); int ans=1;
		for(int i=1;i<=n;i++) scanf("%d",&a[i]),f[i]=1;
		for(int i=2;i<=n;i++){
			for(int j=1;j<=sqrt(i);j++){
				if(i%j==0){
					if(a[j]<a[i]) f[i]=max(f[i],f[j]+1);
					if(a[i/j]<a[i]) f[i]=max(f[i],f[i/j]+1);
				}
			}
			ans=max(ans,f[i]);
		}
		printf("%d\n",ans);
	}
	return 0;
}