#include<bits/stdc++.h>
using namespace std;
#define ri register int
typedef long long ll;
const int maxn=1e5+10;
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
int d[maxn],m,n,p;
ll f[110][maxn],g[maxn],s[maxn],t[maxn];
int main(){
	scanf("%d%d%d",&n,&m,&p);
	for(ri i=2;i<=n;++i)scanf("%d",d+i),d[i]+=d[i-1];
	for(ri i=1,x;i<=m;++i){
		scanf("%d%lld",&x,t+i);
		t[i]-=d[x];
	}
	sort(t+1,t+m+1);
	for(ri i=1;i<=m;++i)s[i]=s[i-1]+t[i];
	memset(f,0x3f,sizeof f);
	f[0][0]=0;
	for(ri i=1;i<=p;++i){
		for(ri j=1;j<=m;++j)g[j]=f[i-1][j]+s[j];
		q.clear();
		q.push(0);
		for(ri j=1;j<=m;++j){
			while(q.size()>1&&g[q.front(1)]-g[q.front()]<=t[j]*(q.front(1)-q.front()))q.pop_front();
			while(q.size()>1&&(g[j]-g[q.back()])*(q.back()-q.back(1))<=(g[q.back()]-g[q.back(1)])*(j-q.back()))q.pop_back();
			q.push(j);
			f[i][j]=g[q.front()]+(j-q.front())*t[j]-s[j];
		}
	}
	printf("%lld",f[p][m]);
	return 0;
}