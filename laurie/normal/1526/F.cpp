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
int qwq,qaq,a[114514],n;
vector<pii >vec;
struct tp{
	int a,b,c;
};
inline int rd(){
	int rt=(1ll*rand()*(RAND_MAX+1)+rand())%n;
	if(rt==0)rt=n;
	return rt;
}
inline tp getrd(){
	while(true){
		ri x=rd(),y=rd(),z=rd();
		if(x==y||x==z||y==z);
		else return tp{x,y,z};
	}
}
inline int query(tp t){
	putchar('?');putchar(' ');
	write(t.a,' ');
	write(t.b,' ');
	write(t.c,'\n');
	fflush(stdout);
	return read();
}
int main() {
	srand(114514);
	F(iakioi,1,read()){
		read(n);
		qaq=n/3;
		qwq=n-qaq;
		--qaq;
		tp temp;
		while(true){
			temp=getrd();
			if(query(temp)>=qwq){
				break;
			}
		}
		while(true){
			int pos=0;
			while(true){
				pos=rd();
				if(pos!=temp.a&&pos!=temp.b&&pos!=temp.c)break;
			}
			if(query(tp{temp.a,temp.b,pos})<=qaq){
				qwq=temp.a,qaq=temp.b;
				break;
			}
			if(query(tp{temp.c,temp.b,pos})<=qaq){
				qwq=temp.c,qaq=temp.b;
				break;
			}
			if(query(tp{temp.a,temp.c,pos})<=qaq){
				qwq=temp.a,qaq=temp.c;
				break;
			}
		}
		F(i,1,n){
			if(i!=qwq&&i!=qaq){
				vec.push_back(make_pair(query(tp{i,qwq,qaq}),i));
			}
		}
		sort(vec.begin(),vec.end());
		qwq=vec.back().second;
		vec.pop_back();
		qaq=vec.back().second;
		vec.clear();
		a[qwq]=1;
		a[qaq]=2;
		F(i,1,n){
			if(i!=qwq&&i!=qaq){
				a[i]=query(tp{i,qwq,qaq})+2;
			}
		}
		putchar('!');putchar(' ');
		if(a[1]<a[2]){
			F(i,1,n)write(a[i],' ');
			putchar('\n');
			fflush(stdout);
		}else{
			F(i,1,n)write(n-a[i]+1,' ');
			putchar('\n');
			fflush(stdout);
		}
		if(read()==-1){
			printf("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
			while(1.0*clock()/CLOCKS_PER_SEC<=4);
			return 0;
		}
	}
	return 0;
}