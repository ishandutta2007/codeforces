#include<bits/stdc++.h>
using namespace std;
#define ri register int
typedef long long ll;
const int maxk=61,maxn=35e3+10;
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,1:0;}
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,1:0;}
template<class T>inline void clear(T *arr,int siz,int val=0){memset(arr,val,sizeof(T)*(siz+1));}
int a[maxn],cnt[maxn],pl=1,pr,sum;
inline void add(int k){if(!cnt[a[k]]++)++sum;}
inline void del(int k){if(!--cnt[a[k]])--sum;}
inline int calc(int l,int r){
	while(pl<l)del(pl++);
	while(pl>l)add(--pl);
	while(pr<r)add(++pr);
	while(pr>r)del(pr--);
	return sum;
}
int f[maxk][maxn];
void solve(int l,int r,int L,int R,int k){
	if(l>r||L>R)return;
	ri mid=l+r>>1,pos=-1,val=-1;
	for(ri i=L;i<=R&&i<mid;++i){
		ri tmp=f[k-1][i]+calc(i+1,mid);
		if(tmp>val)pos=i,val=tmp;
	}
	f[k][mid]=val;
	solve(l,mid-1,L,pos,k);
	solve(mid+1,r,pos,R,k);
}
int k,n;
signed main(){
	scanf("%d%d",&n,&k);
	for(ri i=1;i<=n;++i)scanf("%d",a+i);
	for(ri i=1;i<=k;++i)solve(1,n,0,n-1,i);
	printf("%d",f[k][n]);
	return 0;
}