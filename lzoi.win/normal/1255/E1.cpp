#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN=1e5+5;
int n;
int a[MAXN];
int tot,b[MAXN];
ll ans=1ll<<60;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",a+i);
		if(a[i]) b[++tot]=i;
	}
	if(tot==1) return puts("-1"),0;
	for(int k=2;k<=tot;k++){
		if(tot%k) continue;
		ll res=0;
		for(int i=1;i<=tot;i++){
			int t=(i-1)/k;
			res+=abs(b[i]-b[t*k+(k+1>>1)]);
		}
		ans=min(ans,res);
	}
	printf("%I64d\n",ans);
	return 0;
}