#include<cstdio>
#include<algorithm>
using namespace std;

char s[1000001],t[1000001];
long long z[1000001],c[1000001];
int main(){
	int n,k;
	scanf("%d%d%s%s",&n,&k,s+1,t+1);
	if(k==1){
		printf("%d\n",k*n);
		return 0;
	}
	int o=1;
	while(o<=n&&s[o]==t[o])o++;
	if(o>n){
		printf("%d\n",n);
		return 0;
	}
	long long ans=n+(n-o+1);
	k-=2;
	o++;
	while(o<=n){
		if(s[o]=='a')z[n-o+1]++;
		if(t[o]=='b')z[n-o+1]++;
		o++;
	}
	for(int i=n;i;i--){
		z[i]+=c[i];
		c[i-1]+=c[i];
		int kk=min(1ll*k,z[i]);
		ans+=1ll*i*kk;
		k-=kk;
		c[i-1]+=kk;
	}
	printf("%I64d\n",ans);
}