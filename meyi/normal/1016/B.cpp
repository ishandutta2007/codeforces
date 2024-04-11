#include<bits/stdc++.h>
using namespace std;
#define ri int
typedef long long ll;
const int maxn=1e3+10;
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,1:0;}
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,1:0;}
template<class T>inline void clear(T *arr,int siz,int val=0){memset(arr,val,sizeof(T)*(siz+1));}
using B=bitset<maxn>;
B ans,b[26];
int m,n,pre[maxn],q;
char s[maxn],t[maxn];
signed main(){
	scanf("%d%d%d%s%s",&n,&m,&q,s+1,t+1);
	for(ri i=1;i<=n;++i)b[s[i]-'a'].set(i);
	ans.set();
	for(ri i=1;i<=m;++i)ans&=b[t[i]-'a']>>i-1;
	for(ri i=1;i<=n;++i)pre[i]=pre[i-1]+ans[i];
	while(q--){
		ri l,r;
		scanf("%d%d",&l,&r);
		if(r-l+1<m)puts("0");
		else printf("%d\n",pre[r-m+1]-pre[l-1]);
	}
	return 0;
}