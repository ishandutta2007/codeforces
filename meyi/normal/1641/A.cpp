#include<bits/stdc++.h>
using namespace std;
#define ri register int
#define DEBUG(k...) fprintf(stderr,k)
typedef long long ll;
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,true:false;}
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,true:false;}
template<class T>inline void clear(T *arr,int siz,int val=0){memset(arr,val,sizeof(T)*(siz+1));}
const int maxn=2e5+10;
int m,n,t_case;
ll a[maxn],f[maxn];
int main(){
	scanf("%d",&t_case);
	while(t_case--){
		scanf("%d%d",&n,&m);
		for(ri i=1;i<=n;++i)scanf("%lld",a+i);
		sort(a+1,a+n+1,greater<ll>());
		multiset<ll>s;
		for(ri i=1;i<=n;++i){
			auto it=s.find(a[i]*m);
			if(it==s.end())s.insert(a[i]);
			else s.erase(it);
		}
		printf("%d\n",(int)s.size());
	}
	return 0;
}