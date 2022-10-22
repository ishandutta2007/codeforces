#include<bits/stdc++.h>
using namespace std;
#define ri register int
#define DEBUG(k...) fprintf(stderr,k)
typedef long long ll;
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,true:false;}
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,true:false;}
template<class T>inline void clear(T *arr,int siz,int val=0){memset(arr,val,sizeof(T)*(siz+1));}
const int maxn=2e5+10;
int a[maxn],k,n,t_case;
bool vis[maxn];
int main(){
	scanf("%d",&t_case);
	while(t_case--){
		scanf("%d%d",&n,&k);
		clear(vis,n);
		auto print=[&](int x,int y){printf("%d %d\n",x,y),vis[x]=vis[y]=true;};
		if(!k){
			for(ri i=0;i<n;++i)
				if(!vis[i])
					print(i,(n-1)^i);
			continue;
		}
		if(k+1==n){
			if(n<=4){
				puts("-1");
			}
			else{
				print(n-1,n-2);
				print(1,3);
				print(n-4,0);
				for(ri i=0;i<n;++i)
					if(!vis[i])
						print(i,(n-1)^i);
			}
			continue;
		}
		print(k,n-1);
		print((n-1)^k,0);
		for(ri i=0;i<n;++i)
			if(!vis[i])
				print(i,(n-1)^i);
	}
	return 0;
}