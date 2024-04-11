#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=20002;
typedef long long ll;
ll T,n,d[N],i,x;
bool f[N];
ll D(ll x){
	ll s=0,i;
	for(i=1;i*i<x;i++)
		if(x%i==0)
			s+=2;
	if(i*i==x)
		s++;
	return s;
}
void work(){
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
		scanf("%lld",d+i);
	sort(d+1,d+n+1);
	x=d[1]*d[n];
	for(i=1;i<=n;i++)
		if(x%d[i]){
			printf("-1\n");
			return;
		}
	if(D(x)!=n+2){
		printf("-1\n");
		return;
	}
	printf("%lld\n",x);
}
int main(){
	scanf("%d",&T);
	while(T--){
		work();
	}
	return 0;
}