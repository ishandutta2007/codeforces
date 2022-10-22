#include<bits/stdc++.h>
using namespace std;
#define ri register int
typedef long long ll;
const int maxn=2e5+10;
int t_case;
ll a[21],cnt,n;
int main(){
	a[1]=2050;
	for(ri i=2;i<=15;++i)a[i]=a[i-1]*10;
	scanf("%d",&t_case);
	while(t_case--){
		scanf("%lld",&n);
		cnt=0;
		for(ri i=15;i;--i)
			while(n>=a[i])
				n-=a[i],++cnt;
		printf("%d\n",n?-1:cnt);
	}
	return 0;
}