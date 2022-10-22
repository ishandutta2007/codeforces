#include<bits/stdc++.h>
using namespace std;
#define ri register int
#define DEBUG(k...) fprintf(stderr,k)
typedef long long ll;
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,true:false;}
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,true:false;}
const int maxn=1e5+10;
struct node{
	int val[5],id;
	inline bool operator<(const node &k)const{
		ri cnt=0;
		for(ri i=0;i<5;++i)cnt+=(val[i]<k.val[i]);
		return cnt>2;
	}
}a[maxn];
int cnt[maxn],m,n,t_case;
int main(){
	scanf("%d",&t_case);
	while(t_case--){
		scanf("%d",&n);
		for(ri i=1;i<=n;++i)
			for(ri j=0;j<5;++j)
				scanf("%d",&a[i].val[j]),a[i].id=i;
		sort(a+1,a+n+1);
		ri ans=a[1].id;
		for(ri i=2;i<=n;++i)
			if(!(a[1]<a[i])){
				ans=-1;
				break;
			}
		printf("%d\n",ans);
	}
	return 0;
}