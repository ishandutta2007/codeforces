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
		for(int i=1; i<=n; i++)
			scanf("%d",a+i);
		if(n==1) ans=0;
		else{
			ans=a[n]-a[1];
			for(int i=1; i<n; i++)
				ans=max(ans,a[i]-a[i+1]);
			for(int i=1; i<n; i++)
				ans=max(ans,a[n]-a[i]);
			for(int i=2; i<=n; i++)
				ans=max(ans,a[i]-a[1]);
		}
		printf("%d\n",ans);
	}
	return 0;
}