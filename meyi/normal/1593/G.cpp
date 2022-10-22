#include<bits/stdc++.h>
using namespace std;
#define ri register int
#define DEBUG(k...) fprintf(stderr,k)
typedef long long ll;
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,true:false;}
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,true:false;}
template<class T>inline void clear(T *arr,int siz,int val=0){memset(arr,val,sizeof(T)*(siz+1));}
const int maxn=1e6+10;
int m,n,q,sum[maxn][2][2],t_case;
char s[maxn];
int main(){
	scanf("%d",&t_case);
	while(t_case--){
		scanf("%s",s+1);
		n=strlen(s+1);
		for(ri i=1;i<=n;++i){
			sum[i][0][0]=sum[i-1][0][0],sum[i][0][1]=sum[i-1][0][1];
			sum[i][1][0]=sum[i-1][1][0],sum[i][1][1]=sum[i-1][1][1];
			if(s[i]=='('||s[i]==')')++sum[i][i&1][0];
			else ++sum[i][i&1][1];
		}
		scanf("%d",&q);
		while(q--){
			ri l,r;
			scanf("%d%d",&l,&r);
			ri mx=max(sum[r][0][1]-sum[l-1][0][1],sum[r][1][1]-sum[l-1][1][1]),mn=min(sum[r][0][1]-sum[l-1][0][1],sum[r][1][1]-sum[l-1][1][1]);
			printf("%d\n",mx-mn);
		}
	}
	return 0;
}