#include<bits/stdc++.h>
using namespace std;
#define ri register int
#define DEBUG(k...) fprintf(stderr,k)
typedef long long ll;
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,true:false;}
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,true:false;}
template<class T>inline void clear(T *arr,int siz,int val=0){memset(arr,val,sizeof(T)*(siz+1));}
const int maxn=2e5+10;
int k,l,r,t_case;
inline int calc(int x){return (x+1)>>1;}
int main(){
	scanf("%d",&t_case);
	while(t_case--){
		scanf("%d%d%d",&l,&r,&k);
		puts(((l==r&&l>1)||k>=calc(r)-calc(l-1))?"YES":"NO");
	}
	return 0;
}