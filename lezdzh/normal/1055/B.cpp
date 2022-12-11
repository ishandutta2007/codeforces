#include<cstdio>

using namespace std;

long long a[100002];
int main(){
	int n,m,l;
	scanf("%d%d%d",&n,&m,&l);
	int ans=0;
	for(int i=1;i<=n;i++){
		scanf("%I64d",&a[i]);
		if(a[i]>l)
			ans+=a[i-1]<=l;
	}
	for(int i=1;i<=m;i++){
		int o;
		scanf("%d",&o);
		if(!o)printf("%d\n",ans);
		else{
			int p,d;
			scanf("%d%d",&p,&d);
			if(a[p]<=l&&a[p]+d>l)
				ans+=1-(a[p-1]>l)-(a[p+1]>l);
			a[p]+=d;
		}
	}
}