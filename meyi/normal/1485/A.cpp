#include<bits/stdc++.h>
using namespace std;
#define ri register int
int a,ans,b,t;
inline int _div(int x,int y){
	int ret=0;
	while(x)x/=y,++ret;
	return ret;
}
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&a,&b);
		ans=INT_MAX;
		ri i=max(2,b);
		for(;i*i<=a;++i)ans=min(ans,_div(a,i)+i-b);
		printf("%d\n",min(ans,_div(a,i)+i-b));
	}
	return 0;
}