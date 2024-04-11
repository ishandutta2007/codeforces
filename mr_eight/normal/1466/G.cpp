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
#define mod 1000000007ll
#define base 1331ll
#pragma GCC optimize(3)
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
int n,q,k,t1,t2;
string s[102],t,w,temp;
ll pre[100002][30],pw[5000002],h[5000002],hw,inv[5000002],bpw[5000002];
int f[4000002];
char qwq[5000002];
inline ll fuck_ccf() {

	ll ans=0;
	t1=-1;
	F(i,0,100) {
		if(s[i].length()>=w.size()) {
			t1=i;
			break;
		}
	}
	if(t1<0||t1>k)return 0;
	ri K;
	temp='#'+s[t1]+'#'+s[t1];
	if(t1==k) {
		ri K,cnt=0;
		temp='#'+s[t1]+'#'+s[t1];
		f[0]=-1,f[1]=0;
		F(i,1,w.size()-1) {
			f[i+1]=0;
			K=i;
			while(K>=0) {
				if(w[i]==w[f[K]]) {
					f[i+1]=f[K]+1;
					break;
				} else K=f[K];
			}
		}
		strcpy(qwq,temp.c_str());
		temp='#'+s[t1];
		register int i=1,j=0;
		while(i<temp.size())
			if(j==w.size()) {
				cnt++;
				j=f[j];
			} else if(j==-1||temp[i]==w[j])i++,j++;
			else j=f[j];
		if(j==w.size())cnt++;
		return cnt;
	}


	f[0]=-1,f[1]=0;
	F(i,1,w.size()-1) {
		f[i+1]=0;
		K=i;
		while(K>=0) {
			if(w[i]==w[f[K]]) {
				f[i+1]=f[K]+1;
				break;
			} else K=f[K];
		}
	}
	strcpy(qwq,temp.c_str());
	F(ii,0,25) {

		qwq[s[t1].size()+1]=ii+'a';
		ri cnt=0;
		register int i=s[t1].size()+2-w.size(),j=0;
		while(i<=s[t1].size()+w.size())
			if(j==w.size()) {
				cnt++;
				j=f[j];
			} else if(j==-1||qwq[i]==w[j])i++,j++;
			else j=f[j];
		if(j==w.size())cnt++;
		if(t1)ans+=cnt*(pre[k-1][ii]-pre[t1-1][ii])%mod*inv[n-k+1];
		else ans+=cnt*(pre[k-1][ii])%mod*inv[n-k+1];
		ans%=mod;//cerr<<temp<<' '<<cnt<<endl;
	}
	temp='#'+s[t1];
	ri cnt=0;
	register int i=1,j=0;
	while(i<temp.size())
		if(j==w.size()) {
			cnt++;
			j=f[j];
		} else if(j==-1||temp[i]==w[j])i++,j++;
		else j=f[j];
	if(j==w.size())cnt++;
	ans+=cnt*pw[k-t1];
	ans%=mod;
	return (ans+mod)%mod;
}
int main() {
	pw[0]=bpw[0]=1;
	inv[0]=1;
	F(i,1,5e6)pw[i]=pw[i-1]*2%mod,inv[i]=inv[i-1]*(1000000007/2+1)%mod,bpw[i]=bpw[i-1]*1331%mod;
	cin>>n>>q>>s[0]>>t;
	F(i,0,n-1) {
		if(s[i].size()<1000000) {
			s[i+1]=s[i]+t[i]+s[i];
		} else break;
	}
	pre[0][t[0]-'a']=pw[n];
	F(i,1,n) {
		F(j,0,25) {
			if(t[i]-'a'!=j)pre[i][j]=pre[i-1][j];
			else pre[i][j]=(pre[i-1][j]+pw[n-i])%mod;
		}
	}
	ri orzsto=0;
	while(q--) {
		read(k);
		cin>>w;
		write(fuck_ccf(),'\n');
		if((++orzsto)%1000==0) {
			if(clock()>1900) {
				cout<<q;
				return 0;
			}
		}
	}
	return 0;
}