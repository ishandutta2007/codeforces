#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long ll;
const int MAXN=1e4+5;
int n,k;
int a[MAXN],x[MAXN],y[MAXN];
//int b[MAXN]={0,1,6,4,2,3,5,4};
bool vis[40];
int main(){
	scanf("%d%d",&n,&k);
	for(int i=2; i<=n; i++){
		printf("or %d %d\n",1,i);
		fflush(stdout);
		scanf("%d",x+i);
		//x[i]=b[1]|b[i];
		printf("and %d %d\n",1,i);
		fflush(stdout);
		scanf("%d",y+i);
		//y[i]=b[1]&b[i];
		for(int j=0; j<31; j++)
			if((1<<j&x[i])==(1<<j&y[i])) vis[j]=1,a[1]|=(1<<j&x[i]);
	}
	int p,q;
	puts("or 2 3");
	fflush(stdout);
	scanf("%d",&p);
	puts("and 2 3");
	fflush(stdout);
	scanf("%d",&q);
	for(int j=0; j<31; j++)
		if(!vis[j]&&(1<<j&p)==(1<<j&q)) vis[j]=1,a[1]|=(1<<j&~p);
	for(int i=2; i<=n; i++)
		a[i]=a[1]^x[i]^y[i];
	sort(a+1,a+n+1);
	printf("finish %d\n",a[k]);
	return 0;
}