#include<bits/stdc++.h>
using namespace std;
const int N=3e5+9;
int a[N];
int main(){
	int T; cin>>T;
	while(T--){
		int n; scanf("%d",&n);
		for(int i=1;i<=n;i++) scanf("%d",&a[i]);
		sort(a+1,a+n+1);
		int ans=0,tmp=0;
		for(int i=1;i<=n;i++){
			tmp++;
			if(a[i]<=tmp) tmp=0,ans++;
		}
		printf("%d\n",ans);
	}
	return 0;
}