#include<bits/stdc++.h>
using namespace std;
#define ri register int
#define DEBUG(k...) fprintf(stderr,k)
typedef long long ll;
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,true:false;}
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,true:false;}
template<class T>inline void clear(T *arr,int siz,int val=0){memset(arr,val,sizeof(T)*(siz+1));}
const int maxn=51;
int a[maxn],n,t_case;
int main(){
	scanf("%d",&t_case);
	while(t_case--){
		scanf("%d",&n);
		bool flag=true;
		for(ri i=1;i<=n;++i){
			scanf("%d",a+i);
			flag&=(a[i]==a[1]);
		}
		if(flag)puts("-1");
		else{
			ri g=0;
			sort(a+1,a+n+1);
			for(ri i=2;i<=n;++i)g=__gcd(a[i]-a[1],g);
			printf("%d\n",g);
		}
	}
	return 0;
}