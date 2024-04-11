#include<bits/stdc++.h>
using namespace std;
#define ri register int
#define DEBUG(k...) fprintf(stderr,k)
typedef long long ll;
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,true:false;}
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,true:false;}
const int maxn=2e5+10;
int a[maxn],ans,b[maxn],cnt,m,n,pos[maxn],t_case;
int main(){
	scanf("%d",&n);
	for(ri i=1;i<=n;++i)scanf("%d",a+i);
	for(ri i=1;i<=n;++i){
		scanf("%d",b+i);
		if(b[i])pos[b[i]]=i;
	}
	if(pos[1]){
		ri i=2;
		for(;pos[i]==pos[i-1]+1;++i);
		if(pos[i-1]==n){
			for(ri j=i;j<=n;++j)
				if(j-i<pos[j])
					goto skip;
			return printf("%d",n-i+1),0;
		}
	}
	skip:;
	for(ri i=1;i<=n;++i)
		if(b[i])
			ckmax(ans,i-b[i]+1);
	printf("%d",ans+n);
	return 0;
}