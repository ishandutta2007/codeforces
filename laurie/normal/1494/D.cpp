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
int n,a[1002][1002],s[1002],temp[1002],p[1002],f[1002],cnt;
bool tag[1002][1002],fk[1002];
set<int>now;
struct S{
	int x,y;
	bool operator<(const S &b)const{
		return a[x][y]<a[b.x][b.y];
	}bool operator>(const S &b)const{
		return a[x][y]>a[b.x][b.y];
	}
};
inline S ms(int x,int y){
	if(x>y)swap(x,y);
	return (S){x,y};
}
priority_queue<int,vector<S>,greater<S> >q;
stack<int>sta;
#include<assert.h>
int main() {
	cin>>n;
	s[0]=INT_MAX;
	F(i,1,n)F(j,1,n)read(a[i][j]);
	F(i,1,n)s[i]=a[i][i],now.insert(i);
	F(i,1,n)F(j,i,n)if(i!=j)q.push(ms(i,j));cnt=n;
	while(!q.empty()){
		ri x=q.top().x,y=q.top().y;
		q.pop();
		if(fk[x]||fk[y])continue;
		now.insert(++cnt);
		s[cnt]=a[cnt][cnt]=a[x][y];
		now.erase(x);
		now.erase(y);
		fk[x]=fk[y]=1;
		f[x]=f[y]=cnt;
		for(auto i:now){
			if(i!=cnt)a[cnt][i]=a[i][cnt]=a[x][i];
			if(i!=cnt&&a[cnt][i]==s[cnt]){
				fk[i]=1;
				sta.push(i);
				f[i]=cnt;
			}
			else if(i!=cnt)q.push(ms(i,cnt));
		}while(!sta.empty())now.erase(sta.top()),sta.pop();
	}write(cnt,'\n');
	F(i,1,cnt)write(s[i],' ');puts("");
	write(cnt,'\n');
	F(i,1,cnt-1)write(i,' '),write(f[i],'\n');
	return 0;
}