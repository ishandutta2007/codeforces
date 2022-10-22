#include<bits/stdc++.h>
using namespace std;
#define ri register int
const int maxn=1e5+10;
int t,x,y;
unsigned long long ans;
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&x,&y);
		if(y>=x)y=x-1;
		ans=0;
		ri b=2;
		for(;b<=y;++b){
			int tmp=x/(b+1);
			if(tmp<=b-1)break;
			ans+=b-1;
		}
		++b,++y;
		for(;b<=y;){
			int nxt=min(x/(x/b),y);
			ans+=1ull*(nxt-b+1)*(x/b);
			b=nxt+1;
		}
		printf("%llu\n",ans);
	}
	return 0;
}