#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long ll;
const int MAXN=1.5e5+5;
int n,a[MAXN],lst[MAXN],ans;
int main(){
	int _; scanf("%d",&_);
	while(_--){
		scanf("%d",&n);
		ans=-1;
		for(int i=1; i<=n; i++){
			scanf("%d",a+i);
			if(lst[a[i]]) ans=max(ans,lst[a[i]]+n-i);
			lst[a[i]]=i;
		}
		for(int i=1; i<=n; i++)
			lst[a[i]]=0;
		printf("%d\n",ans);
	}
	return 0;
}