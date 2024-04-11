#include<bits/stdc++.h>
using namespace std;
#define ri register int
typedef long long ll;
const int maxn=2e6+10;
struct node{
	int p,t;
	inline bool operator<(const node &k)const{
		return t-p!=k.t-k.p?t-p<k.t-k.p:p+t!=k.p+k.t?p+t<k.p+k.t:t<k.t;
	}
}a[maxn];
int m,n,t_case;
multiset<int>s[2];
char t[maxn];
int main(){
	scanf("%d",&t_case);
	while(t_case--){
		s[0].clear(),s[1].clear();
		scanf("%d%d",&n,&m);
		ri cnt=0;
		for(ri i=1;i<=n;++i){
			scanf("%s",t+1);
			for(ri j=1;j<=m;++j)
				if(t[j]^48)
					a[++cnt]={j,i};
		}
		sort(a+1,a+cnt+1);
		for(ri i=1;i<=cnt;++i){
			ri j=(a[i].p+a[i].t)&1;
			multiset<int>::iterator it=s[j].lower_bound(-(a[i].p+a[i].t));
			if(it!=s[j].end())s[j].erase(it);
			s[j].insert(-(a[i].p+a[i].t));
		}
		printf("%d\n",(int)s[0].size()+(int)s[1].size());
	}
	return 0;
}