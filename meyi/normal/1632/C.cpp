#include<bits/stdc++.h>
using namespace std;
#define ri register int
#define DEBUG(k...) fprintf(stderr,k)
typedef long long ll;
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,true:false;}
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,true:false;}
template<class T>inline void clear(T *arr,int siz,int val=0){memset(arr,val,sizeof(T)*(siz+1));}
const int maxn=2e5+10;
int a,b,m,n,t_case;
int main(){
	scanf("%d",&t_case);
	while(t_case--){
		scanf("%d%d",&a,&b);
		ri aa=a,bb=b,c=1,d=1;
		while((aa|b)!=b)++aa,++c;
		while((a|bb)!=bb)++bb,++d;
		printf("%d\n",min({1+(a|b)-a,b-a,c,d}));
	}
	return 0;
}