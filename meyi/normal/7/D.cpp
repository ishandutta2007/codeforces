#include<bits/stdc++.h>
using namespace std;
#define ri register int
typedef long long ll;
const int maxn=1e7+10;
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,1:0;}
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,1:0;}
int f[maxn],n,p[maxn];
char s[maxn];
ll ans;
inline bool pld(int k){
	return p[k+1]>k;
}
signed main(){
	scanf("%s",s+1);
	n=strlen(s+1);
	s[0]='?';
	for(ri i=n;~i;--i)s[i<<1]=s[i],s[i<<1|1]='#';
	n=(n<<1|1);
	for(ri i=1,mid=1,mx=1;i<=n;++i){
		if(i<mx)p[i]=min(mx-i,p[(mid<<1)-i]);
		else p[i]=1;
		while(s[i-p[i]]==s[i+p[i]])++p[i];
		if(i+p[i]>mx)mid=i,mx=i+p[i];
	}
	for(ri i=1;i<=n;++i)
		if(pld(i))
			f[i]=f[i>>1]+1,ans+=f[i];
	printf("%lld",ans);
	return 0;
}