#include<cstdio>
#include<algorithm>
using namespace std;

int x[50001],y[50001],z[50001];
int a[50001],b[50001];
bool cmp(int u,int v){
	return x[u]!=x[v]?x[u]<x[v]:y[u]!=y[v]?y[u]<y[v]:z[u]<z[v];
}
int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d%d%d",&x[i],&y[i],&z[i]);
		a[i]=i;
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++){
		int j=i;
		while(j<n&&x[a[i]]==x[a[j+1]]&&y[a[i]]==y[a[j+1]])j++;
		for(int k=i;k+1<=j;k+=2){
			printf("%d %d\n",a[k],a[k+1]);
			b[a[k]]=b[a[k+1]]=1;
		}
		i=j;
	}
	for(int i=1;i<=n;i++)
		if(!b[a[i]])a[++a[0]]=a[i];
	for(int i=1;i<=a[0];i++){
		int j=i;
		while(j<a[0]&&x[a[i]]==x[a[j+1]])j++;
		for(int k=i;k+1<=j;k+=2){
			printf("%d %d\n",a[k],a[k+1]);
			b[a[k]]=b[a[k+1]]=1;
		}
		i=j;
	}
	int tot=0;
	for(int i=1;i<=a[0];i++)
		if(!b[a[i]])a[++tot]=a[i];
	for(int i=1;i<=tot;i+=2)
		printf("%d %d\n",a[i],a[i+1]);
}