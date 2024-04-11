#include<bits/stdc++.h>
using namespace std;
#define ri register int
#define DEBUG(k...) fprintf(stderr,k)
typedef long long ll;
template<class T>inline bool chmax(T &x,const T &y){return x<y?x=y,true:false;}
template<class T>inline bool chmin(T &x,const T &y){return x>y?x=y,true:false;}
const int maxn=2e5+10;
int a[maxn],p[maxn],m,n,t_case;
int main(){
	scanf("%d",&t_case);
	while(t_case--){
		scanf("%d",&n);
		for(ri i=1;i<=n;++i)scanf("%d",a+i),a[i]+=a[i-1],p[i]=0;
		for(ri i=1;i<n;++i)
			for(ri j=i+1;j<=n;++j)
				if(a[j]-a[i-1]<=n)
					p[a[j]-a[i-1]]=true;
		ri ans=0;
		for(ri i=1;i<=n;++i)ans+=p[a[i]-a[i-1]];
		printf("%d\n",ans);
	}
	return 0;
}