#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long ll;
const int MAXN=2e5+5;
int n,a[MAXN];
int ans;
int main(){
	int _; scanf("%d",&_);
	while(_--){
		scanf("%d",&n);
		ans=0;
		for(int i=1; i<=n; i++){
			scanf("%d",a+i);
			if(a[i]&&(i==1||a[i-1]==0)) ans++;
		}
		ans=min(ans,2);
		printf("%d\n",ans);
	}
	return 0;
}