//#include <bits/stdc++.h>
#include <iostream>
#include <iomanip>
#include <math.h>
#include <cmath>
#include <algorithm>
#include <climits>
#include <functional>
#include <cstring>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cstdio>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <bitset>
#include <complex>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
#define itn int
#define nit int
#define ll long long
#define ms multiset
#define F(i,a,b) for(register int i=a,i##end=b;i<=i##end;++i)
#define UF(i,a,b) for(register int i=a,i##end=b;i>=i##end;--i)
#define re register
#define ri re int
#define il inline
#define pii pair<int,int>
#define cp complex<double>
//#pra gma G CC opti mize(3)
using namespace std;
using std::bitset;
//using namespace __gnu_pbds;
const double Pi=acos(-1);
namespace fastIO {
	template<class T>
	inline void read(T &x) {
		x=0;
		bool fu=0;
		char ch=0;
		while(ch>'9'||ch<'0') {
			ch=getchar();
			if(ch=='-')fu=1;
		}
		while(ch<='9'&&ch>='0') x=(x*10-48+ch),ch=getchar();
		if(fu)x=-x;
	}
	inline int read() {
		int x=0;
		bool fu=0;
		char ch=0;
		while(ch>'9'||ch<'0') {
			ch=getchar();
			if(ch=='-')fu=1;
		}
		while(ch<='9'&&ch>='0') x=(x*10-48+ch),ch=getchar();
		return fu?-x:x;
	}
	char _n_u_m_[40];
	template<class T>
	inline void write(T x ) {
		if(x==0){
			putchar('0');
			return;
		}
		T tmp = x > 0 ? x : -x ;
		if( x < 0 ) putchar('-') ;
		register int cnt = 0 ;
		while( tmp > 0 ) {
			_n_u_m_[ cnt ++ ] = tmp % 10 + '0' ;
			tmp /= 10 ;
		}
		while( cnt > 0 ) putchar(_n_u_m_[ -- cnt ]) ;
	}
	template<class T>
	inline void write(T x ,char ch) {
		write(x);
		putchar(ch);
	}
}
using namespace fastIO;
const int MAXN=102,MAXM=502;
int cnt=1,S,T,head[MAXN],deep[MAXN],to[MAXM<<1],v[MAXM<<1],nxt[MAXM<<1],now[MAXN<<1];
inline void clear(){
	cnt=1;
	S=0;
	T=101;
	memset(head,0,sizeof(head));
	memset(deep,0,sizeof(deep));
	memset(to,0,sizeof(to));
	memset(v,0,sizeof(v));
	memset(nxt,0,sizeof(nxt));
	memset(now,0,sizeof(now));
}
inline void add(int x,int y,int vv){
	to[++cnt]=y;
	nxt[cnt]=head[x];
	head[x]=cnt;
	v[cnt]=vv;
}inline void ed(int x,int y,int vv){
	add(x,y,vv);
	add(y,x,0);
}
inline bool bfs(){
	memset(deep,0,sizeof(deep));
	deep[S]=1;
	queue<int>q;
	q.push(S);
	ri h;
	while(!q.empty()){
		h=q.front();
		q.pop();
		now[h]=head[h];
		for(ri i=head[h];i;i=nxt[i]){
			if(!deep[to[i]]&&v[i]>0){
				q.push(to[i]);
				deep[to[i]]=deep[h]+1;
			}
		}
	}return deep[T];
}
inline int dfs(int pos,int mmax){
	if(pos==T)return mmax;
	ri rt=0;
	for(ri i=now[pos];i&&mmax;i=nxt[i]){
		now[pos]=i;
		if(deep[to[i]]==deep[pos]+1&&v[i]>0){
			ri k=dfs(to[i],min(mmax,v[i]));			
			if(k==0)deep[to[i]]=INT_MAX-2;
			else{
				rt+=k;
				mmax-=k;
				v[i]-=k;
				v[i^1]+=k;
			}
		}
	}return rt;
}
inline int Dinic(){
	ri rt=0;
	while(bfs()){
		rt+=dfs(S,INT_MAX);
	}return rt;
}
int n,num[10],m,orz[10][10],x,y;
char qwq[10],qaq[10];
struct bcj{
	int fa[7];
	bcj(){
		F(i,1,m)fa[i]=i;
	}
	inline int findf(int x){
		return (fa[x]==x)?x:(fa[x]=findf(fa[x]));
	}
	inline void merge(int x,int y){
		fa[findf(x)]=findf(y);
	}
}fuck;
pii ak[7];
int akioi;
#define ed orz
inline bool check(){
	F(i,1,m)F(j,i,m)if(orz[i][j]<0)return 0;
	F(i,1,(1<<m)-1){
		ri tot=0,flag=0;
		F(j,1,m)if(i>>j-1&1){
			tot+=num[j];flag|=num[j];
			F(k,j,m)if(i>>k-1&1){
				tot-=orz[j][k];
			}
		}
		if(tot<=0&&flag)return 0;
	}
	return 1;
}
#define now iakioi
int boss[10],now[10];
int main(){
	cin>>n;
	int x=1;
	while(x*10<=n){
		num[++m]=x*9;
		boss[m]=x;
		now[m]=x*10-1;
		x*=10;
	}
	num[++m]=n-x+1;
	boss[m]=x;
	now[m]=n;
	F(i,1,n-1){
		scanf("%s",qwq);scanf("%s",qaq);
		x=strlen(qwq);y=strlen(qaq);
		++orz[min(x,y)][max(x,y)];
	}
	n=m;
	if(!check()){
		puts("-1");
		return 0;
	}
	fuck=bcj();
	F(i,1,m)while(now[i]>boss[i]){
		F(j,1,m){
		--num[i];
		--orz[min(i,j)][max(i,j)];////cerr<<now[i]<<' '<<boss[j]<<' '<<ed[1][1]<<' '<<ed[1][2]<<' '<<num[1]<<' '<<num[2]<<endl;
		if(check()){
			write(now[i]--,' ');
			write(boss[j],'\n');
			break;
		}else{
			++num[i];++orz[min(i,j)][max(i,j)];
		}
		
		}
	}
	F(i,1,m)F(j,i+1,m)if(orz[i][j])write(boss[i],' '),write(boss[j],'\n');
	return 0;
}