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
#define mod 1000000007
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
	char _n_u_m_[40];
	template<class T>
	inline void write(T x ) {
		if(x==0){
			putchar('0');
			return;
		}
		T tmp = x > 0 ? x : -x ;
		if( x < 0 ) putchar('-') ;
		ri cnt = 0 ;
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
const long long MAXN=200002;
long long n,t1,t2,f[MAXN],a[MAXN],sz[MAXN],phi[MAXN],dfn[MAXN],cnt,
fa[MAXN][20],d[MAXN],num,pri[MAXN],temp[MAXN],disfa[MAXN],mu[MAXN];
vector<long long>gg[MAXN],c[MAXN],cc[MAXN];
bool vis[MAXN],mark[MAXN];
ll g[MAXN],qwq[MAXN],ff[MAXN],ans;
inline bool cmp(long long x,long long y){
	return dfn[x]<dfn[y];
}
inline void make_tree(long long pos){
	vis[pos]=sz[pos]=1;ri nxt;
	dfn[pos]=++cnt;d[pos]=d[f[pos]]+1;
	fa[pos][0]=f[pos];
	F(i,1,18)fa[pos][i]=fa[fa[pos][i-1]][i-1];
	F(i,0,gg[pos].size()-1){
		nxt=gg[pos][i];
		if(!vis[nxt]){
			f[nxt]=pos;
			c[pos].push_back(nxt);
			make_tree(nxt);
			sz[pos]+=sz[nxt];
		}
	}
}
inline long long lca(long long x,long long y){
	if(d[x]>d[y]){
		UF(i,18,0){
			if(d[fa[x][i]]>=d[y])x=fa[x][i];
		}
	}if(d[y]>d[x]){
		UF(i,18,0){
			if(d[fa[y][i]]>=d[x])y=fa[y][i];
		}
	}if(x==y)return x;
	UF(i,18,0){
		if(fa[x][i]!=fa[y][i])x=fa[x][i],y=fa[y][i];
	}return f[x];
}
long long sta[MAXN],top;
long long mb[MAXN<<2],orz;
inline void add(long long pos){
	if(!top){
		sta[++top]=pos;
		return;
	}ri l=lca(pos,sta[top]);
	if(l==sta[top]){
		sta[++top]=pos;
		return;
	}while(top>1&&dfn[l]<dfn[sta[top-1]]){
		cc[sta[top-1]].push_back(sta[top]);
		mb[++orz]=(sta[top-1]);
		disfa[sta[top]]=d[sta[top]]-d[sta[top-1]];
		top--;
	}
	disfa[sta[top]]=-d[l]+d[sta[top]];
	cc[l].push_back(sta[top--]);
	mb[++orz]=(sta[top-1]);
	if(l!=sta[top])sta[++top]=l;
	sta[++top]=pos;
}
inline void dfs(long long pos){
	qwq[pos]=a[pos];
	F(i,0,cc[pos].size()-1){
		dfs(cc[pos][i]);
		qwq[pos]+=qwq[cc[pos][i]];
	}qwq[pos]%=mod;
}
inline ll play(long long pos){
	ll rt=0;
	F(i,0,cc[pos].size()-1){
		rt+=play(cc[pos][i]);
	}
	return (rt+qwq[pos]*(qwq[1]-qwq[pos])%mod*disfa[pos])%mod;
}
inline long long pw(long long x,long long p){
    long long res=1;
    for(;p;p>>=1,x=x*x%mod)
        if(p&1)res=res*x%mod;
    return res;
}
inline long long getm(long long top,long long bot) {
	return (top*pw(bot,mod-2))%mod;
}
signed main() {
	cin>>n;
	F(i,1,n)read(a[i]);
	F(i,2,n){
		read(t1);read(t2);
		t1=a[t1];t2=a[t2];
		gg[t1].push_back(t2);
		gg[t2].push_back(t1);
	}make_tree(1);
	memset(a,0,sizeof(a));
	phi[1]=mu[1]=mark[1]=1;
	cnt=0;
	F(i,2,n){
		if(!mark[i]){
			pri[++cnt]=i;
			phi[i]=i-1;
			mu[i]=-1;
		}
		for(register int j=1;i*pri[j]<=n;++j){
			mark[i*pri[j]]=1;
			if(i%pri[j]){
				phi[i*pri[j]]=phi[i]*phi[pri[j]];
				mu[i*pri[j]]=-mu[i];
			}else{
				phi[i*pri[j]]=phi[i]*pri[j];
				break;
			}
		}
	}
	F(i,1,n){
		cnt=0;
		for(ri j=i;j<=n;j+=i){
			temp[++cnt]=j;
			a[j]=phi[j];
		}
		sort(temp+1,temp+cnt+1,cmp);
		if(i!=1)sta[top=1]=1;
		else top=0;
		F(i,1,cnt){
			add(temp[i]);
		}
		while(top>1)cc[sta[top-1]].push_back(sta[top]),mb[++orz]=sta[top-1],disfa[sta[top]]=d[sta[top]]-d[sta[top-1]],--top;
		dfs(1);
		g[i]=play(1);
		F(i,1,cnt)a[temp[i]]=0;
		while(orz)cc[mb[orz--]].clear();
	}
	F(i,1,n){
		F(j,1,n/i){
			ff[i]+=mu[j]*g[i*j];
		}ff[i]%=mod;
		ans+=ff[i]*getm(i,phi[i]);
		ans%=mod;
	}
	write(getm((2*ans%mod+mod)%mod,1ll*n*(n-1)%mod));
	return 0;
}