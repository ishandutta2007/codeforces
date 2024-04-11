#include<bits/stdc++.h>
using namespace std;
#define ri register int
#define DEBUG(k...) fprintf(stderr,k)
typedef long long ll;
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,true:false;}
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,true:false;}
const int maxn=2e5+10;
int m,n,x,y,t_case;
inline bool check1(int k){
	ri l1=k+(k>=x),l2=k+(k>=y);
	return min(l1,l2)+n>x+y;
}
inline int half1(){
	ri l=1,r=n,ret=n;
	while(l<=r){
		ri mid=l+r>>1;
		if(check1(mid))ret=mid,r=mid-1;
		else l=mid+1;
	}
	return ret;
}
inline bool check2(int k){
	ri r1=k-(k<=x),r2=k-(k<=y);
	return max(r1,r2)+1<=x+y;
}
inline int half2(){
	ri l=1,r=n,ret=1;
	while(l<=r){
		ri mid=l+r>>1;
		if(check2(mid))ret=mid,l=mid+1;
		else r=mid-1;
	}
	return ret;
}
int main(){
	scanf("%d",&t_case);
	while(t_case--){
		scanf("%d%d%d",&n,&x,&y);
		printf("%d %d\n",half1(),half2());
	}
	return 0;
}