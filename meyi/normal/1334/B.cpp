#include<bits/stdc++.h>
using namespace std;
#define ri register int
typedef long long ll;
const int maxn=1e5+10;
int a[maxn],n,x,t;
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&x);
		for(ri i=1;i<=n;++i)scanf("%d",a+i);
		sort(a+1,a+n+1);
		ll sum=0;
		bool flag=true;
		for(ri i=n;i;--i){
			sum+=a[i];
			if(sum/(n-i+1)<x){
				printf("%d\n",n-i);
				flag=false;
				break;
			}
		}
		if(flag)printf("%d\n",n);
	}
	return 0;
}