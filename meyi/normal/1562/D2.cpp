#include<bits/stdc++.h>
using namespace std;
#define ri register int
typedef long long ll;
const int maxn=3e5+10;
template<class T>inline void ckmax(T &x,const T &y){if(x<y)x=y;}
template<class T>inline void ckmin(T &x,const T &y){if(x>y)x=y;}
int a[maxn],m,n,pre[maxn],t_case;
vector<int>pos[maxn<<2];
char s[maxn];
signed main(){
	scanf("%d",&t_case);
	while(t_case--){
		scanf("%d%d%s",&n,&m,s+1);
		for(ri i=1;i<=(n<<2);++i)pos[i].clear();
		for(ri i=1;i<=n;++i){
			a[i]=(s[i]=='+'?1:-1);
			pre[i]=pre[i-1]+((i&1)?a[i]:-a[i]);
			pos[pre[i]+pre[i-1]+(n<<1)].push_back(i);
		}
		while(m--){
			ri l,r;
			scanf("%d%d",&l,&r);
			if(pre[r]==pre[l-1])puts("0");
			else{
				vector<int>ans;
				if((r-l)&1)ans.push_back(l),++l;
				ri sum=pre[r]+pre[l-1]+(n<<1);
				ans.push_back(*lower_bound(pos[sum].begin(),pos[sum].end(),l));
				printf("%u\n",ans.size());
				for(auto i:ans)printf("%d ",i);
				printf("\n");
			}
		}
	}
	return 0;
}