#include<bits/stdc++.h>
using namespace std;
#define ri register int
#define DEBUG(k...) fprintf(stderr,k)
typedef long long ll;
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,true:false;}
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,true:false;}
const int maxn=2e5+10;
int a[maxn],m,n,t_case;
int main(){
	scanf("%d",&t_case);
	while(t_case--){
		scanf("%d%d",&n,&m);
		if(n>m)swap(n,m);
		ri ans=0,d=(m-n)>>1;
		if(n<d||m<d*3){printf("%d\n",min(n,m/3));continue;}
		n-=d,m-=d*3,ans+=d;
		ri dd=min(n,m)>>1;
		ans+=dd;
		n-=dd*2,m-=dd*2;
		while(n&&m>=3)++ans,--n,m-=3;
		while(m&&n>=3)++ans,--m,n-=3;
		printf("%d\n",ans);
	}
	return 0;
}