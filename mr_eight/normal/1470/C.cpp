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
#define mid 1250
using namespace fastIO;
ll num[100002],res,now,temp,nxt[100002],n,k,cnt;int c[100002];
bool vis[100002],orz[100002];
inline int query(int);
inline bool ok(int pos,int qwq){
	if(pos>=qwq&&pos+qwq<n)return query(pos+qwq+1)-query(pos-qwq)<qwq+qwq+1;
	else{
		F(i,pos-qwq,qwq+pos){
			if(vis[(i+n)%n]==0)return 1;
		}
	}return 0;
}
inline void add(int pos){
	while(pos<=n){
		c[pos]++;
		pos+=(-pos&pos);
	}
}inline int query(int pos){
	ri rt=0;
	while(pos){
		rt+=c[pos];
		pos-=(-pos&pos);
	}return rt;
}
int main() {
	srand(998244353);cin>>n>>k;
	F(i,0,n-1)num[i]=k;
	cout<<"? 1"<<endl;
	cout.flush();
	cin>>temp;
	F(qwq,1,999) {

			nxt[1]+=num[0];
			F(j,1,n-1) {
				nxt[j-1]+=num[j]/2;
				nxt[j+1]+=num[j]-num[j]/2;
			}
			nxt[0]+=nxt[n];
			nxt[n]=0;
			memcpy(num,nxt,sizeof(num));
			memset(nxt,0,sizeof(nxt));
		now+=min(2000-rand()%500,qwq<<1);now%=n;
		while(!ok(now,qwq))now+=qwq+qwq+-1+rand()%3,now%=n;
		
		cout<<"? "<<now+1<<endl;
		cout.flush();
		cin>>temp;


			F(i,0,n-1) {

				if(num[i]!=temp&&vis[(now-i+n)%n]==0) {
					vis[(now-i+n)%n]=1;
add((now-i+n)%n+1);
				}
			}
cnt=0;
		F(i,0,n-1){
			if(vis[i]==0)cnt++;
		}if(cnt==1)break;
	}
	F(i,0,n-1) {
		if(!vis[i]) {
			cout<<"! "<<i+1<<endl;
			cout.flush();
			return 0;
		}
	}
	return 0;
}