#include<bits/stdc++.h>
using namespace std;
#define ri register int
#define DEBUG(k...) fprintf(stderr,k)
typedef long long ll;
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,true:false;}
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,true:false;}
const int maxn=3e5+10;
ll ans;
int l[maxn],m,n,t_case;
char s[maxn];
int main(){
	scanf("%s",s+1);
	n=strlen(s+1);
	for(ri i=1;i<=n;++i){
		l[i]=l[i-1];
		for(ri j=i-2;j>l[i];j-=2)
			if(s[i]==s[j]&&s[i]==s[(i+j)>>1]){
				l[i]=j;
				break;
			}
		ans+=l[i];
	}
	printf("%lld",ans);
	return 0;
}