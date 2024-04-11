#include<bits/stdc++.h>
using namespace std;
#define ri register int
#define DEBUG(k...) fprintf(stderr,k)
typedef long long ll;
template<class T>inline bool chmax(T &x,const T &y){return x<y?x=y,true:false;}
template<class T>inline bool chmin(T &x,const T &y){return x>y?x=y,true:false;}
const int maxn=2e5+10;
int a[maxn],n;
ll f[maxn];
int main(){
	scanf("%d",&n);
	for(ri i=1;i<=n;++i)scanf("%d",a+i);
	memset(f,-0x3f,sizeof f);
	f[0]=0;
	ri cnt=0;
	for(ri i=1;i<=n;++i){
		if(a[i]>=0){
			for(ri j=0;j<=cnt;++j)
				if(f[j]>=0)
					f[j]+=a[i];
		}
		else{
			++cnt;
			for(ri j=cnt;j;--j)
				if(f[j-1]+a[i]>=0)
					f[j]=max(f[j],f[j-1]+a[i]);
		}
	}
	for(ri i=cnt;~i;--i)
		if(f[i]>=0){
			printf("%d",n-cnt+i);
			break;
		}
	return 0;
}