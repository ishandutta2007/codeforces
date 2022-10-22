#include<cstdio>
#include<algorithm>
#include<map>
using namespace std;
typedef long long ll;
const int MAXN=2e5+5;
int n;
ll a[MAXN];
map<ll,int> mp;
ll ans;
int main(){
	scanf("%d",&n);
	for(int i=1; i<=n; i++)
		scanf("%lld",a+i),a[i]+=a[i-1];
	int mx=0;
	mp[0]=1;
	for(int i=1; i<=n; i++){
		if(mp[a[i]]) mx=max(mx,mp[a[i]]);
		mp[a[i]]=i+1;
		ans+=i-mx;
	}
	printf("%lld\n",ans);
	return 0;
}