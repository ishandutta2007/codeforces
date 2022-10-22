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
	template<class T,class... Args>
	inline void read(T& t,Args&... args) {
		read(t);
		read(args...);
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
#define mod 1000000007
int S[202][202],f[100002][202],g[100002][202],ans[200002];
const int MAXN=100002;
int n,t1,t2,fa[MAXN],k;
vector<int>gg[MAXN],c[MAXN];
bool vis[MAXN];
int sz[MAXN];
inline void make_tree(int pos){
	vis[pos]=sz[pos]=1;ri nxt;
	F(i,0,gg[pos].size()-1){
		nxt=gg[pos][i];
		if(!vis[nxt]){
			fa[nxt]=pos;
			c[pos].push_back(nxt);
			make_tree(nxt);
			sz[pos]+=sz[nxt];
		}
	}
}
inline void dfs(int pos){
	int now=1;
	f[pos][0]=1;
	F(i,0,c[pos].size()-1){
		int nxt=c[pos][i];
		dfs(nxt);
		memcpy(g[pos],f[pos],sizeof(g[pos]));
		F(j,1,min(sz[nxt],k))f[pos][j]=((f[pos][j]+f[nxt][j])%mod+f[nxt][j-1])%mod;
		f[pos][0]=(f[pos][0]+f[nxt][0])%mod;
		F(x,0,min(k,now)){
			F(y,0,min(k-x,sz[nxt])){
				int mul=1ll*g[pos][x]*f[nxt][y]%mod;
				ans[x+y]=(ans[x+y]+mul)%mod;
				ans[x+y+1]=(ans[x+y+1]+mul)%mod;
				f[pos][x+y]=(f[pos][x+y]+mul)%mod;
				f[pos][x+y+1]=(f[pos][x+y+1]+mul)%mod;
			}
		}
		now+=sz[nxt];
	}
}
int main(){
    cin>>n>>k;
    S[0][0]=1;
    F(i,1,k){
    	F(j,1,i){
    		S[i][j]=(S[i-1][j-1]+1ll*j*S[i-1][j])%mod;
		}
	}
    F(i,2,n){
    	t1=read(),t2=read();
    	gg[t1].push_back(t2);
    	gg[t2].push_back(t1);
	}make_tree(1);
	dfs(1);
	long long res=0,fac=1;
	F(j,1,k){
		fac=fac*j%mod;
		res+=S[k][j]*fac%mod*ans[j]%mod;
	}cout<<res%mod;
    return 0;
}