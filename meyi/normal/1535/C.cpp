#include<bits/stdc++.h>
using namespace std;
#define ri register int
#define DEBUG(k...) fprintf(stderr,k)
typedef long long ll;
template<class T>inline bool chmax(T &x,const T &y){return x<y?x=y,true:false;}
template<class T>inline bool chmin(T &x,const T &y){return x>y?x=y,true:false;}
const int maxn=2e5+10;
int l[maxn],m,n,r[maxn],t_case;
char s[maxn];
ll ans;
inline int findl(int k){
	if(s[k]=='?')return k;
	return k==l[k]?k:l[k]=findl(l[k]);
}
int main(){
	scanf("%d",&t_case);
	while(t_case--){
		scanf("%s",s+1);
		n=strlen(s+1);
		for(ri i=1;i<=n;++i)l[i]=i;
		for(ri i=1,lst1=1,lst2=0;i<=n;++i)
			if(s[i]=='?')
				l[i]=lst1;
			else{
				if((!lst2&&s[i-1]!='0'&&s[i-1]!='1')||s[i]==(s[lst2]^((i-lst2)&1)))l[i]=lst1;
				else l[i]=lst2+1,lst1=i;
				lst2=i;
			}
		ans=0;
		for(ri i=1;i<=n;++i)ans+=i-findl(l[i])+1;
		printf("%lld\n",ans);
	}
	return 0;
}