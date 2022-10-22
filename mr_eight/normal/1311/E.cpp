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
int f[5002],tot,d[5002],now,n;
inline void build(int pos){
    if(pos>n)return;
    if(pos==(-pos&pos))now=max(now,pos);
    f[pos]=(pos>>1);
    d[pos]=d[f[pos]]+1;
    tot-=d[pos];
    build(pos<<1);build(pos<<1|1);
}
inline void orz(){
    puts("YES");
    F(i,2,n)write(f[i],' ');
    putchar('\n');
}
int main() {
    d[0]=-1;
    F(iakioi,1,read()){
        memset(f,0,sizeof(f));
        read(n);read(tot);now=0;
        build(1);
        if(tot<0){
            puts("NO");continue;
        }
        if(tot==0){
            orz();continue;
        }
        ri i=n;
        while(114514){
            while(i&&i==(-i&i))--i;
            if(i==0){
                puts("NO");break;
            } 
            if(tot<=d[now]-d[i]+1){
                F(qwq,1,d[now]-d[i]+1-tot)now=f[now];
                f[i]=now;
                orz();break;
            }else{
                tot-=d[now]-d[i]+1;
                f[i]=now;
                d[i]=d[now]+1;
                now=i;
            }
            --i;
        }
    }
	return 0;
}