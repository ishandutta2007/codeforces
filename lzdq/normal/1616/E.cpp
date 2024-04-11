#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
using namespace std;
typedef long long ll;
const int MAXN=1e5+5;
const ll INF=1ll<<60;
int n;
char s[MAXN],t[MAXN];
queue<int> que[26];
ll ans;
int rsum[MAXN];
inline int query(int x){
	int res=0;
	for(int i=x; i; i-=i&-i)
		res+=rsum[i];
	return res;
}
inline void Add(int x,int y){
	for(int i=x; i<=n; i+=i&-i)
		rsum[i]+=y;
}
int main(){
	int _; scanf("%d",&_);
	while(_--){
		scanf("%d",&n);
		scanf("%s%s",s+1,t+1);
		ans=INF;
		for(int i=0; i<26; i++)
			while(!que[i].empty()) que[i].pop();
		for(int i=1; i<=n; i++){
			s[i]-='a';
			t[i]-='a';
			que[s[i]].push(i);
			rsum[i]=0;
		}
		for(int i=1; i<=n; i++)
			Add(i,1);
		ll cnt=0;
		for(int i=1; i<=n; i++){
			int w=n+1;
			for(int j=0; j<t[i]; j++)
				if(!que[j].empty()) w=min(w,que[j].front());
			if(w<=n) ans=min(ans,cnt+query(w)-1);
			if(que[t[i]].empty()) break;
			w=que[t[i]].front();
			que[t[i]].pop();
			cnt+=query(w)-1;
			Add(w,-1);
		}
		if(ans==INF) ans=-1;
		printf("%lld\n",ans);
	}
	return 0;
}