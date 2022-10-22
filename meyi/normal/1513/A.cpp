#include<bits/stdc++.h>
using namespace std;
#define ri register int
typedef long long ll;
const int maxn=2e5+10;
int cnt1,cnt2,k,n,t_case;
int main(){
	scanf("%d",&t_case);
	while(t_case--){
		scanf("%d%d",&n,&k);
		if(k*2>=n){
			puts("-1");
			continue;
		}
		cnt1=1,cnt2=0;
		printf("1 ");--n;
		for(ri i=1;i<=k;++i){
			printf("%d %d ",cnt1+=2,cnt2+=2);
			n-=2;
		}
		while(n--)printf("%d ",++cnt1);
		puts("");
	}
	return 0;
}