#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long ll;
const int MAXN=2e5+5;
int n,a[MAXN],c0,c1;
int main(){
	int _; scanf("%d",&_);
	while(_--){
		scanf("%d",&n);
		c0=c1=0;
		for(int i=1; i<=n; i++){
			scanf("%d",a+i);
			if(a[i]==0) c0=1;
			if(a[i]==1) c1=1;
		}
		if(c0&&c1){
			puts("NO");
			continue;
		}
		sort(a+1,a+n+1);
		bool ans=1;
		if(c1){
			for(int i=n; a[i]>1; i--)
				if(a[i]-a[i-1]==1) ans=0;
		}
		if(ans) puts("YES");
		else puts("NO");
	}
	return 0;
}