#include<bits/stdc++.h>
using namespace std;
#define ri register int
#define DEBUG(k...) fprintf(stderr,k)
typedef long long ll;
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,true:false;}
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,true:false;}
template<class T>inline void clear(T *arr,int siz,int val=0){memset(arr,val,sizeof(T)*(siz+1));}
const int maxn=2e5+10;
int a[maxn],ans[maxn],b[maxn],c[maxn],d[maxn],m,n,t_case;
vector<int>pos[maxn];
int main(){
	scanf("%d",&t_case);
	while(t_case--){
		scanf("%d%d",&n,&m);
		for(ri i=1;i<=n;++i)scanf("%d",a+i),d[i]=0,pos[i]={};
		for(ri i=1;i<=n;++i){
			scanf("%d",b+i);
			if(a[i]!=b[i])pos[b[i]].push_back(i);
			else d[b[i]]=i;
		}
		for(ri i=1;i<=m;++i)scanf("%d",c+i);
		ri used=0;
		for(ri i=m;i;--i){
			if(pos[c[i]].empty()){
				if(used)ans[i]=used;
				else if(d[c[i]])ans[i]=used=d[c[i]];
				else{puts("NO");goto skip;}
			}
			else{
				ans[i]=used=pos[c[i]].back();
				pos[c[i]].pop_back();
			}
		}
		for(ri i=1;i<=n;++i)
			for(ri j:pos[i])
				if(a[j]!=i){
					puts("NO");
					goto skip;
				}
		puts("YES");
		for(ri i=1;i<=m;++i)printf("%d ",ans[i]);
		printf("\n");
		skip:;
	}
	return 0;
}