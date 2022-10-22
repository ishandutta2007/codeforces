#include<bits/stdc++.h>
using namespace std;
#define ri register int
#define DEBUG(k...) fprintf(stderr,k)
typedef long long ll;
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,true:false;}
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,true:false;}
const int maxn=510;
map<int,int>cnt;
int k,m,n,t_case;
int main(){
	scanf("%d%d",&n,&k);
	for(ri i=1;i<=k+1;++i){
		printf("?");
		for(ri j=1;j<=k+1;++j)
			if(i!=j)
				printf(" %d",j);
		printf("\n");
		fflush(stdout);
		ri val;
		scanf("%*d%d",&val);
		++cnt[val];
	}
	printf("! %d",(--cnt.end())->second);
	fflush(stdout);
	return 0;
}