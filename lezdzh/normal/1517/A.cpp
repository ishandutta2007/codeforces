#include<cstdio>

using namespace std;

int main(){
	int t;
	scanf("%d",&t);
	for(int tt=1;tt<=t;tt++){
		long long n;
		scanf("%lld",&n);
		if(n%2050)printf("-1\n");
		else{
			n/=2050;
			int ans=0;
			while(n)ans+=n%10,n/=10;
			printf("%d\n",ans);
		}
	}
}