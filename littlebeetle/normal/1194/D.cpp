#include<cstdio>
int t,n,k;
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&k);
		if(k%3){
			if(n%3==0)
				printf("Bob\n");
			else
				printf("Alice\n");
		}
		else{
			n%=k+1;
			if(n==k)
				printf("Alice\n");
			else{
				if(n%3==0)
					printf("Bob\n");
				else
					printf("Alice\n");
			}
		}
	}
}