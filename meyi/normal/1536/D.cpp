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
	inline void add(int k,T v){
		for(;k<=mx_idx;k+=lowbit(k))c[k]=max(c[k],v);
	}
	inline T query(int k){
		ri ret=0;
		for(;k;k^=lowbit(k))ret=max(ret,c[k]);
		return ret;
	}
};
BIT<int>c1,c2;
template<typename T>
struct FWT{
	T c[maxn];
	int mx_idx;
	inline void add(int k,T v){
		for(;k<=mx_idx;k+=lowbit(k))c[k]+=v;
	}
	inline T query(int k){
		ri ret=0;
		for(;k;k^=lowbit(k))ret+=c[k];
		return ret;
	}
};
FWT<int>c3,c4;
int a[maxn],b[maxn],bl,m,n,t_case,x[maxn],y[maxn];
int main(){
	scanf("%d",&t_case);
	while(t_case--){
		scanf("%d",&n);
		for(ri i=1;i<=n;++i){
			scanf("%d",a+i),b[i]=a[i];
			c1.c[i]=c2.c[i]=c3.c[i]=c4.c[i]=0;
		}
		sort(b+1,b+n+1);
		bl=unique(b+1,b+n+1)-b-1;
		c1.mx_idx=c2.mx_idx=c3.mx_idx=c4.mx_idx=bl;
		bool flag=false;
		for(ri i=1;i<=n;++i){
			a[i]=lower_bound(b+1,b+bl+1,a[i])-b;
			ri tmp1=c1.query(a[i]-1);
			x[i]=tmp1+c3.query(a[i]-1)-x[tmp1];
			c1.add(a[i],i),c3.add(a[i],1);
			ri tmp2=c2.query(bl-a[i]);
			y[i]=tmp2+c4.query(bl-a[i])-y[tmp2];
			c2.add(bl-a[i]+1,i),c4.add(bl-a[i]+1,1);
			if(x[i]>=i||y[i]>=i){
				flag=true;
				break;
			}
			x[i]=c3.query(a[i]);
			y[i]=c4.query(bl-a[i]+1);
		}
		puts(flag?"NO":"YES");
	}
	return 0;
}