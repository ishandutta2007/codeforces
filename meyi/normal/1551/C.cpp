#include<bits/stdc++.h>
using namespace std;
#define ri register int
#define DEBUG(k...) fprintf(stderr,k)
typedef long long ll;
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,true:false;}
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,true:false;}
const int maxn=2e5+10;
int cnt[maxn][5],n,tmp[maxn],t_case;
char s[maxn];
inline int calc(int k){
	for(ri i=1;i<=n;++i){
		tmp[i]=0;
		for(ri j=0;j<5;++j)
			if(j==k)tmp[i]+=cnt[i][j];
			else tmp[i]-=cnt[i][j];
	}
	sort(tmp+1,tmp+n+1,greater<int>());
	ri ret=0,sum=0;
	for(ri i=1;i<=n;++i){
		sum+=tmp[i];
		if(sum>0)ret=i;
	}
	return ret;
}
int main(){
	scanf("%d",&t_case);
	while(t_case--){
		scanf("%d",&n);
		for(ri i=1;i<=n;++i){
			scanf("%s",s+1);
			ri m=strlen(s+1);
			for(ri j=0;j<5;++j)cnt[i][j]=0;
			for(ri j=1;j<=m;++j)++cnt[i][s[j]-'a'],s[j]=0;
		}
		ri ans=0;
		for(ri i=0;i<5;++i)ckmax(ans,calc(i));
		printf("%d\n",ans);
	}
	return 0;
}