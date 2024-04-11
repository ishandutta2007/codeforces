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
char s[maxn];
int main(){
	scanf("%d",&t_case);
	while(t_case--){
		scanf("%s",s+1);
		n=strlen(s+1);
		for(ri i=1;i<=n;++i)a[i]=s[i]^48;
		ri ans=n;
		for(ri i=n;i>1;--i)
			for(ri j=i-1;j;--j)
				if((a[j]*10+a[i])%25==0)
					ckmin(ans,n-j);
		printf("%d\n",ans-1);
		for(ri i=1;i<=n;++i)s[i]=0;
	}
	return 0;
}