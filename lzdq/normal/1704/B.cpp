#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long ll;
const int MAXN=2e5+5,INF=0x3fffffff;
int n,x,a[MAXN];
int ans;
int main(){
	int _; scanf("%d",&_);
	while(_--){
		scanf("%d%d",&n,&x);
		for(int i=1; i<=n; i++)
			scanf("%d",a+i);
		ans=0;
		int mi=INF,mx=0;
		for(int i=1; i<=n; i++){
			mi=min(mi,a[i]);
			mx=max(mx,a[i]);
			if(mx-mi>x*2) ans++,mi=mx=a[i];
		}
		printf("%d\n",ans);
	}
	return 0;
}