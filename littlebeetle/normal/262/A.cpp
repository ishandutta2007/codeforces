#include<cstdio>
int n,k,i,a,s,sum;
int main(){
	scanf("%d%d",&n,&k);
	for(i=1;i<=n;i++){
		scanf("%d",&a);
		s=0;
		while(a){
			if(a%10==4||a%10==7)
				s++;
			a/=10;
		}
		if(s<=k)
			sum++;
	}
	printf("%d",sum);
}