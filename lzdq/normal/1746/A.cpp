#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long ll;
const int MAXN=2e5+5;
int n,k;
int a[MAXN];
bool ans;
int main(){
	int _; scanf("%d",&_);
	while(_--){
		scanf("%d%d",&n,&k);
		for(int i=1; i<=n; i++)
			scanf("%d",a+i);
		ans=0;
		for(int i=1; i<=n; i++)
			if(a[i]) ans=1;
		if(ans) puts("YES");
		else puts("NO");
	}
	return 0;
}