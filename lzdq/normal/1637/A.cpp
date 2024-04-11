#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long ll;
const int MAXN=2e5+5;
int n,a[MAXN];
int main(){
	int _; scanf("%d",&_);
	while(_--){
		scanf("%d",&n);
		bool ans=1;
		for(int i=1; i<=n; i++){
			scanf("%d",a+i);
			if(i>1&&a[i]<a[i-1]) ans=0;
		}
		if(ans) puts("NO");
		else puts("YES");
	}
	return 0;
}