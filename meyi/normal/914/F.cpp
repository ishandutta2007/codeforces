#include<bits/stdc++.h>
using namespace std;
#define ri int
typedef long long ll;
const int maxn=1e5+10;
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,1:0;}
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,1:0;}
template<class T>inline void clear(T *arr,int siz,int val=0){memset(arr,val,sizeof(T)*(siz+1));}
using B=bitset<maxn>;
B ans,b[26];
int n,q;
char s[maxn],t[maxn];
signed main(){
	scanf("%s%d",s+1,&q);
	n=strlen(s+1);
	for(ri i=1;i<=n;++i)b[s[i]-'a'].set(i);
	while(q--){
		ri op;
		scanf("%d",&op);
		if(op&1){
			ri k;
			scanf("%d%s",&k,t+1);
			b[s[k]-'a'].reset(k);
			s[k]=t[1];
			b[s[k]-'a'].set(k);
		}
		else{
			ri l,r;
			scanf("%d%d%s",&l,&r,t+1);
			ri m=strlen(t+1);
			if(r-l+1<m){puts("0");continue;}
			ans.set();
			for(ri i=1;i<=m;++i)ans&=b[t[i]-'a']>>i-1;
			printf("%d\n",(ans>>l).count()-(ans>>r-m+2).count());
		}
	}
	return 0;
}