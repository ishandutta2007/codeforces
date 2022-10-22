//#include <bits/stdc++.h>
#include <iostream>
#include <iomanip>
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
//#include <random>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/priority_queue.hpp>
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
#define vi vector<int>
#define ull unsigned long long
#define mem0(x) memset(x,0,sizeof(x))
#define mem0x3f(x) memset(x,0x3f,sizeof(x))
using namespace std;
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
	inline void write(T x) {
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
int n,p[200002],m,op[200002],qwq[200002],qaq[200002],temp[200002],col[200002],now,ed[200002];
ll a[200002],pre[200002],tag[200002];
bool vis[200002];
vector<int>vec[200002],kuai;
const int B=500;
inline void dfs(int pos){
	col[pos]=now;
	if(!vis[pos]&&!col[p[pos]])dfs(p[pos]);
	else ed[now]=pos;
}
int main() {
	//freopen("data.txt","r",stdin);freopen("qwq.out","w",stdout);
	cin>>n;
	F(i,1,n)pre[i]=pre[i-1]+read();
	F(i,1,n)read(p[i]);
	cin>>m;
	F(i,1,m)read(op[i]),read(qwq[i]),read(qaq[i]);
	for(int L=1,R;L<=m;L=R+1){
		F(i,1,now)vec[i].clear();
		now=0;kuai.clear();
		R=min(L+B-1,m);
		memset(vis,0,sizeof(vis));
		memset(tag,0,sizeof(tag));
		memset(col,0,sizeof(col));
		F(i,L,R)if(op[i]==3){
			vis[qwq[i]]=vis[qaq[i]]=true;
		}
		F(i,1,n)if(vis[i]){
			++now;
			dfs(p[i]);
		}
		F(i,1,n)if(!col[i]){
			++now;
			dfs(i);
		}
		F(i,1,n)vec[col[i]].push_back(i);
		memset(vis,0,sizeof(vis));
		F(i,L,R){
			if(op[i]==1){
				ll rt=pre[qaq[i]]-pre[qwq[i]-1];//cerr<<tag[1]<<" "<<now<<endl;
				for(int j:kuai){
					rt+=tag[j]*(upper_bound(vec[j].begin(),vec[j].end(),qaq[i])-lower_bound(vec[j].begin(),vec[j].end(),qwq[i]));
				}
				write(rt,'\n');
			}else if(op[i]==2){
				int now=col[qwq[i]],tar=now,v=qaq[i];
				do{
					if(!vis[now])kuai.push_back(now),vis[now]=true;
					tag[now]+=v;//cerr<<v<<endl;
					now=col[p[ed[now]]];
				}while(now!=tar);
			}else{
				swap(p[qwq[i]],p[qaq[i]]);
			}
		}
		F(i,1,n)a[i]=tag[col[i]]+a[i-1];
		F(i,1,n)pre[i]+=a[i];
	}
	return 0;
}