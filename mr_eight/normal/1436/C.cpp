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
#define mod 1000000007ll
#define ri re int
#define il inline
#define cp complex<double>
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
inline char readc(){
	register char c;
	while((c=getchar())==' '||c=='\n');
	return c;
}ll n,x,f[100002],pos,l,r,mid,s,b;
long long pow(long long x,long long p)
{
    long long res=1;
    for(;p;p>>=1,x=x*x%mod)
        if(p&1)res=res*x%mod;
    return res;
}
long long getm(long long top,long long bot) {
	return (top*pow(bot,mod-2))%mod;
}
 
ll A(int m,int n){if(n<m)return 0;
	return getm(f[n],f[n-m]%mod);
}
int main(){f[0]=1;
	F(i,1,100000)f[i]=i*f[i-1]%mod;
    cin>>n>>x>>pos;
    r=n;
    while(l<r){
    	mid=(l+r)/2;
    	if(mid<=pos){
    		l=mid+1;
    		if(mid!=pos){
				s++;
			}
		}else{
			r=mid;
			b++;
		}
	}cout<<A(b,n-x)*A(s,x-1)%mod*f[n-b-s-1]%mod;
    return 0;
}