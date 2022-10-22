#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long ll;
const int m=20000;
int n,f[m+5],g[m+5],a[105];
bool cm[m+5];
int ans;
int main(){
	for(int i=2; i<=m; i++)
		for(int j=i<<1; j<=m; j+=i)
			cm[j]=1;
	int _; scanf("%d",&_);
	while(_--){
		scanf("%d",&n);
		int sum=0;
		for(int i=1; i<=n; i++){
			scanf("%d",a+i);
			sum+=a[i];
		}
		if(cm[sum]){
			printf("%d\n",n);
			for(int i=1; i<=n; i++)
				printf("%d ",i);
		}else{
			int mi=0;
			for(int i=1; i<=n; i++)
				if(cm[sum-a[i]]&&(!mi||a[i]>a[mi]))
					mi=i;
			printf("%d\n",n-1);
			for(int i=1; i<=n; i++)
				if(i!=mi) printf("%d ",i);
		}
		puts("");
	}
	return 0;
}