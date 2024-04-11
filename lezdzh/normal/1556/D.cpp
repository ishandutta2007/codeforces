#include<cstdio>
#include<algorithm>
using namespace std;

int a[10001],b[10001],c[10001];
int main(){
	int n,k;
	scanf("%d%d",&n,&k);
	for(int i=2;i<=n;i++){
		printf("and %d %d\n",1,i);
		fflush(stdout);
		scanf("%d",&a[i]);
		printf("or %d %d\n",1,i);
		fflush(stdout);
		scanf("%d",&b[i]);
	}
	printf("and %d %d\n",2,3);
	fflush(stdout);
	scanf("%d",&a[1]);
	printf("or %d %d\n",2,3);
	fflush(stdout);
	scanf("%d",&b[1]);
	for(int i=30;i>=0;i--){
		int ok=1;
		for(int j=2;j<=n;j++)
			if((a[j]>>i&1)){
				c[1]+=1<<i;
				goto ed;
			}
		for(int j=2;j<=n;j++)
			if(!(b[j]>>i&1)){
				goto ed;
			}
		if(!(a[1]>>i&1))
			c[1]+=1<<i;
		ed:;
	}
	for(int i=2;i<=n;i++)
		c[i]=c[1]^(b[i]-a[i]);
	sort(c+1,c+n+1);
	printf("finish %d\n",c[k]);
}