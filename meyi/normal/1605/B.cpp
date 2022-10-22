#include<bits/stdc++.h>
using namespace std;
#define ri register int
#define DEBUG(k...) fprintf(stderr,k)
typedef long long ll;
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,true:false;}
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,true:false;}
template<class T>inline void clear(T *arr,int siz,int val=0){memset(arr,val,sizeof(T)*(siz+1));}
const int maxn=2e5+10;
int m,n,t_case;
char s[maxn];
signed main(){
	scanf("%d",&t_case);
	while(t_case--){
		scanf("%d%s",&n,s+1);
		ri cnt=0;
		for(ri i=1;i<=n;++i){
			s[i]^=48;
			if(!s[i])++cnt;
		}
		vector<int>ans;
		for(ri i=1;i<=n;++i)
			if(s[i]!=(i>cnt))
				ans.push_back(i);
		if(ans.empty())puts("0");
		else{
			printf("1\n%d",(int)ans.size());
			for(ri i:ans)printf(" %d",i);
			printf("\n");
		}
	}
	return 0;
}