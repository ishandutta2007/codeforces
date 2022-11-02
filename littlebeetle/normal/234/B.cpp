#include<cstdio>
#include<algorithm>
using namespace std;
const int N=100002;
int n,k,i,a[N],d[N],f[N];
bool cmp(int x,int y){
	return a[x]!=a[y]?a[x]>a[y]:x<y;
}
int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);	
	scanf("%d%d",&n,&k);
	for(i=1;i<=n;i++)
		scanf("%d",a+i),d[i]=i;
	sort(d+1,d+n+1,cmp);
	for(i=1;i<=k;i++)
		f[d[i]]=1;
	printf("%d\n",a[d[k]]);
	for(i=1;i<=n;i++)
		if(f[i])
			printf("%d ",i);
}