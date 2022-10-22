#include<bits/stdc++.h>
using namespace std;
#define ri register int
#define DEBUG(k...) fprintf(stderr,k)
typedef long long ll;
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,true:false;}
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,true:false;}
const int maxn=2e5+10;
int n,t_case;
char s[maxn];
int dfs(int l,int r,char ch){
	if(l==r)return s[l]!=ch;
	ri mid=l+r>>1,cnt1=dfs(l,mid,ch+1),cnt2=dfs(mid+1,r,ch+1);
	for(ri i=l;i<=mid;++i)cnt2+=(s[i]!=ch);
	for(ri i=mid+1;i<=r;++i)cnt1+=(s[i]!=ch);
	return min(cnt1,cnt2);
}
int main(){
	scanf("%d",&t_case);
	while(t_case--){
		scanf("%d%s",&n,s+1);
		printf("%d\n",dfs(1,n,'a'));
	}
	return 0;
}