#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long ll;
const int MAXN=2e5+5;
int n,z,a[MAXN];
int ans;
int main(){
	int _; scanf("%d",&_);
	while(_--){
		scanf("%d%d",&n,&z);
		ans=0;
		for(int i=1; i<=n; i++){
			scanf("%d",a+i);
			ans=max(ans,a[i]|z);
		}
		printf("%d\n",ans);
	}
	return 0;
}