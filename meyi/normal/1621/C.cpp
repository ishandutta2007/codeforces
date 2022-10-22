#include<bits/stdc++.h>
using namespace std;
#define ri register int
#define DEBUG(k...) fprintf(stderr,k)
typedef long long ll;
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,true:false;}
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,true:false;}
template<class T>inline void clear(T *arr,int siz,int val=0){memset(arr,val,sizeof(T)*(siz+1));}
const int maxn=2e5+10;
inline int ask(int k){
	printf("? %d\n",k);
	fflush(stdout);
	ri ret;
	scanf("%d",&ret);
	return ret;
}
int ans[maxn],m,n,t_case;
int main(){
	scanf("%d",&t_case);
	while(t_case--){
		scanf("%d",&n);
		clear(ans,n);
		for(ri i=1;i<=n;++i)
			if(!ans[i]){
				vector<int>v={ask(i)};
				while(1){
					ri j=ask(i);
					v.push_back(j);
					if(j==v.front())break;
				}
				for(ri j=0;j+1<v.size();++j)ans[v[j]]=v[j+1];
			}
		printf("!");
		for(ri i=1;i<=n;++i)printf(" %d",ans[i]);
		printf("\n");
		fflush(stdout);
	}
	return 0;
}