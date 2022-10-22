#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN=4e5+5;
int n,m,a[MAXN],b[MAXN];
ll rsum[MAXN];
int main(){
//	freopen("A.in","r",stdin);
	int t;scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		m=0;
		for(int i=1;i<=n;i++){
			scanf("%d",a+m+1);
			if(m&&a[m+1]==a[m]) ++b[m];
			else b[++m]=1;
		}
//		printf("m %d\n",m);
//		for(int i=1;i<=m;i++)
//			printf("a b %d %d\n",a[i],b[i]);
		int w=0;
		for(int i=1;i<=m;i++)
			if((rsum[i]=rsum[i-1]+b[i])<=n>>1) w=i;
		bool ans=0;
		for(int i=2;i<w;i++)
			if(rsum[i]-rsum[1]>rsum[1]&&rsum[w]-rsum[i]>rsum[1]){
				ans=1;
				printf("%I64d %I64d %I64d\n",rsum[1],rsum[i]-rsum[1],rsum[w]-rsum[i]);
				break;
			}
		if(!ans) puts("0 0 0");
	}
	return 0;
}