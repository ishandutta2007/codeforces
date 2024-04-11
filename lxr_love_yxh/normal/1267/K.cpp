#include<stdio.h>
#include<string>
#include<math.h>
#include<stdlib.h>
#include<set>
#include<bitset>
#include<map>
#include<vector>
#include<string.h>
#include<algorithm>
#include<iostream>
#include<queue>
#include<deque>
#include<stack>
#include<cmath>
#include<ctime>
#include<complex>
#include<list>
#include<limits.h>
#include<iomanip>
using namespace std;

int T,n;
long long x;
int cnt[21],tot;
long long ans,ans2;

void solve(){
	scanf("%I64d",&x);
	long long y=x;
	memset(cnt,0,sizeof(cnt));
	for(n=2;y!=0ll;n++){
		cnt[y%n]++;
		y/=1ll*n;
	}
	n--;;
	ans=1ll;ans2=1ll;
	tot=cnt[0]+cnt[1];
	for(int i=2;i<=n;i++){
		ans*=tot;
		tot+=cnt[i]-1;
	}
	for(int i=0;i<=n;i++) if(cnt[i]!=0) for(int j=1;j<=cnt[i];j++) ans/=1ll*j;
	ans--;
	if(cnt[0]){
		cnt[0]--;
		tot=cnt[0]+cnt[1];
//		for(int i=0;i<=n;i++) printf("%d ",cnt[i]); puts("");
		for(int i=2;i<=n-1;i++){
			ans2*=tot;
			tot+=cnt[i]-1;
//			printf("%lld %d\n",ans2,tot);
		}
//		printf("%I64d\n",ans2);
		for(int i=0;i<=n;i++) if(cnt[i]!=0) for(int j=1;j<=cnt[i];j++) ans2/=1ll*j;
		printf("%I64d\n",ans-ans2);
	}else printf("%I64d\n",ans);
}

int main(){
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}