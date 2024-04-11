#include<bits/stdc++.h>
using namespace std;
#define ri register int
#define DEBUG(k...) fprintf(stderr,k)
typedef long long ll;
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,true:false;}
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,true:false;}
template<class T>inline void clear(T *arr,int siz,int val=0){memset(arr,val,sizeof(T)*(siz+1));}
const int maxn=5e5+10;
int a[maxn],m,n,t_case;
int main(){
	scanf("%d",&t_case);
	while(t_case--){
		scanf("%d%d",&m,&n);
		for(ri i=1;i<=n;++i)scanf("%d",a+i);
		sort(a+1,a+n+1,greater<int>());
		ri ans=0,pos=0;
		for(ri i=1;i<=n;++i){
			if(pos>=a[i])break;
			++ans,pos+=m-a[i];
		}
		printf("%d\n",ans);
	}
	return 0;
}