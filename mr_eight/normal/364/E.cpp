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
int n,m,k;
char a[2502][2502];
ll ans;
struct A{
	int a[8],cnt;
	inline A operator+(A b){
		A rt;rt.cnt=0;
		a[cnt+1]=b.a[b.cnt+1]=-114514;
		int x=1,y=1;
		while((x<=cnt||y<=b.cnt)&&rt.cnt<=k){
			if(a[x]>b.a[y])rt.a[++rt.cnt]=a[x++];
			else rt.a[++rt.cnt]=b.a[y++];
		}
		return rt;
	}
}orz[2502];
struct B{
	int a[8],cnt;
	inline B operator+(B b){
		B rt;rt.cnt=0;
		a[cnt+1]=b.a[b.cnt+1]=114514;
		int x=1,y=1;
		while((x<=cnt||y<=b.cnt)&&rt.cnt<=k){
			if(a[x]<b.a[y])rt.a[++rt.cnt]=a[x++];
			else rt.a[++rt.cnt]=b.a[y++];
		}
		return rt;
	}
}sto[2502];
inline void calc(A a,B b){
	//puts("--------debug--------");F(i,0,k)cerr<<a.a[i]<<" ";cerr<<endl;F(i,0,k)cerr<<b.a[i]<<" ";puts("");puts("---------end---------");
	F(i,1,k){
		ans+=1ll*(a.a[i-1]-a.a[i])*(b.a[k+1-i]-b.a[k-i]);
	}
}
inline A qwq(A a,int l,int r){
	F(i,a.cnt+1,k)a.a[i]=l-1;
	a.a[0]=r;
	return a;
}
inline B qaq(B a,int l,int r){
	F(i,a.cnt+1,k)a.a[i]=r+1;
	a.a[0]=l;
	return a;
}
inline void solve(int L,int R,int l,int r){
	if(L==R&&l==r){
		ans+=(a[L][l]=='0'&&k==1)+(a[L][l]=='1'&&k==2);
		return;
	}
	if(R-L>r-l){
		int mid=(L+R)>>1;
		solve(L,mid,l,r);
		solve(mid+1,R,l,r);
		F(i,l,r){
			orz[i].cnt=0;
			UF(j,mid,L){
				if(a[j][i]=='1'){
					orz[i].a[++orz[i].cnt]=j;
					if(orz[i].cnt==k)break;
				}
			}
		}
		F(i,l,r){
			sto[i].cnt=0;
			F(j,mid+1,R){
				if(a[j][i]=='1'){
					sto[i].a[++sto[i].cnt]=j;
					if(sto[i].cnt==k)break;
				}
			}
			calc(qwq(orz[i],L,mid),qaq(sto[i],mid+1,R));
		}
		F(i,l,r){
			A x=orz[i];B y=sto[i];
			F(j,i+1,r){
				x=x+orz[j];y=y+sto[j];
				calc(qwq(x,L,mid),qaq(y,mid+1,R));
			}
		}
	}else{
		int mid=(l+r)>>1;
		solve(L,R,l,mid);
		solve(L,R,mid+1,r);
		F(i,L,R){
			orz[i].cnt=0;
			UF(j,mid,l){
				if(a[i][j]=='1'){
					orz[i].a[++orz[i].cnt]=j;
					if(orz[i].cnt==k)break;
				}
			}
		}
		F(i,L,R){
			sto[i].cnt=0;
			F(j,mid+1,r){
				if(a[i][j]=='1'){
					sto[i].a[++sto[i].cnt]=j;
					if(sto[i].cnt==k)break;
				}
			}
			calc(qwq(orz[i],l,mid),qaq(sto[i],mid+1,r));
		}
		F(i,L,R){
			A x=orz[i];B y=sto[i];
			F(j,i+1,R){
				x=x+orz[j];y=y+sto[j];
				calc(qwq(x,l,mid),qaq(y,mid+1,r));
			}
		}
	}
}
int main(){
	cin>>n>>m>>k;++k;
	F(i,1,n)scanf("%s",a[i]+1);
	solve(1,n,1,m);
	cout<<ans;
    return 0;
}