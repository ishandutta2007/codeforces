#include<cstdio>
int T,n,m,p1,p2,q1,q2,a;
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		p1=p2=q1=q2=0;
		while(n--){
			scanf("%d",&a);
			if(a%2)p1++;
			else p2++;
		}
		scanf("%d",&m);
		while(m--){
			scanf("%d",&a);
			if(a%2)q1++;
			else q2++;
		}
		printf("%lld\n",1ll*p1*q1+1ll*p2*q2);
	}
}