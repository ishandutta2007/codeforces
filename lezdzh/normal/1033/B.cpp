#include<cstdio>

using namespace std;

int main(){
	int t;
	scanf("%d",&t);
	for(int tt=1;tt<=t;tt++){
		long long a,b;
		scanf("%I64d%I64d",&b,&a);
		if(b-a!=1){
			printf("NO\n");
			continue;
		}
		b+=a;
		for(long long i=2;i*i<=b;i++)
			if(b%i==0){printf("NO\n");goto ed;}
		printf("YES\n");
		ed:;
	}
}