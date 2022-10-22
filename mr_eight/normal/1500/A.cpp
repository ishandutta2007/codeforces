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
int n,a[5000002],b[5000002],v[5000002],cnt[5000002],ak[5000002],fkd[5000002];
int l[5000002],m;
int main() {
	cin>>n;F(i,1,n)read(v[i]),cnt[v[i]]++;	
	ri tot=0;
	F(i,1,5000000){
		if(cnt[i]>3){
			ri flag=0;puts("YES");
			F(j,1,n){
				if(v[j]==i){
					flag++;
					write(j,' ');
				}if(flag==4)return 0;
			}
		}
		if(cnt[i]>1){
			if(!tot)tot=i;
			else{
				puts("YES");int flag=0,flag2=0,temp1,temp2,temp3,temp4;
				F(j,1,n){
					
					if(v[j]==tot&&flag<2){
						flag++;
						if(flag==1)temp3=j;
						else temp4=j;
					}else if(v[j]==i&&flag2<2){
						flag2++;
						if(flag2==1)temp1=j;
						else temp2=j;
					}
				}
				write(temp1,' ');write(temp3,' ');write(temp2,' ');write(temp4);while(clock()<800);
				return 0;
			}
		}
	}
	F(i,1,n){
		if(ak[v[i]]){
			fkd[i]=1;
			a[v[i]+v[i]]=ak[v[i]];b[v[i]+v[i]]=i;
		}ak[v[i]]=i;
	}F(i,1,n)if(!fkd[i])l[++m]=i;
	F(ii,1,m){
		F(jj,ii+1,m){ri i=l[ii],j=l[jj];
			if(!a[v[i]+v[j]]){
				a[v[i]+v[j]]=i;
				b[v[i]+v[j]]=j;
			}else{
				puts("YES");
				write(a[v[i]+v[j]],' ');write(b[v[i]+v[j]],' ');
				write(i,' ');write(j);
				return 0;
			}
		}
	}
	puts("NO");
	return 0;
}