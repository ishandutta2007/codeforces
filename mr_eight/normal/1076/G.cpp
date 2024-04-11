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
const int MAXN=200002,B=300;
int n,m,q,cnt;
int L[MAXN],R[MAXN],in[MAXN],pre[MAXN],rpre[MAXN],jmp[MAXN],rjmp[MAXN];
bool tag[MAXN],a[MAXN];
inline int getpre(int pos){
	if(pos<=0)return 0;
	while(pos&&(tag[in[pos]]?rpre[pos]:pre[pos])<L[in[pos]])pos=R[in[pos]-1];
	return (tag[in[pos]]?rpre[pos]:pre[pos]);
}
inline int getjmp(int pos){
	return pos>0?(tag[in[pos]]?rjmp[pos]:jmp[pos]):0;
}
inline void split(int pos){
	if(tag[pos])F(i,L[pos],R[pos])a[i]^=1;
	tag[pos]=0;
	pre[L[pos]]=(a[L[pos]]?L[pos]-1:L[pos]);
	rpre[L[pos]]=(a[L[pos]]?L[pos]:L[pos]-1);
	if(a[L[pos]]){
		jmp[L[pos]]=L[pos]-1;
		rjmp[L[pos]]=L[pos]-m;
	}else{
		rjmp[L[pos]]=L[pos]-1;
		jmp[L[pos]]=L[pos]-m;
	}
	F(i,L[pos]+1,R[pos]){
		if(a[i])pre[i]=pre[i-1],rpre[i]=i;
		else rpre[i]=rpre[i-1],pre[i]=i;
	}
	F(i,L[pos]+1,R[pos]){
		if(a[i]){
			jmp[i]=jmp[i-1];
			rjmp[i]=(i-m<L[pos]?i-m:(rpre[i-m]<L[pos]?L[pos]-1:rjmp[rpre[i-m]]));
		}else{
			jmp[i]=(i-m<L[pos]?i-m:(pre[i-m]<L[pos]?L[pos]-1:jmp[pre[i-m]]));
			rjmp[i]=rjmp[i-1];
		}
	}
}
int main(){
	cin>>n>>m>>q;++m;
	F(i,1,n)a[i]=(read()&1)^1;
	cnt=(n+B-1)/B;
	F(i,1,cnt){
		L[i]=R[i-1]+1;
		R[i]=min(n,R[i-1]+B);
		F(j,L[i],R[i])in[j]=i;
		split(i);
	}
	in[n+1]=cnt+1;
	L[cnt+1]=n+1;
	F(iakioi,1,q){
		if(read()==1){
			int l=read(),r=read();
			if(read()&1){
				if(in[l]==in[r]){
					F(i,l,r)a[i]^=1;
					split(in[l]);
				}else{
					if(l!=L[in[l]]){
						while(l!=L[in[l]])a[l++]^=1;
						split(in[l]-1);
					}
					if(r!=R[in[r]]){
						while(r!=R[in[r]])a[r--]^=1;
						split(in[r]+1);
					}
					F(i,in[l],in[r])tag[i]^=1;	
				}
				
			}
		}else{
			int l=read(),r=read();
			while(in[l]<in[r])r=getpre(getjmp(r));
			r=getpre(r);
			while(r>l)r=getpre(r-m);
			write(1+(l==r),'\n');
		}
	}
    return 0;
}