#include<stdio.h>
#include<set>
using namespace std;
const int maxn=200005;
int n,t;
int g[maxn],c[maxn],d[maxn];
long long all,ans=1e18;
set< pair<int,long long> >s;
int main(){
	scanf("%d%d",&n,&t);
	for(int i=1;i<=n;i++)
		scanf("%d%d",&g[i],&c[i]);
	for(int i=1;i<n;i++)
		scanf("%d",&d[i]),all+=d[i],c[i+1]=(c[i+1]+all%t)%t;
	s.insert(make_pair(0,0ll));
	for(int i=1;i<=n;i++)
		s.insert(make_pair((t-c[i])%t,0ll)),s.insert(make_pair((g[i]-1-c[i]+t)%t,0ll));
	for(int i=1;i<=n;i++){
		long long now=1e18;
		set< pair<int,long long>>::iterator it=s.lower_bound(make_pair((g[i]-c[i]+t)%t,0ll));
		while(it!=s.end()){
			if((c[i]+it->first)%t<g[i])
				break;
			now=min(now,it->second+(t-c[i]-it->first+t)%t),it=s.erase(it);
		}
		it=s.begin();
		while(it!=s.end()){
			if((c[i]+it->first)%t<g[i])
				break;
			now=min(now,it->second+(t-c[i]-it->first+t)%t),it=s.erase(it);
		}
		it=s.lower_bound(make_pair((t-c[i])%t,0ll));
		if(it!=s.end()&&it->first==(t-c[i])%t)
			now=min(now,it->second),s.erase(it);
		s.insert(make_pair((t-c[i])%t,now));
	}
	for(set< pair<int,long long> >::iterator it=s.begin();it!=s.end();it++)
		ans=min(ans,it->second);
	printf("%lld\n",ans+all);
	return 0;
}