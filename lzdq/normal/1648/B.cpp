#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long ll;
const int MAXN=1e6+5;
int n,c;
int a[MAXN],cnt[MAXN],sum[MAXN];
bool ans;
int main(){
	int _; scanf("%d",&_);
	while(_--){
		scanf("%d%d",&n,&c);
		for(int i=1; i<=n; i++)
			scanf("%d",a+i);
		sort(a+1,a+n+1);
		n=unique(a+1,a+n+1)-a-1;
		if(a[1]!=1){
			puts("No");
			continue;
		}
		for(int i=1; i<=c; i++)
			cnt[i]=0;
		for(int i=1; i<=n; i++)
			cnt[a[i]]=1;
		for(int i=1; i<=c; i++)
			sum[i]=sum[i-1]+cnt[i];
		ans=1;
		for(int i=2; i<=c; i++){
			if(!cnt[i]) continue;
			for(int j=i; j<=c; j+=i){
				// [j,j+i-1]
				if(sum[min(j+i-1,c)]>sum[j-1]&&!cnt[j/i]) ans=0;
			}
			if(!ans) break;
		}
		if(ans) puts("Yes");
		else puts("No");
	}
	return 0;
}