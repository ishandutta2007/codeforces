#include<cstdio>
#include<algorithm>
using namespace std;
int n,x,y,xy,m=10;
int a[1024];
bool cx(int o,int f=-1){
	int ans=0,z;
	a[0]=0;
	for(int i=0;i<(1<<m);i++)
		if((i>>o&1)&&((f==-1)||!(i>>f&1)))
			if(i+1<=n)a[++a[0]]=i;
			else ans^=x;
	if(a[0]){
		printf("? %d",a[0]);
		for(int i=1;i<=a[0];i++)
			printf(" %d",a[i]+1);
		printf("\n");
		fflush(stdout);
		scanf("%d",&z);
		ans^=z;
	}
	return ans;
}
int main(){
	scanf("%d%d%d",&n,&x,&y);
	for(int i=m-1;i>=0;i--)
		xy|=cx(i)<<i;
	for(int i=m-1;i>=0;i--)
		if(xy>>i&1){
			int xx=0;
			for(int j=m-1;j>=0;j--)
				if(j!=i)xx|=cx(j,i)<<j;
			xy^=xx;
			if(xx>xy)swap(xx,xy);
			printf("! %d %d\n",xx+1,xy+1);
			fflush(stdout);
		}
}