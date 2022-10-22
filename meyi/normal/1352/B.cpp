#include<bits/stdc++.h>
using namespace std;
#define ri register int
#define DEBUG(k...) fprintf(stderr,k)
typedef long long ll;
template<class T>inline bool chmax(T &x,const T &y){return x<y?x=y,true:false;}
template<class T>inline bool chmin(T &x,const T &y){return x>y?x=y,true:false;}
const int maxn=2e5+10;
int a[maxn],b,m,n,t_case;
inline bool calc(int k){
	if(n<=(m-1)*k||((n-(m-1)*k)&1)!=(k&1))return false;
	puts("YES");
	for(ri i=1;i<m;++i)printf("%d ",k);
	printf("%d\n",n-(m-1)*k);
	return true;
}
int main(){
	scanf("%d",&t_case);
	while(t_case--){
		scanf("%d%d",&n,&m);
		if(calc(1)||calc(2));
		else puts("NO");
	}
	return 0;
}