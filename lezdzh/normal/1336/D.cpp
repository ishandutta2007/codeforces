#include<cstdio>

using namespace std;

int a,b,da,db;
int z[101],ans[101];
void cx(int p){
	printf("+ %d\n",p);
	fflush(stdout);
	scanf("%d%d",&da,&db);
	da-=a;
	db-=b;
	a+=da;
	b+=db;
}
int main(){
	int n;
	scanf("%d%d%d",&n,&a,&b);
	for(int i=n-1;i>=3;i--){
		cx(i);
		z[i]=db;
	}
	cx(1);
	z[1]=db;
	cx(2);
	z[2]=db;
	cx(1);
	ans[1]=1;
	while(ans[1]*(ans[1]-1)/2<da)ans[1]++;
	ans[1]--;
	ans[3]=db-z[1]-1;
	ans[2]=z[1]/(ans[3]+1);
	ans[4]=(z[2]-(ans[1]+1)*(ans[3]+1))/(ans[3]+1)-1;
	for(int i=3;i<=n-2;i++)
		ans[i+2]=(z[i]-ans[i-1]*ans[i-2]-ans[i-1]*(ans[i+1]+1))/(ans[i+1]+1)-1;
	ans[n]+=1;
	printf("! ");
	for(int i=1;i<=n;i++)
		printf("%d%c",ans[i],i==n?'\n':' ');
}