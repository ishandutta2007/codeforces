#include<bits/stdc++.h>
using namespace std;
#define ri register int
typedef long long ll;
const int maxn=1e5+10;
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,1:0;}
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,1:0;}
typedef pair<int,int> pii;
#define fi first
#define se second
int n,t_case;
signed main(){
	scanf("%d",&t_case);
	while(t_case--){
		scanf("%d",&n);
		vector<pii>ans;
		for(ri now=n;now>2;){
			ri nxt=ceil(sqrt(now));
			for(ri i=nxt+1;i<now;++i)ans.emplace_back(i,now);
			ans.emplace_back(now,nxt);
			ans.emplace_back(now,nxt);
			now=nxt;
		}
		printf("%u\n",ans.size());
		for(auto i:ans)printf("%d %d\n",i.fi,i.se);
	}
	return 0;
}