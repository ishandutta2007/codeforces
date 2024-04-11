#include<cstdio>
int q,n,a,s,i;
int main(){
	scanf("%d",&q);
	while(q--){
		scanf("%d",&n);
		s=0;
		for(i=1;i<=n;i++)
			scanf("%d",&a),s+=a;
		printf("%d\n",(s+n-1)/n);
	}
}