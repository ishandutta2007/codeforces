#include<bits/stdc++.h>
using namespace std;
#define ri register int
#define DEBUG(k...) fprintf(stderr,k)
typedef long long ll;
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,true:false;}
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,true:false;}
template<class T>inline void clear(T *arr,int siz,int val=0){memset(arr,val,sizeof(T)*(siz+1));}
const int maxn=3e5+10;
int a[maxn],m,n,pos[maxn],t_case;
inline bool check(int k){
	for(ri i=1;i<=n;++i)pos[a[i]]=-1145141;
	for(ri i=1;i<=n;++i){
		if(pos[a[i]]>k-(n-i+1))return true;
		else pos[a[i]]=i;
	}
	return false;
}
int main(){
    scanf("%d",&t_case);
    while(t_case--){
        scanf("%d",&n);
        for(ri i=1;i<=n;++i)scanf("%d",a+i);
		ri ans=-1,l=1,r=n;
		while(l<=r){
			ri mid=l+r>>1;
			if(check(mid))ans=mid,l=mid+1;
			else r=mid-1;
		}
		printf("%d\n",ans);
    }
    return 0;
}