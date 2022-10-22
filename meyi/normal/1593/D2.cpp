#include<bits/stdc++.h>
using namespace std;
#define ri register int
#define DEBUG(k...) fprintf(stderr,k)
typedef long long ll;
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,true:false;}
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,true:false;}
template<class T>inline void clear(T *arr,int siz,int val=0){memset(arr,val,sizeof(T)*(siz+1));}
const int maxn=51;
int a[maxn],ans,cur,n,t_case;
void dfs(int p,int cnt,int g){
	if(g>0&&g<=ans)return;
	if(cnt>=(n>>1)){
		ans=g;
		return;
	}
	for(ri i=p+1;i<=n;++i)dfs(i,cnt+1,__gcd(g,a[i]-a[cur]));
}
int main(){
	scanf("%d",&t_case);
	while(t_case--){
		scanf("%d",&n);
		for(ri i=1;i<=n;++i)scanf("%d",a+i);
		sort(a+1,a+n+1);
		for(ri i=1;i+(n>>1)-1<=n;++i){
			bool flag=true;
			for(ri j=i;j<i+(n>>1);++j)flag&=(a[i]==a[j]);
			if(flag){
				puts("-1");
				goto skip;
			}
		}
		ans=0;
		for(ri i=1;i+(n>>1)-1<=n;++i)cur=i,dfs(i,1,0);
		printf("%d\n",ans);
		skip:;
	}
	return 0;
}