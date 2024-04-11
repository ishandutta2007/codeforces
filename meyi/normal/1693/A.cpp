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
		ll sum=0;
		for(ri i=1;i<=n;++i)scanf("%d",a+i),sum+=a[i];
		if(sum){
			puts("No");
			continue;
		}
		int cnt=0;
		bool flag=false;
		ll tot=0;
		for(ri i=n;i;--i){
			if(a[i])flag=true;
			if((sum+=a[i])>=0&&flag)++cnt;
		}
		puts(cnt<2?"Yes":"No");
	}
	return 0;
}