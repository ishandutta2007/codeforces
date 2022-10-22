#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXN=1e5+5;
int n,a[MAXN];
int ans=-1;
int main(){
	scanf("%d",&n);
	for(int i=1; i<=n; i++)
		scanf("%d",a+i);
	for(int i=30;i>=0;i--){
		int cnt=0;
		for(int j=1; j<=n; j++)
			if(a[j]&(1<<i)) cnt++;
		if(cnt!=1) continue;
		for(int j=1; j<=n; j++)
			if(a[j]&(1<<i)) ans=j;
		break;
	}
	if(~ans){
		printf("%d ",a[ans]);
		for(int i=1; i<=n; i++)
			if(i!=ans) printf("%d ",a[i]);
	}else for(int i=1;i<=n;i++) printf("%d ",a[i]);
	puts("");
	return 0;
}