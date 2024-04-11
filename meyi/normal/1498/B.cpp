#include<bits/stdc++.h>
using namespace std;
#define ri register int
typedef long long ll;
const int maxn=2e5+10;
int a,ans,cnt[110],m,n,t_case;
int main(){
	scanf("%d",&t_case);
	while(t_case--){
		scanf("%d%d",&n,&m);
		memset(cnt,0,sizeof cnt);
		for(ri i=1;i<=n;++i){
			scanf("%d",&a);
			++cnt[(int)log2(a)];
		}
		ans=0;
		for(ri i=20;~i;--i){
			ri tot=0;
			while(cnt[i]){
				for(ri j=i;~j;--j)
					while(cnt[j]>0&&tot+(1<<j)<=m)
						tot+=(1<<j),--cnt[j];
				++ans,tot=0;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}