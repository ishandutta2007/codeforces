#include<bits/stdc++.h>
using namespace std;
#define ri register int
typedef long long ll;
const int maxn=2e5+10;
#define pb push_back
#define pp pop_back
#define eb emplace_back
#define SZ(k) k.size()
#define ALL(k) k.begin(),k.end()
#define RALL(k) k.rend(),k.rbegin()
#define lowbit(k) ((k)&(-k))
template<typename T>
struct BIT{
	T c[maxn];
	int mx_idx;
	inline void clear(){memset(c,0,sizeof(T)*(mx_idx+1));}
	inline void add(int k,T v){
		for(;k<=mx_idx;k+=lowbit(k))c[k]+=v;
	}
	inline T query(int k){
		ri ret=0;
		for(;k;k^=lowbit(k))ret+=c[k];
		return ret;
	}
	inline T query(int l,int r){
		return query(r)-query(l-1);
	}
};
BIT<int>c;
int n;
vector<int>pos[26];
char s[maxn];
ll ans;
int main(){
	scanf("%d%s",&n,s+1);
	for(ri i=n;i;--i)s[i]-='a',pos[s[i]].eb(i);
	reverse(s+1,s+n+1);
	c.mx_idx=n;
	for(ri i=1;i<=n;++i){
		ri tmp=pos[s[i]].back();
		pos[s[i]].pp();
		ans+=c.query(tmp+1,n);
		c.add(tmp,1);
	}
	printf("%lld",ans);
	return 0;
}