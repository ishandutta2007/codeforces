#include<bits/stdc++.h>
using namespace std;
#define ri register int
typedef long long ll;
const int maxn=2e5+10;
template<class T>inline void ckmax(T &x,const T &y){if(x<y)x=y;}
template<class T>inline void ckmin(T &x,const T &y){if(x>y)x=y;}
int a[maxn],m,n,t_case;
bool dfs(int l,int r,int t){
	if(l>=r)return true;
	bool ret=false;
	if(a[l]==a[r]){
		ret|=dfs(l+1,r-1,t);
		return ret;
	}
	if(t==-1||a[l]==t){
		ret|=dfs(l+1,r,a[l]);
		if(ret)return true;
	}
	if(t==-1||a[r]==t){
		ret|=dfs(l,r-1,a[r]);
		if(ret)return true;
	}
	return false;
}
int main(){
	scanf("%d",&t_case);
	while(t_case--){
		scanf("%d",&n);
		for(ri i=1;i<=n;++i)scanf("%d",a+i);
		puts(dfs(1,n,-1)?"YES":"NO");
	}
	return 0;
}