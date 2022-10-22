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
		scanf("%d%d",&n,&m);
		if((n+1)/2<m)puts("-1");
		else{
			for(ri i=1;i<=n;++i,putchar(10))
				for(ri j=1;j<=n;++j)
					if((i&1)&&i==j&&(i+1)/2<=m)putchar('R');
					else putchar('.');
		}
	}
	return 0;
}