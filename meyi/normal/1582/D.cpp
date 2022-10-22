#include<bits/stdc++.h>
using namespace std;
#define ri register int
#define DEBUG(k...) fprintf(stderr,k)
typedef long long ll;
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,true:false;}
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,true:false;}
const int maxn=2e5+10;
int a[maxn],m,n,t_case;
int main(){
	scanf("%d",&t_case);
	while(t_case--){
		scanf("%d",&n);
		for(ri i=1;i<=n;++i)scanf("%d",a+i);
		bool flag=false;
		int x,y,z;
		if(n&1){
			flag=true;
			z=a[n],y=a[n-1],x=a[n-2];
			n-=3;
		}
		for(ri i=1;i<=n;i+=2)printf("%d %d ",a[i+1],-a[i]);
		if(flag){
			if(x==z)printf("%d %d %d\n",-y,x*2,-y);
			// -xy+y(x-z)+zy=y(x-z)+y(z-x)
			else printf("%d %d %d",-y,x-z,y);
		}
		printf("\n");
	}
	return 0;
}