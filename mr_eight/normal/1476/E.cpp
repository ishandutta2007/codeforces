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
		if(x==0) {
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
const int MAXN=1000002,MAXM=5000002;
int S,T,head[MAXN],deep[MAXN],to[MAXM<<1],v[MAXM<<1],nxt[MAXM<<1],now[MAXN<<1],n,m,k,in[100002];
int p[5000002],mmin[100002];
inline int h(char s[]) {
	int res=0;
	F(i,0,k-1)res*=27,res+=s[i];
	return res;
}
char x[100002][5],y[100002][5];
vector<int>g[100002],ttt;
bool vis[100002],pl[100002],flag;
int pw[5]= {1,27,27*27,27*27*27,27*27*27*27};
inline void dfs(ri h,ri pos,ri i) {
	if(pos==-1) {
		if(!p[h])return;
		if(p[h]==i){
			flag=1;
			return;
		};
		g[i].push_back(p[h]);
		in[p[h]]++;
		return;
	}
	dfs(h%pw[pos]+h/pw[pos+1]*pw[pos+1],pos-1,i);
	dfs(h,pos-1,i);
}
int ans[100002],qwqwq[100002],cnt;
set<int>sss;
queue<int>q;
int main() {
	ri orz=0;
	cin>>n>>m>>k;
	F(i,1,n) {
		scanf("%s",x[i]);
		F(j,0,k-1)if(x[i][j]>='a'&&x[i][j]<='z')x[i][j]-='a'-1;
		else x[i][j]=0;
		p[h(x[i])]=i;
	}
	F(i,1,m) {
		scanf("%s",y[i]);
		ri temp=read();
		flag=0;
		F(j,0,k-1)if(y[i][j]>='a'&&y[i][j]<='z')y[i][j]-='a'-1;
		else y[i][j]=0;
		dfs(h(y[i]),k-1,temp);
		if(!flag){
			puts("NO");return 0;
		}
		if(!pl[temp])pl[temp]=1,orz++;
	}
//	F(i,1,n){
		//F(j,0,g[i].size()-1)cout<<g[i][j]<<' ';cout<<endl;
//	}
	F(i,1,n)if(in[i]==0)q.push(i),qwqwq[++cnt]=i;
	while(!q.empty()){
		ri pos=q.front();
		F(i,0,g[pos].size()-1){
			in[g[pos][i]]--;
			if(in[g[pos][i]]==0){
				q.push(g[pos][i]);
				qwqwq[++cnt]=g[pos][i];
			}
		}q.pop();
		
	}if(cnt==n){
		puts("YES");
		F(i,1,n)write(qwqwq[i],' ');
		
	}else puts("NO");
	cerr<<"\nqwqwqwq";
	return 0;
}