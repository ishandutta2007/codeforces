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
}ll t,a[100002],a2[100002],n,c1,c2,ans;
int main(){
    cin>>t;
    while(t--){
    	cin>>n;
    	F(i,1,n)a[i]=read();
    	sort(a+1,a+n+1);
    	ans=-LLONG_MAX;
    	ans=max(ans,a[n]*a[n-1]*a[n-2]*a[1]*a[2]);
    	ans=max(ans,a[n]*a[n-1]*a[n-2]*a[n-3]*a[n-4]);
    	ans=max(ans,a[n]*a[n-1]*a[n-2]*a[n-3]*a[1]);
    	ans=max(ans,a[n]*a[n-1]*a[3]*a[1]*a[2]);
    	ans=max(ans,a[n]*a[4]*a[3]*a[1]*a[2]);
    	ans=max(ans,a[5]*a[4]*a[3]*a[1]*a[2]);
    	cout<<ans<<endl;
	}
    return 0;
}