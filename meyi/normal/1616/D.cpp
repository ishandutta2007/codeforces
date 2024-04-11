#include<bits/stdc++.h>
using namespace std;
#define ri register int
#define DEBUG(k...) fprintf(stderr,k)
typedef long long ll;
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,true:false;}
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,true:false;}
template<class T>inline void clear(T *arr,int siz,int val=0){memset(arr,val,sizeof(T)*(siz+1));}
const int maxn=2e5+10;
int a[maxn],m,n,t_case,x;
int main(){
	scanf("%d",&t_case);
	while(t_case--){
		scanf("%d",&n);
		for(ri i=1;i<=n;++i)scanf("%d",a+i);
		scanf("%d",&x);
		for(ri i=1;i<=n;++i)a[i]-=x;
		ri ans=0;
		for(ri i=1;i<=n;){
			ri nxt=i;
			while(nxt<n){
				if(a[nxt]+a[nxt+1]<0)break;
				if(nxt>i&&a[nxt-1]+a[nxt]+a[nxt+1]<0)break;
				++nxt;
			}
			ans+=nxt-i+1,i=nxt+2;
		} 
		printf("%d\n",ans);
	}
	return 0;
}