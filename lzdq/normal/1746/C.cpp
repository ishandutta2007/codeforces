#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long ll;
const int MAXN=2e5+5;
int n,a[MAXN],b[MAXN];
int main(){
	int _; scanf("%d",&_);
	while(_--){
		scanf("%d",&n);
		for(int i=1; i<=n; i++)
			scanf("%d",a+i),b[a[i]]=i;
		for(int i=1; i<=n; i++)
			printf("%d ",min(n,b[i]+1));
		puts("");
	}
	return 0;
}