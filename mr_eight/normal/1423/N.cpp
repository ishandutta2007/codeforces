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
vector<int>to[12502],id[12502];
int vis[12502],num[1000002],n,k,t1,t2,v[12502],fuck[1000002],ccf[1000002];
bool orz[10000002];
inline void play(int x,int y){
	if(y<0){
		ri res=-y;
		F(i,0,to[x].size()-1){if(!res)return;
			if(!vis[to[x][i]]){
				--num[id[x][i]];
				vis[to[x][i]]=1;
				--res;
			}
			
		}
	}else{
		ri res=y;
		F(i,0,to[x].size()-1){if(!res)return;
			if(vis[to[x][i]]){
				++num[id[x][i]];
				vis[to[x][i]]=0;
				--res;
			}
			
		}
	}
}
#include<assert.h>
int main() {
	cin>>n>>k;
	F(i,1,k){
		read(t1);read(t2);fuck[i]=t1,ccf[i]=t2;
		num[i]=1;++v[t1];++v[t2];
		if(t1>t2)swap(t1,t2);
		to[t2].push_back(t1);
		id[t2].push_back(i);
	}
	F(i,1,n){
		int add=0,mns=0;
		F(j,0,to[i].size()-1){
			if(vis[to[i][j]])++add;
			else ++mns;
			orz[v[to[i][j]]]=1;
		}
		F(j,v[i]-mns,v[i]+add){
			if(!orz[j]){
				play(i,j-v[i]);
				v[i]=j;
				break;
			}
		}
		F(j,0,to[i].size()-1){
			orz[v[to[i][j]]]=0;
		}
	}int tot=0;
	F(i,1,n)tot+=vis[i];write(tot,'\n');
	F(i,1,n)if(vis[i])write(i,' ');if(tot)putchar('\n');
	F(i,1,k)write(fuck[i],' '),write(ccf[i],' '),write(num[i],'\n');
	return 0;
}