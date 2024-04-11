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
#define ll long long //long long
#define ms multiset
#define F(i,a,b) for(register int i=a,i##end=b;i<=i##end;++i)
#define UF(i,a,b) for(register int i=a,i##end=b;i>=i##end;--i)
#define openf(a) freopen(#a".in","r",stdin);freopen(#a".out","w",stdout)
#define re register
#define int long long
#define ri re int
#define il inline
#define cp complex<double>
#define endl '\n'//
//#pragma GCC optimize(3)
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
int n,mod,w[100002],q,l,r;
map<int,int>phi;
inline int go(int num){
	int rt=num;
	for(int i=2;i*i<=num;i++){
		if(num%i==0)rt=rt*(i-1)/i;
		while(num%i==0)num/=i;
	}if(num>1)rt=rt*(num-1)/num;
	return rt;
}
inline int pw(int x,int p,int mod){
	bool flag=0;
	int rt=1;
	while(p){
		if(p&1){if(rt*x>=mod)flag=1;
			rt=rt*x%mod;
		}if(x*x>=mod)flag=1;
		x=x*x%mod,p>>=1;
	}
	return rt+flag*mod;
}
inline int dfs(int pos,int mod){
	if(pos>r||mod==1)return 1;
	return pw(w[pos],dfs(pos+1,phi[mod]),mod);
}
signed main(){
    cin>>n>>mod;
    l=mod;
    phi[1]=1;
    while(l>1)phi[l]=go(l),l=phi[l];
    F(i,1,n)w[i]=read();
    cin>>q;
    while(q--){
    	l=read(),r=read();
    	cout<<dfs(l,mod)%mod<<endl;
	}
    return 0;
}