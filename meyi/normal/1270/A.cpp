#include<bits/stdc++.h>
using namespace std;
#define ri register int
#define DEBUG(k...) fprintf(stderr,k)
typedef long long ll;
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,true:false;}
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,true:false;}
const int maxn=2e5+10;
int a[maxn],b[maxn],m,n,t_case;
int main(){
	scanf("%d",&t_case);
	while(t_case--){
		scanf("%*d%d%d",&n,&m);
		for(ri i=1;i<=n;++i)scanf("%d",a+i);
		for(ri i=1;i<=m;++i)scanf("%d",b+i);
		puts(*max_element(a+1,a+n+1)>*max_element(b+1,b+m+1)?"YES":"NO");
	}
	return 0;
}