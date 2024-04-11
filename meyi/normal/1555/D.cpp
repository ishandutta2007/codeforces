#include<bits/stdc++.h>
using namespace std;
#define ri register int
#define DEBUG(k...) fprintf(stderr,k)
typedef long long ll;
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,true:false;}
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,true:false;}
const int maxn=2e5+10;
int cnt[6][maxn],m,n;
char s[maxn],t[6][maxn];
signed main(){
	scanf("%d%d%s",&n,&m,s+1);
	t[0][1]='a',t[0][2]='b',t[0][0]='c';
	t[1][1]='a',t[1][2]='c',t[1][0]='b';
	t[2][1]='b',t[2][2]='a',t[2][0]='c';
	t[3][1]='b',t[3][2]='c',t[3][0]='a';
	t[4][1]='c',t[4][2]='a',t[4][0]='b';
	t[5][1]='c',t[5][2]='b',t[5][0]='a';
	for(ri i=1;i<=n;++i){
		for(ri j=0;j<6;++j)
			if(s[i]!=t[j][i%3])
				cnt[j][i]=1;
	}
	for(ri j=0;j<6;++j)
		for(ri i=1;i<=n;++i)
			cnt[j][i]+=cnt[j][i-1];
	while(m--){
		ri ans=INT_MAX,l,r;
		scanf("%d%d",&l,&r);
		for(ri i=0;i<6;++i)ckmin(ans,cnt[i][r]-cnt[i][l-1]);
		printf("%d\n",ans);
	}
	return 0;
}