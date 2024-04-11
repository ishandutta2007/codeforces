#include<cstdio>
#include<algorithm>
#include<cstring>
typedef long long ll;
using namespace std;
const int MAXN=2e5+5;
int n,a[MAXN],b[MAXN];
int main(){
	int _; scanf("%d",&_);
	while(_--){
		scanf("%d",&n);
		for(int i=1; i<=n; i++)
			scanf("%d",a+i);
		for(int i=1; i<=n; i++)
			scanf("%d",b+i);
		sort(a+1,a+n+1);
		sort(b+1,b+n+1);
		bool ans=1;
		for(int i=1; i<=n; i++)
			if(a[i]>b[i]||a[i]+1<b[i]) ans=0;
		if(ans) puts("YES");
		else puts("NO");
	}
	return 0;
}