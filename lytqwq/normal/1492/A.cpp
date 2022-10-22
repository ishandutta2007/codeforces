#include<bits/stdc++.h>
using namespace std;
int T;
long long int p,a,b,c;
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%lld%lld%lld%lld",&p,&a,&b,&c);
		if(p%a==0||p%b==0||p%c==0)printf("%lld\n",0ll);
		else printf("%lld\n",min(a-p%a,min(b-p%b,c-p%c))); 
	}
	return 0;
}