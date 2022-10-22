#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long ll;
const int MAXN=2e5+5;
int n,a[MAXN],ans;
int main(){
	int _; scanf("%d",&_);
	while(_--){
		scanf("%d",&n);
		for(int i=1; i<=n; i++)
			scanf("%d",a+i);
		int x=0,y=0;
		for(int i=1; i<n; i++)
			if(a[i]==a[i+1]){
				x=i+1;
				break;
			}
		for(int i=n; i>1; i--)
			if(a[i]==a[i-1]){
				y=i-1;
				break;
			}
		if(x&&x<=y) ans=max(1,y-x);
		else ans=0;
		printf("%d\n",ans);
	}
	return 0;
}