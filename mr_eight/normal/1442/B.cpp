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
#define openf(a) freopen(#a".in","r",stdin);freopen(#a".out","w",stdout)
#define re register
#define ri re int
#define il inline
#define cp complex<double>
#define mod 998244353
//#pra gma G CC opti mize(3)
using namespace std;
using std::bitset;
//using namespace __gnu_pbds;
const double Pi=acos(-1);
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
int t,l[200002],r[200002],n,k,v[200002],ans,a[200002],b[200002];
bool tag[200002];
inline void solve() {n=read();
		k=read();v[n+1]=n+1;
//memset(tag,0,sizeof(tag));
	tag[0]=tag[n+1]=1;
	F(i,1,n) {
		a[i]=read();
		v[a[i]]=i;
		l[i]=i-1
		     ;
		r[i]=i+1;
	}
	F(i,1,k) {
		b[i]=read();
		tag[v[b[i]]]=1;
	}
	F(qwq,1,k) {ri i=v[b[qwq]];
		tag[i]=0;
		if(tag[l[i]]&&tag[r[i]]) {
			F(qaq,qwq,k)tag[v[b[qaq]]]=0;
			tag[0]=tag[n+1]=0;
			printf("0\n");
			return;
		}
		if(tag[l[i]]) {
			r[i]=r[r[i]];
			l[r[i]]=i;
		}else if(tag[r[i]]){
			l[i]=l[l[i]];
			r[l[i]]=i;
		}else{
			ans=ans*2%mod;
			l[i]=l[l[i]];
			r[l[i]]=i;
		}
	}
	tag[0]=tag[n+1]=0;
	printf("%d\n",ans);
}
int main() {
	cin>>t;
	while(t--) {
		ans=1;
		solve();
		
	}
	return 0;
}