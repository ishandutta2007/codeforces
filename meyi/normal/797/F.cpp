#include<bits/stdc++.h>
using namespace std;
#define ri int
typedef long long ll;
const int maxn=5010;
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,1:0;}
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,1:0;}
template<class T>inline void clear(T *arr,int siz,int val=0){memset(arr,val,sizeof(T)*(siz+1));}
template<typename T>
struct dq{
	int hd,tl;
	T v[maxn];
	inline dq(){hd=1;}
	inline T front(int ex=0){return v[hd+ex];}
	inline T back(int ex=0){return v[tl-ex];}
	inline void pop_front(){++hd;}
	inline void pop_back(){--tl;}
	inline void push(T k){v[++tl]=k;}
	inline int size(){return tl-hd+1;}
	inline void clear(){hd=1,tl=0;}
};
dq<int>q;
ll f[maxn][maxn],sum[maxn],tot;
int c[maxn],id[maxn],m,n,p[maxn],x[maxn];
int main(){
	scanf("%d%d",&n,&m);
	for(ri i=1;i<=n;++i)scanf("%d",x+i);
	sort(x+1,x+n+1);
	for(ri i=1;i<=m;++i)scanf("%d%d",p+i,c+i),id[i]=i,tot+=c[i];
	if(tot<n)return puts("-1"),0;
	sort(id+1,id+m+1,[&](int x,int y){return p[x]<p[y];});
	clear(f[0],n,0x3f);
	f[0][0]=0;
	for(ri ii=1;ii<=m;++ii){
		ri i=id[ii];
		q.clear();
		q.push(0);
		for(ri j=1;j<=n;++j){
			while(q.size()&&j-q.front()>c[i])q.pop_front();
			sum[j]=sum[j-1]+abs(p[i]-x[j]);
			while(q.size()&&f[ii-1][j]-sum[j]<=f[ii-1][q.back()]-sum[q.back()])q.pop_back();
			q.push(j);
			f[ii][j]=f[ii-1][q.front()]-sum[q.front()]+sum[j];
		}
	}
	printf("%lld",f[m][n]);
	return 0;
}