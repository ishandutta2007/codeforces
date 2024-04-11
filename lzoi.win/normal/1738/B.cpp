#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
typedef long long ll;
const int MAXN=1e5+5;
int n,k,s[MAXN],a[MAXN];
bool ans;
int main(){
	int _; scanf("%d",&_);
	while(_--){
		ans=1;
		scanf("%d%d",&n,&k);
		for(int i=n-k+1; i<=n; i++)
			scanf("%d",s+i);
		for(int i=n-k+2; i<=n; i++)
			a[i]=s[i]-s[i-1];
		for(int i=1; i<=n-k+1; i++)
			a[i]=floor((double)(s[n-k+1]+i-1)/(n-k+1));
		for(int i=2; i<=n; i++)
			if(a[i-1]>a[i]) ans=0;
		if(ans) puts("Yes");
		else puts("No");
	}
	return 0;
}