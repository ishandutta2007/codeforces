#include<bits/stdc++.h>
using namespace std;
#define ri register int
typedef long long ll;
const int maxn=1e5+10;
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,1:0;}
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,1:0;}
template<class T>inline void clear(T *arr,int siz,int val=0){memset(arr,val,sizeof(T)*(siz+1));}
int a[maxn],m,n,pos[256],t_case;
char s[maxn],t[maxn];
int main(){
	scanf("%d",&t_case);
	while(t_case--){
		scanf("%s%s",s+1,t+1);
		n=strlen(t+1);
		for(ri i=1;i<=26;++i)pos[s[i]]=i;
		ll ans=0;
		for(ri i=2;i<=n;++i)ans+=abs(pos[t[i]]-pos[t[i-1]]);
		printf("%lld\n",ans);
		clear(t,n);
	}
	return 0;
}