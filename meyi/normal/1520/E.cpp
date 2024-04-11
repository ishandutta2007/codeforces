#include<bits/stdc++.h>
using namespace std;
#define ri register int
#define DEBUG(k...) fprintf(stderr,k)
typedef long long ll;
template<class T>inline bool chmax(T &x,const T &y){return x<y?x=y,true:false;}
template<class T>inline bool chmin(T &x,const T &y){return x>y?x=y,true:false;}
const int maxn=1e6+10;
int m,n,t_case;
char s[maxn];
ll ans,pre[maxn],suf[maxn];
vector<int>pos;
inline ll sum(ll l,ll r){
	return (l+r)*(r-l+1)/2;
}
int main(){
	scanf("%d",&t_case);
	while(t_case--){
		scanf("%d%s",&n,s+1);
		pos.clear();
		pos.push_back(0);
		for(ri i=1;i<=n;++i)
			if(s[i]=='*')
				pos.push_back(i);
		n=pos.size()-1;
		if(!n){puts("0");continue;}
		for(ri i=1;i<=n;++i)pre[i]=pre[i-1]+pos[i];
		suf[n+1]=0;
		for(ri i=n;i;--i)suf[i]=suf[i+1]+pos[i];
		ans=LLONG_MAX;
		for(ri i=1;i<=n;++i)ans=min(ans,sum(pos[i]-(i-1),pos[i]-1)-pre[i-1]+suf[i+1]-sum(pos[i]+1,pos[i]+n-i));
		printf("%lld\n",ans);
	}
	return 0;
}