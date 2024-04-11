#include<bits/stdc++.h>
using namespace std;
#define ri register int
#define DEBUG(k...) fprintf(stderr,k)
typedef long long ll;
template<class T>inline bool chmax(T &x,const T &y){return x<y?x=y,true:false;}
template<class T>inline bool chmin(T &x,const T &y){return x>y?x=y,true:false;}
const int maxn=2e5+10;
int t_case,x,y,z;
int main(){
	scanf("%d",&t_case);
	while(t_case--){
		scanf("%d%d%d",&x,&y,&z);
		if(!y){
			if(x)for(ri i=1;i<=x+1;++i)putchar('0');
			if(z)for(ri i=1;i<=z+1;++i)putchar('1');
			printf("\n");
			continue;
		}
		for(ri i=1;i<=x;++i)putchar('0');
		printf("01");
		for(ri i=1;i<=z;++i)putchar('1');
		for(ri i=1;i<y;++i)putchar((i&1)?'0':'1');
		printf("\n");
	}
	return 0;
}