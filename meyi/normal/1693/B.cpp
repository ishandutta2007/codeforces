#include<bits/stdc++.h>
using namespace std;
#define ri int
#define DEBUG(k...) fprintf(stderr,k)
typedef long long ll;
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,true:false;}
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,true:false;}
template<class T>inline void clear(T *arr,int siz,int val=0){memset(arr,val,sizeof(T)*(siz+1));}
const int maxn=2e5+10;
ll f[maxn];
int cnt,l[maxn],n,r[maxn],t_case;
vector<int>to[maxn];
void dfs(int p){
	f[p]=0;
	for(ri i:to[p])dfs(i),f[p]+=f[i];
	ckmin(f[p],(ll)r[p]);
	if(f[p]>=l[p])return;
	else ++cnt,f[p]=r[p];
}
int main(){
	scanf("%d",&t_case);
	while(t_case--){
		scanf("%d",&n);
		for(ri i=1;i<=n;++i)to[i].clear();
		for(ri i=2,f;i<=n;++i)scanf("%d",&f),to[f].push_back(i);
		for(ri i=1;i<=n;++i)scanf("%d%d",l+i,r+i);
		cnt=0;
		dfs(1);
		printf("%d\n",cnt);
	}
	return 0;
}