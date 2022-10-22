#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN=2e5+5;
int n,a[MAXN],b[MAXN],ans;
int main(){
	int _; scanf("%d",&_);
	while(_--){
		scanf("%d",&n);
		int w=1;
		ans=1;
		for(int i=1; i<=n; i++){
			scanf("%d",a+i);
			b[i]=a[i]-a[i-1];
		}
		ll sum=0;
		for(int i=2; i<=n; i++)
			if(b[i]<0) sum-=b[i];
		if(sum<=b[1]) puts("YES");
		else puts("NO");
	}
	return 0;
}