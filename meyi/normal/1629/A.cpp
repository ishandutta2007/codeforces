#include<bits/stdc++.h>
using namespace std;
#define ri register int
#define DEBUG(k...) fprintf(stderr,k)
typedef long long ll;
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,true:false;}
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,true:false;}
template<class T>inline void clear(T *arr,int siz,int val=0){memset(arr,val,sizeof(T)*(siz+1));}
const int maxn=2e5+10;
int a[maxn],b[maxn],id[maxn],m,n,t_case;
int main(){
	scanf("%d",&t_case);
	while(t_case--){
		scanf("%d%d",&n,&m);
		for(ri i=1;i<=n;++i)scanf("%d",a+i);
		for(ri i=1;i<=n;++i)scanf("%d",b+i),id[i]=i;
		sort(id+1,id+n+1,[&](int x,int y){return a[x]<a[y];});
		for(ri ii=1;ii<=n;++ii){
			ri i=id[ii];
			if(m>=a[i])m+=b[i];
			else break;
		}
		printf("%d\n",m);
	}
	return 0;
}