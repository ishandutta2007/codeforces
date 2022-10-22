#include<bits/stdc++.h>
using namespace std;
#define ri int
typedef long long ll;
const int maxn=1e5+10;
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,1:0;}
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,1:0;}
template<class T>inline void clear(T *arr,int siz,int val=0){memset(arr,val,sizeof(T)*(siz+1));}
char s[11];
inline bool ask(int x,int y){
	printf("%d %d\n",x,y);
	fflush(stdout);
	scanf("%s",s+1);
	return s[1]=='b';
}
inline int half(int k,bool t){
	ri l=0,r=1e9;
	while(k--){
		ri mid=l+r>>1;
		if(t?ask(mid,0):ask(0,mid))r=mid-1;
		else l=mid+1;
	}
	return l+r>>1;
}
int n;
signed main(){
	scanf("%d",&n);
	printf("0 %d %d 0\n",half(n>>1,0),half(n+1>>1,1));
	fflush(stdout);
	return 0;
}