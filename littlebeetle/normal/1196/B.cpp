#include<cstdio>
const int N=200002;
int T,n,k,s,i,a[N];
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&k);
		s=0;
		for(i=1;i<=n;i++){
			scanf("%d",a+i);
			s+=a[i]%2;
		}
		if(s<k||(s-k)%2!=0)
			printf("NO\n");
		else{
			printf("YES\n");
			s=0;
			for(i=1;i<=n;i++)
				if(a[i]%2){
					s++;
					if(s<k)
						printf("%d ",i);
					else
						break;
				}
			printf("%d\n",n);
		}
	}
}