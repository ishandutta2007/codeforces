#include<cstdio>

using namespace std;

int main(){
	int t;
	scanf("%d",&t);
	for(int tt=1;tt<=t;tt++){
		long long n;
		int nn;
		scanf("%lld",&n);
		nn=(n-1)%3;
		n=(n-1)/3;
		long long i=1;
		for(;;){
			if(n>=i){
				n-=i;
				i*=4;
				continue;
			}
			long long o1=n+i,o2=i*2;
			for(int j=0;1ll<<j<i;j+=2){
				if((o1>>j&3)==0);
				if((o1>>j&3)==1)o2+=2ll<<j;
				if((o1>>j&3)==2)o2+=3ll<<j;
				if((o1>>j&3)==3)o2+=1ll<<j;
			}
			printf("%lld\n",nn==0?o1:nn==1?o2:o1^o2);
			break;
		}
	}
}