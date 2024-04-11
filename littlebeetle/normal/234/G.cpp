#include<cstdio>
int n,k,i,j,s;
int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);	
	scanf("%d",&n);
	for(k=1;1<<k<=n-1;k++);
	printf("%d\n",k);
	while(k){
		s=0;
		for(i=0;i<n;i+=1<<k)
			for(j=1;j<=1<<k-1;j++)
				if(i+j<=n)
				s++;
		printf("%d ",s);
		for(i=0;i<n;i+=1<<k)
			for(j=1;j<=1<<k-1;j++)
				if(i+j<=n)
				printf("%d ",i+j);
		printf("\n");
		k--;
	}
}