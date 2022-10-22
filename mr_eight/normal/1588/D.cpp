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
int p[52][12][3],cnt[52][12],m[12],dp[10000002],trans[10000002],lst[12][114][52],n;
char c[12][114];
vector<pii >vec;
inline int id(char c){
	if(c>='a'&&c<='z')return c-'a';
	return c-'A'+26;
}
inline void getans(int pos){
	if(dp[pos]>1)getans(trans[pos]);
	if((pos&63)<=25)putchar('a'+(pos&63));
	else putchar('A'+(pos&63)-26);
}
int main() {
	F(iakioi,1,read()){
		read(n);
		memset(p,0,sizeof(p));memset(cnt,0,sizeof(cnt));mem0(dp);mem0(lst);mem0(trans);
		F(i,1,n){
			scanf("%s",c[i]+1);
			m[i]=strlen(c[i]+1);
			F(j,1,m[i])p[id(c[i][j])][i][++cnt[id(c[i][j])][i]]=j;
			F(j,1,m[i]){
				F(k,0,51)lst[i][j][k]=lst[i][j-1][k];
				lst[i][j][id(c[i][j])]=j;
			}
		}
		vec.clear();
		int N=(1<<n)-1;
		F(i,0,51){
			if(*min_element(cnt[i]+1,cnt[i]+n+1)){
				F(S,0,N){
					int mmin=114514,flag=true;
					F(j,1,n){
						if(S>>(j-1)&1){
							if(cnt[i][j]==2){
								mmin=min(mmin,p[i][j][2]);
							}else{
								flag=false;
								break;
							}
						}else{
							mmin=min(mmin,p[i][j][1]);
						}
					}
					if(flag)vec.push_back(make_pair(mmin,S<<6|i));
				}
			}
		}
		sort(vec.begin(),vec.end());
		for(pii i:vec){
			dp[i.second]=1;
			int S=i.second>>6,c=i.second&63;
			F(j,0,51){
				bool flag=true;
				int SS=0;
				F(k,1,n){
					int temp=lst[k][p[c][k][(S>>(k-1)&1)+1]-1][j];
					if(temp){
						SS|=(temp==p[j][k][2])<<(k-1);
					}else{
						flag=false;
						break;
					}
				}
				if(flag){
					if(dp[i.second]<dp[SS<<6|j]+1)dp[i.second]=dp[SS<<6|j]+1,trans[i.second]=(SS<<6|j);
				}
			}
		}
		int p=max_element(dp,dp+10000001)-dp;
		write(dp[p],'\n');
		if(dp[p])getans(p);putchar('\n');
	}
	return 0;
}
/*
9
4
qwqQAQ
QAQqwq
qwqQAQ
waqQWQ
*/