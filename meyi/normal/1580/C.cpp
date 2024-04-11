#include<bits/stdc++.h>
using namespace std;
#define ri register int
#define DEBUG(k...) fprintf(stderr,k)
typedef long long ll;
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,true:false;}
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,true:false;}
const int maxn=2e5+10,maxp=510;
int ex[maxp][maxp],ksum[maxp],lim,lst[maxn],m,n,sum1[maxn],sum2[maxp],x[maxn],y[maxn];
inline void modify_small(int k,int v){
	ri len=x[k]+y[k];
	for(ri i=lst[k]+x[k];i<lst[k]+len;++i)ex[len][i%len]+=v;
}
inline void modify_big(int k,int v){
	ri len=x[k]+y[k];
	for(ri i=lst[k];i+x[k]<=m;i+=len){
		sum1[i+x[k]]+=v,sum2[(i+x[k])/lim]+=v;
		if(i+len<=m)sum1[i+len]-=v,sum2[(i+len)/lim]-=v;
	}
}
inline int query_small(int k){
	ri ret=0;
	for(ri i=1;i<=lim;++i)ret+=ex[i][k%i];
	return ret;
}
inline int query_big(int k){
	ri ret=0;
	for(ri i=0;i<=k;i+=lim){
		if(i+lim>k)for(ri j=i;j<=k;++j)ret+=sum1[j];
		else ret+=sum2[i/lim];
	}
	return ret;
}
signed main(){
	scanf("%d%d",&n,&m);
	lim=sqrt(m);
	for(ri i=1;i<=n;++i)scanf("%d%d",x+i,y+i);
	for(ri i=1;i<=m;++i){
		ri op,k;
		scanf("%d%d",&op,&k);
		if(op&1)lst[k]=i;
		ri len=x[k]+y[k];
		if(len<=lim)modify_small(k,(op&1)?1:-1);
		else modify_big(k,(op&1)?1:-1);
		printf("%d\n",query_small(i)+query_big(i));
	}
	return 0;
}