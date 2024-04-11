#include<bits/stdc++.h>
using namespace std;
#define ri register int
#define DEBUG(k...) fprintf(stderr,k)
typedef long long ll;
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,true:false;}
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,true:false;}
const int maxn=2e5+10;
int a[maxn],m,n,t_case;
bool vis[maxn];
int main(){
	scanf("%d",&t_case);
	while(t_case--){
		scanf("%d",&n);
		for(ri i=1;i<=n;++i)scanf("%d",a+i),vis[i]=false;
		for(ri i=0;i<30;++i){
			ri cnt=0;
			for(ri j=1;j<=n;++j)
				if(a[j]&(1<<i))
					++cnt;
			for(ri j=1;j<=n;++j)
				if(cnt%j)
					vis[j]=true;
		}
		for(ri i=1;i<=n;++i)
			if(!vis[i])
				printf("%d ",i);
		printf("\n");
	}
	return 0;
}