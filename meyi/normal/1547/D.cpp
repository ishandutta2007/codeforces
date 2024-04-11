#include<bits/stdc++.h>
using namespace std;
#define ri register int
#define DEBUG(k...) fprintf(stderr,k)
typedef long long ll;
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,true:false;}
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,true:false;}
const int maxn=2e5+10;
int a[maxn],b[maxn],m,n,t_case;
int main(){
	scanf("%d",&t_case);
	while(t_case--){
		scanf("%d",&n);
		for(ri i=1;i<=n;++i)scanf("%d",a+i);
		for(ri i=2;i<=n;++i){
			b[i]=0;
			for(ri j=0;j<30;++j)
				if((a[i-1]&(1<<j))&&!(a[i]&(1<<j)))
					b[i]|=(1<<j);
			a[i]^=b[i];
		}
		for(ri i=1;i<=n;++i)printf("%d ",b[i]);
		printf("\n");
	}
	return 0;
}