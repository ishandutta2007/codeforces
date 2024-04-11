#include<bits/stdc++.h>
using namespace std;
#define ri int
typedef long long ll;
const int maxn=2e5+10;
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,1:0;}
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,1:0;}
template<class T>inline void clear(T *arr,int siz,int val=0){memset(arr,val,sizeof(T)*(siz+1));}
int cnt[maxn][2],m,n;
char s[maxn];
int main(){
	scanf("%d%d%s",&n,&m,s+1);
	for(ri i=1;i<=n;++i){
		if(s[i]==s[i-1])++cnt[i-1][s[i]^48];
		cnt[i][0]=cnt[i-1][0],cnt[i][1]=cnt[i-1][1];
	}
	while(m--){
		ri l,r;
		scanf("%d%d",&l,&r);
		--l,--r;
		printf("%d\n",max(cnt[r][0]-cnt[l][0],cnt[r][1]-cnt[l][1])+1);
	}
	return 0;
}