#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long ll;
const int MAXN=205;
int n,k,a[MAXN],x[MAXN],y[MAXN],b[MAXN];
int main(){
	int _; scanf("%d",&_);
	while(_--){
		scanf("%d%d",&n,&k);
		for(int i=1; i<=n*2; i++)
			a[i]=0;
		for(int i=1; i<=k; i++)
			scanf("%d%d",x+i,y+i),a[x[i]]=a[y[i]]=1;
		*b=0;
		for(int i=1; i<=n*2; i++)
			if(!a[i]) b[++*b]=i;
		int c=k;
		for(int i=1; i<=n-k; i++)
			x[++c]=b[i],y[c]=b[i+n-k];//,printf("add %d %d\n",x[c],c);
		for(int i=1; i<=n; i++)
			if(x[i]>y[i]) swap(x[i],y[i]);
		int ans=0;
		for(int i=1; i<=n; i++)
			for(int j=1; j<=n; j++)
				if(x[i]<x[j]&&x[j]<y[i]&&y[i]<y[j]) ans++;
		printf("%d\n",ans);
	}
	return 0;
}