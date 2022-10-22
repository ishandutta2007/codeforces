#include<bits/stdc++.h>
using namespace std;
#define ri register int
typedef long long ll;
const int maxn=110;
int a[maxn],n,t;
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(ri i=1;i<=n;++i)scanf("%d",a+i);
		if(n==1){
			puts("1");
			continue;
		}
		sort(a+1,a+n+1);
		int cnt=1;
		for(ri i=2;i<=n;++i)
			if(a[i]==a[1])++cnt;
			else break;
		printf("%d\n",n-cnt);
	}
	return 0;
}