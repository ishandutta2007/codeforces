#include<bits/stdc++.h>
using namespace std;
const int N=1e6+9;
int a[N],s[N];
int main(){
	int T; cin>>T;
	while(T--){
		bool ans=0;
		int n,k; scanf("%d%d",&n,&k);
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
			if(a[i]>=k) s[i]=s[i-1]+1;
			else s[i]=s[i-1];
			if(a[i]==k) ans=1;
		}
		if(!ans){puts("no");continue;}
		ans=0;
		for(int i=1;i<=n-2;i++){
			ans|=(s[i+2]-s[i-1]>1);
		}
		if(n==1) ans=(a[n]==k);
		if(n==2) ans=((a[1]==k&&a[2]>=k)||(a[2]==k&&a[1]>=k));
		if(ans) puts("yes");
		else puts("no");
	}
	return 0;
}