#include<bits/stdc++.h>
using namespace std;
#define ri register int
#define DEBUG(k...) fprintf(stderr,k)
typedef long long ll;
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,true:false;}
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,true:false;}
template<class T>inline void clear(T *arr,int siz,int val=0){memset(arr,val,sizeof(T)*(siz+1));}
const int maxn=2e5+10;
int a[maxn],m,n,t_case,x[maxn],y[maxn],z[maxn];
int main(){
	scanf("%d",&t_case);
	while(t_case--){
		scanf("%d",&n);
		ri ans=INT_MAX,mn=1,mx=1;
		for(ri i=1;i<=n;++i){
			scanf("%d%d%d",x+i,y+i,z+i);
			typedef pair<int,int> pii;
			#define fi first
			#define se second
			if(x[i]<x[mn]||y[i]>y[mx])ans=INT_MAX;
			if(pii{x[i],z[i]}<pii{x[mn],z[mn]})mn=i;
			if(pii{y[i],-z[i]}>pii{y[mx],-z[mx]})mx=i;
			ckmin(ans,z[mn]+z[mx]);
			if(x[i]==x[mn]&&y[i]==y[mx])ckmin(ans,z[i]);
			printf("%d\n",ans);
		}
	}
	return 0;
}