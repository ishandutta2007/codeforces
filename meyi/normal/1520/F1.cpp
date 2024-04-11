#include<bits/stdc++.h>
using namespace std;
#define ri register int
#define DEBUG(k...) fprintf(stderr,k)
typedef long long ll;
template<class T>inline bool chmax(T &x,const T &y){return x<y?x=y,true:false;}
template<class T>inline bool chmin(T &x,const T &y){return x>y?x=y,true:false;}
const int maxn=2e5+10;
int a[maxn],k,m,n,t_case;
inline void ask(int l,int r){
	printf("? %d %d\n",l,r);
	fflush(stdout);
}
inline void half(int l,int r,int k){
	if(l==r){
		printf("! %d\n",l);
		fflush(stdout);
		exit(0);
	}
	ri mid=l+r>>1;
	ask(1,mid);
	ri tmp;
	scanf("%d",&tmp);
	if(tmp<=mid-k)half(l,mid,k);
	else half(mid+1,r,k);
}
int main(){
	scanf("%d%d%d",&n,&t_case,&k);
	half(1,n,k);
	return 0;
}