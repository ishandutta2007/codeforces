#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
typedef long long ll;
const int MAXN=100;
int n,a[MAXN],ans;
int main(){
	int _; scanf("%d",&_);
	while(_--){
		scanf("%d",&n);
		for(int i=1; i<=n; i++)
			scanf("%d",a+i);
		ans=n-1;
		for(int i=1; i<=n; i++)
			for(int j=i+1; j<=n; j++){
				int x=a[j]-a[i],y=j-i;
				int g=__gcd(abs(x),abs(y));
				x/=g,y/=g;
				int cnt=0;
				for(int k=1; k<=n; k++)
					if((k-i)%abs(y)||x*(k-i)/y+a[i]!=a[k]) cnt++;
				ans=min(ans,cnt);
			}
		printf("%d\n",ans);
	}
	return 0;
}