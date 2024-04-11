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
#include <random>
#define F(i,a,b) for(int i=a,i##end=b;i<=i##end;++i)
#define vector basic_string
#define pii pair<int,int>
using namespace std;
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
inline int up(int x){
	if(x==1)return 1;
	return 2<<(31-__builtin_clz(x-1));
}
char s[1000002];
bool vis[1000002];
int n;
vector<pair<int,int> >res;
vector<int>p;
inline void orz(){
	F(i,1,n)vis[i]=false;
	for(auto i:res)F(j,i.first,i.second)vis[j]=true;
	int tot=res.size();
	F(i,1,n)if(!vis[i])++tot;
	write(tot,'\n');
	F(i,1,n)if(!vis[i])write(i,' '),write(i,'\n');
	for(auto i:res)write(i.first,' '),write(i.second,'\n');
}
inline void solve(int cnt,vector<int>p,int m){
	if(m==cnt<<1){
		if(cnt==4){
			if(p[0]+1==p[1]){
				res.push_back({p[0],p[0]+2});
			}else{
				res.push_back({p[0],p[0]+2});
				res.push_back({p[2],p[2]+1});
			}
		}else{
			solve(cnt>>1,p.substr(0,cnt>>1),m>>1);
			solve(cnt>>1,p.substr(cnt>>1,cnt),m>>1);
		}
		return;
	}
	if(cnt==9){
		if(p[0]+2<p[1]){
			res.push_back({p[0],p[0]+2});
			p.erase(p.begin());
			solve(cnt-1,p,12);
		}else if(p[0]+2==p[1]){
			res.push_back({p[0],p[0]+2});
			p.erase(p.begin()),p.erase(p.begin());
			p.erase(p.begin()+4,p.end());
			solve(4,p,8);
		}else if(p[0]+2==p[2]){
			res.push_back({p[0],p[0]+2});
			p.erase(p.begin(),p.begin()+3);
			solve(6,p,9);
		}else{
			res.push_back({p[0],p[0]+2});
			p.erase(p.begin(),p.begin()+2);
			solve(7,p,10);
		}
		return;
	}
	if(cnt==10){
		solve(4,p.substr(0,4),8);
		solve(6,p.substr(4,10),8);
		return;
	}
	if(m<=cnt*3/2){
		int temp=m-cnt;
		F(i,0,temp-1)res.push_back({p[i<<1],p[i<<1]+1});
		return;
	}
	solve(cnt>>1,p.substr(0,cnt>>1),m>>1);
	solve((cnt+1)>>1,p.substr(cnt>>1,cnt),(m+1)>>1);
}
int main(){
	F(iakioi,1,read()){
		res.clear(),p.clear();
		scanf("%s",s+1);
		n=strlen(s+1);
		if(*max_element(s+1,s+n+1)=='0')puts("-1");
		else{
			int cnt=0;
			F(i,1,n){
				s[i]-='0';
				cnt+=s[i];
				if(s[i])p.push_back(i);
			}
			if(__builtin_popcount(cnt)==1){
				orz();
			}else if(cnt==5){
				if(p[0]+1==p[1]){
					if(p[1]+1==p[2]){
						res.push_back({p[0],p[0]+3});
					}else{
						res.push_back({p[0],p[0]+3});
						res.push_back({p[3],p[3]+1});
					}
				}else{
					res.push_back({p[0],p[0]+1});
					res.push_back({p[1],p[1]+1});
					res.push_back({p[3],p[3]+1});
				}
				orz();
			}else{
				solve(cnt,p,up(cnt));
				orz();
			}
		}
	}
	return 0;
}