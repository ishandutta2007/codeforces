#include<bits/stdc++.h>
using namespace std;
#define ri register int
#define DEBUG(k...) fprintf(stderr,k)
typedef long long ll;
template<class T>inline bool chmax(T &x,const T &y){return x<y?x=y,true:false;}
template<class T>inline bool chmin(T &x,const T &y){return x>y?x=y,true:false;}
const int maxn=2e5+10;
int a[maxn],nxt[maxn],pre[maxn],m,n,t_case;
int main(){
	scanf("%d",&t_case);
	while(t_case--){
		scanf("%d",&n);
		for(ri i=1;i<=n;++i)scanf("%d",a+i),nxt[a[i]]=pre[a[i]]=0;
		for(ri i=1;i<=n;++i)nxt[a[i]]=i;
		for(ri i=n;i;--i)pre[a[i]]=i;
		bool flag=false;
		for(ri i=1;i<=n;++i)
			if(nxt[a[i]]&&pre[a[i]]&&nxt[a[i]]-pre[a[i]]>1)
				flag=true;
		puts(flag?"YES":"NO");
	}
	return 0;
}