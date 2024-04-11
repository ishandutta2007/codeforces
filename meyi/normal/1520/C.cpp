#include<bits/stdc++.h>
using namespace std;
#define ri register int
#define DEBUG(k...) fprintf(stderr,k)
typedef long long ll;
template<class T>inline bool chmax(T &x,const T &y){return x<y?x=y,true:false;}
template<class T>inline bool chmin(T &x,const T &y){return x>y?x=y,true:false;}
const int maxn=110;
int a[maxn][maxn],m,n,t_case;
int main(){
	scanf("%d",&t_case);
	while(t_case--){
		scanf("%d",&n);
		if(n==1){puts("1");continue;}
		if(n==2){puts("-1");continue;}
		ri cnt=1;
		memset(a,0,sizeof a);
		for(ri i=1;i<=n;++i,printf("\n"))
			for(ri j=1;j<=n;++j){
				printf("%d ",cnt);
				cnt+=2;
				if(cnt>n*n)cnt=2;
			}
	}
	return 0;
}