#include<bits/stdc++.h>
using namespace std;
#define ri register int
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
		for(ri i=1;i<=n;++i)scanf("%d",a+i);
		ri cnt=0;
		for(ri i=2;i<n;++i)
			if(a[i]>a[i-1]&&a[i]>a[i+1]){
				++cnt;
				if(i+1==n)a[i]=max(a[i-1],a[i+1]);
				else a[i+1]=max(a[i],a[i+2]);
			}
		printf("%d\n",cnt);
		for(ri i=1;i<=n;++i)printf("%d ",a[i]);
		printf("\n");
	}
	return 0;
}