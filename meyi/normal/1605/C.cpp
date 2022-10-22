#include<bits/stdc++.h>
using namespace std;
#define ri register int
#define DEBUG(k...) fprintf(stderr,k)
typedef long long ll;
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,true:false;}
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,true:false;}
template<class T>inline void clear(T *arr,int siz,int val=0){memset(arr,val,sizeof(T)*(siz+1));}
const int maxn=1e6+10;
int m,n,sum[maxn][3],t_case;
char s[maxn];
inline bool check(int k){
	for(ri i=k;i<=n;++i)
		if(sum[i][0]-sum[i-k][0]>max(sum[i][1]-sum[i-k][1],sum[i][2]-sum[i-k][2]))
			return true;
	return false;
}
signed main(){
	scanf("%d",&t_case);
	while(t_case--){
		scanf("%d%s",&n,s+1);
		for(ri i=1;i<=n;++i){
			for(ri j=0;j<3;++j)sum[i][j]=sum[i-1][j];
			++sum[i][s[i]-'a'];
		}
		for(auto i:{2,3,4,7})
			if(check(i)){
				printf("%d\n",i);
				goto skip;
			}
		puts("-1");
		skip:;
	}
	return 0;
}
/*
aa
aba aca
abca acba


abbacca accabba
*/