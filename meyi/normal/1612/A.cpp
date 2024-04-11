#include<bits/stdc++.h>
using namespace std;
#define ri register int
typedef long long ll;
const int maxn=2e5+10;
template<class T>inline void ckmax(T &x,const T &y){if(x<y)x=y;}
template<class T>inline void ckmin(T &x,const T &y){if(x>y)x=y;}
int t_case,x,y;
int main(){
	scanf("%d",&t_case);
	while(t_case--){
		scanf("%d%d",&x,&y);
		if((x+y)&1)puts("-1 -1");
		else{
			ri dx=min(x,((x+y)>>1)),dy=((x+y)>>1)-dx;
			printf("%d %d\n",x-dx,y-dy);
		}
	}
	return 0;
}