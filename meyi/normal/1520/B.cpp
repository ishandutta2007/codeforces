#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
#define ri register int
#define DEBUG(k...) fprintf(stderr,k)
typedef long long ll;
template<class T>inline bool chmax(T &x,const T &y){return x<y?x=y,true:false;}
template<class T>inline bool chmin(T &x,const T &y){return x>y?x=y,true:false;}
const int maxn=2e5+10;
int a[maxn],m,n,t_case;
inline int qpow(int x,int y){
	ri ret=1;
	for(;y;x*=x,y>>=1)if(y&1)ret*=x;
	return ret;
}
int main(){
	scanf("%d",&t_case);
	while(t_case--){
		scanf("%d",&n);
		ri ans=0;
		for(ri i=0;i<=8;++i)
			for(ri j=1;j<=9;++j){
				ri tmp=0;
				for(ri k=0;k<=i;++k)tmp+=qpow(10,k)*j;
				if(tmp<=n)++ans;
			}
		printf("%d\n",ans);
	}
	return 0;
}