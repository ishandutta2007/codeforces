#include<bits/stdc++.h>
using namespace std;
#define ri register int
#define DEBUG(k...) fprintf(stderr,k)
typedef long long ll;
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,true:false;}
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,true:false;}
template<class T>inline void clear(T *arr,int siz,int val=0){memset(arr,val,sizeof(T)*(siz+1));}
const int maxn=2e5+10;
inline int calc(int x,int y,int z){
	return max(max(y,z)+1-x,0);
}
int a,b,c,m,n,t_case;
int main(){
	scanf("%d",&t_case);
	while(t_case--){
		scanf("%d%d%d",&a,&b,&c);
		printf("%d %d %d\n",calc(a,b,c),calc(b,a,c),calc(c,b,a));
	}
	return 0;
}