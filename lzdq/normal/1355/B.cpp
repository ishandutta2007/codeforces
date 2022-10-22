#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=2e5+5;
int n,a[MAXN];
int ans,x,y;
int main(){
	int _; scanf("%d",&_);
	while(_--){
		scanf("%d",&n);
		ans=x=y=0;
        for(int i=1;i<=n;++i)
			scanf("%d",a+i);
        sort(a+1,a+n+1);
        for(int i=1;i<=n;i++) {
			x++;
			y=max(a[i],y);
			if(y<=x)
				x=0,y=0,ans++;
		}
		printf("%d\n",ans);
	}
	return 0;
}