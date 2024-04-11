#include<bits/stdc++.h>
using namespace std;
#define ri register int
typedef long long ll;
const int maxn=2e5+10;
int a,ans,cnt[maxn],m,n,s,t;
map<int,int>p;
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		p.clear();
		for(ri i=1;i<=n;++i)scanf("%d",&a),++p[a];
		ans=n;
		memset(cnt,0,sizeof cnt);
		s=m=0;
		for(map<int,int>::iterator i=p.begin();i!=p.end();++i)++cnt[i->second],m=max(m,i->second);
		for(ri i=1;i<=m;++i){
			if(!cnt[i])continue;
			ri tmp=0;
			for(ri j=i+1;j<=m;++j)tmp+=cnt[j]*(j-i);
			ans=min(ans,s+tmp);
			s+=cnt[i]*i;
		}
		printf("%d\n",ans);
	}
	return 0;
}