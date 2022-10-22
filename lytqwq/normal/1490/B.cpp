#include<bits/stdc++.h>
using namespace std;
const int N=30100;
int T,n,a[N];
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		int c0=0,c1=0,c2=0,ans=0;
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
			if(a[i]%3==0)c0++;
			if(a[i]%3==1)c1++;
			if(a[i]%3==2)c2++;
		}
		while(c0>n/3||c1>n/3||c2>n/3){
		if(c0>n/3){
			c1+=(c0-n/3);
			ans+=(c0-n/3);
			c0=n/3;
		}
		if(c1>n/3){
			c2+=(c1-n/3);
			ans+=(c1-n/3);
			c1=n/3;
		}
		if(c2>n/3){
			c0+=(c2-n/3);
			ans+=(c2-n/3);
			c2=n/3;
		}
		
		}
		printf("%d\n",ans);
	}
	return 0;
}