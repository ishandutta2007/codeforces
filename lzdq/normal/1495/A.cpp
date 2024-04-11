#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN=1e5+5;
int n,m,a[MAXN],b[MAXN];
int ans;
int main(){
	//freopen("in1.txt","r",stdin);
	int _; scanf("%d",&_);
	while(_--){
		scanf("%d",&n);
		*a=*b=0;
		for(int i=0; i<n<<1; i++){
			int x,y;
			scanf("%d%d",&x,&y);
			x=abs(x);
			y=abs(y);
			if(!x) b[++*b]=y;
			else a[++*a]=x;
		}
		sort(a+1,a+n+1);
		sort(b+1,b+n+1);
		//reverse(b+1,b+n+1);
		double ans=0;
		for(int i=1; i<=n; i++)
			ans+=sqrt((1ll*a[i]*a[i]+1ll*b[i]*b[i]));
		printf("%.15f\n",ans);
	}
	return 0;
}