#include<bits/stdc++.h>
using namespace std;
#define ri register int
#define DEBUG(k...) fprintf(stderr,k)
typedef long long ll;
template<class T>inline bool chmax(T &x,const T &y){return x<y?x=y,true:false;}
template<class T>inline bool chmin(T &x,const T &y){return x>y?x=y,true:false;}
const int maxn=2e5+10;
#define lowbit(k) ((k)&(-k))
template<typename T>
struct BIT{
	T c[maxn];
	int mx_idx;
	inline void clear(){memset(c,0,sizeof(T)*(mx_idx+1));}
	inline void add(int k,T v){
		for(;k<=mx_idx;k+=lowbit(k))c[k]+=v;
	}
	inline T query(int k){
		ri ret=0;
		for(;k;k^=lowbit(k))ret+=c[k];
		return ret;
	}
	inline T query(int l,int r){
		return query(r)-query(l-1);
	}
};
BIT<int>c;
bool vis[maxn];
int k,m,n,t_case;
inline void ask(int l,int r){
	printf("? %d %d\n",l,r);
	fflush(stdout);
}
inline void half(int l,int r,int k){
	if(l==r){
		printf("! %d\n",l);
		vis[l]=true;
		ri d=l-k-c.query(l);
		c.add(l,d+1);
		c.add(l+1,-d);
		fflush(stdout);
		return;
	}
	ri mid=l+r>>1,tmp;
	if(vis[mid])tmp=c.query(mid);
	else{
		ask(1,mid);
		scanf("%d",&tmp);
		if(tmp==-1)exit(1);
		vis[mid]=true;
		ri d=tmp-c.query(mid);
		c.add(mid,d);
		c.add(mid+1,-d);
	}
	if(tmp<=mid-k)half(l,mid,k);
	else half(mid+1,r,k);
}
int main(){
	scanf("%d%d",&n,&t_case);
	c.mx_idx=n;
	while(t_case--){
		scanf("%d",&k);
		half(1,n,k);
	}
	return 0;
}