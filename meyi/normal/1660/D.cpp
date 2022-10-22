#include<bits/stdc++.h>
using namespace std;
#define ri int
#define DEBUG(k...) fprintf(stderr,k)
typedef long long ll;
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,true:false;}
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,true:false;}
template<class T>inline void clear(T *arr,int siz,int val=0){memset(arr,val,sizeof(T)*(siz+1));}
const int maxn=2e5+10;
int a[maxn],cnt[maxn],m,mn[2],n,t_case;
signed main(){
	scanf("%d",&t_case);
	while(t_case--){
		scanf("%d",&n);
		for(ri i=1;i<=n;++i)scanf("%d",a+i);
		a[n+1]=0;
		ri l=n,lst=0,mx=0,r=0;
		for(ri nw=1;nw<=n+1;++nw)
			if(!a[nw]){
				cnt[lst]=0;
				bool neg=0;
				mn[0]=lst,mn[1]=-1;
				for(ri i=lst+1;i<nw;++i){
					cnt[i]=cnt[i-1]+(abs(a[i])==2);
					if(a[i]<0)neg^=1;
					if(mn[neg]!=-1&&(cnt[i]-cnt[mn[neg]]>mx||(cnt[i]-cnt[mn[neg]]==mx&&mn[neg]+n-i<l+r))){
						mx=cnt[i]-cnt[mn[neg]],l=mn[neg],r=n-i;
					}
					if(mn[neg]==-1||cnt[i]<cnt[mn[neg]])mn[neg]=i;
				}
				lst=nw;
			}
		printf("%d %d\n",l,r);
	}
	return 0;
}