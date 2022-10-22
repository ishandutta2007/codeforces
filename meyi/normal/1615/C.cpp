#include<bits/stdc++.h>
using namespace std;
#define ri register int
#define DEBUG(k...) fprintf(stderr,k)
typedef long long ll;
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,true:false;}
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,true:false;}
const int maxn=2e5+10;
int a[maxn],m,n,t_case;
char s[maxn],t[maxn];
int main(){
	scanf("%d",&t_case);
	while(t_case--){
		scanf("%d%s%s",&n,s+1,t+1);
		ri a0=0,a1=0,cnt0=0,cnt1=0;
		for(ri i=1;i<=n;++i)
			if(s[i]!=t[i]){
				++cnt1;
				++(s[i]=='0'?a0:a1);
			}
		if(cnt1%2!=0||a0!=a1)cnt1=INT_MAX;
		a0=0,a1=0;
		for(ri i=1;i<=n;++i)
			if(s[i]==t[i]){
				++cnt0;
				++(s[i]=='0'?a0:a1);
			}
		if(cnt0%2==0||a1-a0!=1)cnt0=INT_MAX;
		ri ans=min(cnt1,cnt0);
		if(ans>n)puts("-1");
		else printf("%d\n",ans);
	}
	return 0;
}