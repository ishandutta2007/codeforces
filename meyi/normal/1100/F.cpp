#include<bits/stdc++.h>
using namespace std;
#define ri register int
typedef long long ll;
const int maxn=5e5+10;
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,1:0;}
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,1:0;}
typedef pair<int,int> pii;
#define fi first
#define se second
pii d[maxn][21];
inline void insert(int id,pii k){
	for(ri i=20;~i;--i)
		if((k.fi>>i)&1){
			if(!d[id][i].fi){
				d[id][i]=k;
				return;
			}
			else if(k.se>d[id][i].se)swap(d[id][i],k);
			k.fi^=d[id][i].fi;
		}
}
inline int getmx(int l,int r){
	ri ret=0;
	for(ri i=20;~i;--i)
		if(l<=d[r][i].se)
			ckmax(ret,ret^d[r][i].fi);
	return ret;
}
int a[maxn],m,n;
int main(){
	scanf("%d",&n);
	for(ri i=1;i<=n;++i){
		memcpy(d[i],d[i-1],sizeof d[i-1]);
		scanf("%d",a+i);
		insert(i,{a[i],i});
	}
	scanf("%d",&m);
	while(m--){
		ri l,r;
		scanf("%d%d",&l,&r);
		printf("%d\n",getmx(l,r));
	}
	return 0;
}