#include<bits/stdc++.h>
using namespace std;
#define ri int
#define DEBUG(k...) fprintf(stderr,k)
typedef long long ll;
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,true:false;}
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,true:false;}
template<class T>inline void clear(T *arr,int siz,int val=0){memset(arr,val,sizeof(T)*(siz+1));}
const int maxn=2e5+10;
int a[maxn],m,n,t_case;
int main(){
	scanf("%d",&t_case);
	while(t_case--){
		scanf("%d",&n);
		ri ans=1919810,l=1,r=114514;
		while(l<=r){
			ri mid=l+r>>1,x=mid/3,y=(mid-x)/2,z=mid-x-y;
			if(2ll*x*y+2ll*x*z+2ll*y*z>=n)ans=mid,r=mid-1;
			else l=mid+1;
		}
		printf("%d\n",ans);
	}
	return 0;
}