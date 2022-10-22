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
const int MAXN=1000002,MAXM=1000002;
int n,m;
int cnt=1,S,T,head[MAXN],deep[MAXN],to[MAXM<<1],v[MAXM<<1],nxt[MAXM<<1],now[MAXN];
inline void clear(){
	memset(head,0,(n*m+4)<<2);
	memset(deep,0,(n*m+4)<<2);
	memset(to,0,cnt+1<<2);
	memset(v,0,cnt+1<<2);
	memset(nxt,0,cnt+1<<2);
	memset(now,0,(n*m+4)<<2);
	read(n);read(m);
	T=n*m+3;
	cnt=1;
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
vector<int>s[100002],a[100002];
vector<char>d[100002];
vector<bool>vis[100002];
inline int id(int x,int y){
	return (x-1)*m+y;
}
int main(){
	F(iakioi,1,read()){
		clear();
		F(i,0,n+1)s[i].resize(m+2),a[i].resize(m+2),d[i].resize(m+2),vis[i].resize(m+2);
		F(i,0,n+1)F(j,0,m+1){
			if(i&&j&&i<=n&&j<=m)read(s[i][j]);
			else s[i][j]=INT_MAX;
			vis[i][j]=false;
		}
		if((n*m)&1){
			ed(S,n*m+1,1);
		}
		F(i,1,n){
			F(j,1,m){
				if((i+j)&1){
					ed(S,id(i,j),1);
					if(s[i][j]==s[i-1][j])ed(id(i,j),id(i-1,j),1);
					if(s[i][j]==s[i+1][j])ed(id(i,j),id(i+1,j),1);
					if(s[i][j]==s[i][j-1])ed(id(i,j),id(i,j-1),1);
					if(s[i][j]==s[i][j+1])ed(id(i,j),id(i,j+1),1);
					if(s[i][j]>s[i-1][j]||s[i][j]>s[i+1][j]||s[i][j]>s[i][j-1]||s[i][j]>s[i][j+1]){
						ed(id(i,j),n*m+1,1);
					}
				}else{
					ed(id(i,j),T,1);
					if(s[i][j]>s[i-1][j]||s[i][j]>s[i+1][j]||s[i][j]>s[i][j-1]||s[i][j]>s[i][j+1]){
						ed(n*m+1,id(i,j),1);
					}
				}
			}
		}
		if(Dinic()==(n*m+1)/2){
			puts("YES");
			F(i,1,n){
				F(j,1,m){
					if((i+j)&1){
						int x=id(i,j);
						for(int p=head[x];p;p=nxt[p]){
							if(!v[p]&&to[p]&&to[p]<=n*m){
								a[i][j]=s[i][j]-1;
								int t1=(to[p]-1)/m+1,t2=to[p]-(t1-1)*m;
								vis[i][j]=vis[t1][t2]=true;
								a[t1][t2]=1;
								if(t1==i+1)d[i][j]='D',d[t1][t2]='U';
								else if(t1==i-1)d[i][j]='U',d[t1][t2]='D';
								else if(t2==j+1)d[i][j]='R',d[t1][t2]='L';
								else d[i][j]='L',d[t1][t2]='R';
							}
						}
					}
				}
			}
			F(i,1,n)F(j,1,m)if(!vis[i][j]){
				if(s[i][j]>s[i][j-1]){
					d[i][j]='L',a[i][j]=s[i][j]-s[i][j-1];
				}else if(s[i][j]>s[i][j+1]){
					d[i][j]='R',a[i][j]=s[i][j]-s[i][j+1];
				}else if(s[i][j]>s[i-1][j]){
					d[i][j]='U',a[i][j]=s[i][j]-s[i-1][j];
				}else{
					d[i][j]='D',a[i][j]=s[i][j]-s[i+1][j];
				}
			}
			F(i,1,n){
				F(j,1,m)write(a[i][j],' ');
				putchar('\n');
			}
			F(i,1,n){
				F(j,1,m)putchar(d[i][j]),putchar(' ');
				putchar('\n');
			}
		}else puts("NO");
	}
	return 0;
}