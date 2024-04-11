#include<cstdio>
#include<map>
using namespace std;
int n,k,p,i,a,s;
long long ans;
map<int,int>f;
void init(){
	scanf("%d%d",&n,&k);
	p=(1<<k)-1;
	f[0]=1;
	for(i=1;i<=n;i++){
		scanf("%d",&a);
		s^=a;
		ans+=f[s]+f[s^p]>>1;
		f[s]++;
	}
	printf("%lld",1ll*n*(n+1)/2-ans);
	//while(1);
}
int main(){
	init();
	return 0;
}