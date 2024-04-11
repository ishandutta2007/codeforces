#include<cstdio>
#include<cstdlib>
using namespace std;
const int N=200002;
int n,i,j,k,a[N],b[N];
void d(int x){
	i=2;
	while(i*i<=x){
		if(x%i==0){
			while(x%i==0)
				x/=i;
			k=1;
			for(j=1;j<=n;j++)
				if(a[j]%i&&b[j]%i)
					k=0;
			if(k){
				printf("%d",i);
				exit(0);
			}
		}
		i++;
	}
	if(x!=1){
		i=x;
		k=1;
		for(j=1;j<=n;j++)
			if(a[j]%i&&b[j]%i)
				k=0;
		if(k){
			printf("%d",i);
			exit(0);
		}
	}
}
int main(){
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		scanf("%d%d",a+i,b+i);
	d(a[1]);
	d(b[1]);
	printf("-1");
	//while(1);
}