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
using namespace std;
int t[200002],f[200002],size[200002],a[200002],type,
dp[200002],head[200002],big[200002],root=1,n,m,t1,t2,t3,num;
vector<int>c[200002],g[200002];
bool vis[200002];
namespace seg{
	int mmax[400002],sum[400002];
	bool clear[400002];
	#define mid ((l+r)>>1)
	inline void add(int pos,int l,int r,int q,int w){
		if(l==r){
			mmax[pos]+=w;
			sum[pos]+=w;
			return;
		}
		if(clear[pos]){
			mmax[pos<<1]=mmax[pos<<1|1]=-1;
			sum[pos<<1]=l-mid-1;
			sum[pos<<1|1]=mid-r;
			clear[pos<<1]=clear[pos<<1|1]=true;
			clear[pos]=false;
		}
		if(q<=mid)add(pos<<1,l,mid,q,w);
		else add(pos<<1|1,mid+1,r,q,w);
		sum[pos]=sum[pos<<1]+sum[pos<<1|1];
		mmax[pos]=max(mmax[pos<<1]+sum[pos<<1|1],mmax[pos<<1|1]);
	}
	inline void erase(int pos,int l,int r,int ql,int qr){
		if(ql<=l&&qr>=r){
			clear[pos]=true;
			mmax[pos]=-1;
			sum[pos]=l-r-1;
			return;
		}
		if(clear[pos]){
			mmax[pos<<1]=mmax[pos<<1|1]=-1;
			sum[pos<<1]=l-mid-1;
			sum[pos<<1|1]=mid-r;
			clear[pos<<1]=clear[pos<<1|1]=true;
			clear[pos]=false;
			return;
		}
		if(ql<=mid)erase(pos<<1,l,mid,ql,qr);
		if(qr>mid)erase(pos<<1|1,mid+1,r,ql,qr);
		sum[pos]=sum[pos<<1]+sum[pos<<1|1];
		mmax[pos]=max(mmax[pos<<1]+sum[pos<<1|1],mmax[pos<<1|1]);
	}
	inline pii query(int pos,int l,int r,int ql,int qr){
		if(ql<=l&&qr>=r){
			return make_pair(mmax[pos],sum[pos]);
		}
		if(clear[pos]){
			mmax[pos<<1]=mmax[pos<<1|1]=-1;
			sum[pos<<1]=l-mid-1;
			sum[pos<<1|1]=mid-r;
			clear[pos<<1]=clear[pos<<1|1]=true;
			clear[pos]=false;
		}
		if(qr<=mid)return query(pos<<1,l,mid,ql,qr);
		if(ql>mid)return query(pos<<1|1,mid+1,r,ql,qr);
		pii t1=query(pos<<1,l,mid,ql,mid),t2=query(pos<<1|1,mid+1,r,mid+1,qr);
		return make_pair(max(t1.first+t2.second,t2.first),t1.second+t2.second);
	}
	inline int query(int pos){
		int mmax=-1,sum=0;
		while(pos){
			pii temp=query(1,1,n,t[head[pos]],t[pos]);
			mmax=max(mmax,temp.first+sum);
			sum+=temp.second;
			pos=f[head[pos]];
		}
		return mmax;
	}
	inline void modify(int pos){
		erase(1,1,n,t[pos],t[pos]+size[pos]-1);
		int temp=query(f[pos]);
		if(temp>0)add(1,1,n,t[pos],-temp);
	}
}
inline void make_tree(int pos){	
	vis[pos]=1;dp[pos]=dp[f[pos]]+1;
	F(i,0,g[pos].size()-1)
		if(!vis[g[pos][i]]){
			f[g[pos][i]]=pos;
			c[pos].push_back(g[pos][i]);
			make_tree(g[pos][i]);
		}
}
inline void getsize(int pos){
	F(i,0,c[pos].size()-1){
		getsize(c[pos][i]);
		size[pos]+=size[c[pos][i]];
	}size[pos]++;
}
void dfs(int pos,bool isbig){
	if(isbig)head[pos]=head[f[pos]];
	else head[pos]=pos;
	t[pos]=++num;
	ri mmax=0,mpos=0;
	F(i,0,c[pos].size()-1){
		if(size[c[pos][i]]>mmax){
			mpos=c[pos][i];
			mmax=size[c[pos][i]];
		}
	}big[pos]=mpos;
	if(c[pos].size())dfs(mpos,1);
	F(i,0,c[pos].size()-1)if(c[pos][i]!=mpos)dfs(c[pos][i],0);
}
int main(){
	root=1;
    cin>>n>>m;
    F(i,2,n){
    	t1=i,t2=read();
    	g[t1].push_back(t2);
    	g[t2].push_back(t1);
	}make_tree(root);
	getsize(root);
	dfs(root,0);
	F(i,1,n)seg::add(1,1,n,i,-1);
	F(i,1,m){
		int opt=read();
		if(opt==1)seg::add(1,1,n,t[read()],1);
		else if(opt==2)seg::modify(read());
		else{
			int qwq=seg::query(read());
			if(qwq>=0)puts("black");
			else puts("white");
		}
	}
    return 0;
}