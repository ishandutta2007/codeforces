#include<bits/stdc++.h>
using namespace std;
#define ri register int
#define DEBUG(k...) fprintf(stderr,k)
typedef long long ll;
template<class T>inline bool chmax(T &x,const T &y){return x<y?x=y,true:false;}
template<class T>inline bool chmin(T &x,const T &y){return x>y?x=y,true:false;}
const int maxn=2e5+10;
int a[maxn],m,n,t_case;
inline void print(int st){
	for(ri i=st;i<=n;i+=2)printf("%d ",i);
	printf("%d %d %d ",n-3,n-1,n-5);
	for(ri i=n-7;i>0;i-=2)printf("%d ",i);
	printf("\n");
}
int main(){
	scanf("%d",&t_case);
	while(t_case--){
		scanf("%d",&n);
		if(n<4){
			puts("-1");
			continue;
		}
		if(n==4){
			puts("2 4 1 3");
			continue;
		}
		if(n==5){
			puts("1 3 5 2 4");
			continue;
		}
		print(1+(n&1^1));
	}
	return 0;
}