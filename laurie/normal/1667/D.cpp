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
#include <random>
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
int n,c[200002];
bool f[200002],g[200002];//f ou,g ji
vector<int>gr[200002];
inline bool dfs(int pos,int fa){
	c[pos]=gr[pos].size()-(pos!=1);
	for(int i:gr[pos])if(i!=fa){
		if(!dfs(i,pos))return false;;
	}
	int x=0,y=0;
	for(int i:gr[pos])if(i!=fa){
		if(!f[i]&&!g[i]){
			return false;
		}
		if(!g[i])++x;
		if(!f[i])++y;
	}
	/*
	if(x+x>c[pos]+1)return false;
	if(y+y>c[pos]+2)return false;
	if(y+y>c[pos]&&)
	*/
	if(pos!=1){
		if(x+x<=c[pos]&&y+y<=c[pos]+1){
			f[pos]=true;
		}
		if(x+x<=c[pos]+2&&y+y<c[pos]){
			g[pos]=true;
		}
	//	cerr<<pos<<" "<<f[pos]<<" "<<g[pos]<<endl;
	}else{
		if(x+x<=c[pos]+1&&y+y<=c[pos])return true;
		else return false;
	}
	return true;
}
inline void getans(int pos,int fa,bool now){
	if(pos==1)puts("YES");
	if(now==0){
		vector<int>qwq,qaq,quq;
		for(int i:gr[pos])if(i!=fa){
			if(!g[i])qwq.push_back(i);
			else if(!f[i])qaq.push_back(i);
			else quq.push_back(i);
		}
		bool p=(pos!=1)^(c[pos]+1&1);
		while(qwq.size()||qaq.size()||quq.size()){
			if(p){
				if(qaq.size()){
					getans(qaq.back(),pos,1);
					qaq.pop_back();
				}else{
					getans(quq.back(),pos,1);
					quq.pop_back();
				}
			}else{
				if(qwq.size()){
					getans(qwq.back(),pos,0);
					qwq.pop_back();
				}else{
					getans(quq.back(),pos,0);
					quq.pop_back();
				}
			}
			p^=1;
		}
		if(pos!=1)write(pos,' '),write(fa,'\n');
	}else{
		vector<int>qwq,qaq,quq;
		for(int i:gr[pos])if(i!=fa){
			if(!g[i])qwq.push_back(i);
			else if(!f[i])qaq.push_back(i);
			else quq.push_back(i);
		}
		bool p=(pos!=1)^(c[pos]+1&1);
		while(qwq.size()+qaq.size()+quq.size()>1){
			if(p){
				if(qaq.size()){
					getans(qaq.back(),pos,1);
					qaq.pop_back();
				}else{
					getans(quq.back(),pos,1);
					quq.pop_back();
				}
			}else{
				if(qwq.size()){
					getans(qwq.back(),pos,0);
					qwq.pop_back();
				}else{
					getans(quq.back(),pos,0);
					quq.pop_back();
				}
			}
			p^=1;
		}
		if(pos!=1)write(pos,' '),write(fa,'\n');
		p^=1;
		if(qwq.size())getans(qwq.front(),pos,p);
		if(qaq.size())getans(qaq.front(),pos,p);
		if(quq.size())getans(quq.front(),pos,p);
	}
}
int main() {
	F(iakioi,1,read()){
		read(n);
		F(i,1,n)gr[i].clear(),f[i]=g[i]=0;
		F(i,2,n){
			int x=read(),y=read();
			gr[x].push_back(y);
			gr[y].push_back(x);
		}
		if(dfs(1,0))getans(1,0,0);
		else puts("NO");
	}
	return 0;
}