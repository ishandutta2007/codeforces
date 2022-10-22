#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
typedef long long ll;
const int MAXN=2e5+5;
int n;
ll k,a[MAXN],ans;
ll gcd(ll a,ll b){
	if(!b) return a;
	return gcd(b,a%b);
}
int main(){
	int _; scanf("%d",&_);
	while(_--){
		scanf("%d%lld",&n,&k);
		for(int i=1; i<=n; i++){
			scanf("%lld",a+i);
			if(i>1){
				if(i==2) ans=abs(a[i]-a[i-1]);
				else ans=gcd(ans,abs(a[i]-a[i-1]));
			}
		}
		if(!ans&&k==a[1]) puts("YES");
		else if(ans&&abs(k-a[1])%ans==0) puts("YES");
		else puts("NO");
	}
	return 0;
}