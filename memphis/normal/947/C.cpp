#include<cstdio>
#include<algorithm>
#include<cstring>
#define M 10000010
using namespace std;
const int N=600005;

int n,i,a[N],cur,np;
int son[2][M],sum[M],x,y,j;

int main(){
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		scanf("%d",&a[i]);
	np=1;
	for(i=1;i<=n;i++){
		scanf("%d",&x);
		for(cur=1,j=29;j>=0;j--){
			if(!son[(x>>j)&1][cur])
				son[(x>>j)&1][cur]=++np;
			cur=son[(x>>j)&1][cur];
			sum[cur]++;
		}
	}
	for(i=1;i<=n;i++){
		y=0;
		for(cur=1,j=29;j>=0;j--){
			if(sum[son[(a[i]>>j)&1][cur]])
				cur=son[(a[i]>>j)&1][cur];
			else cur=son[!((a[i]>>j)&1)][cur],y|=1<<j/*,printf("%d %d\n",a[i],j)*/;
			sum[cur]--;
		}
		printf("%d ",y);
	}
}