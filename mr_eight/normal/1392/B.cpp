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
}ll t,n,k,a[200002],mmin,mmax,q;
int main(){
    cin>>t;
    while(t--){
    	cin>>n>>k;
    	mmin=INT_MAX,mmax=-INT_MAX;
    	F(i,1,n){
    		a[i]=read();
    		mmin=min(mmin,a[i]);
    		mmax=max(mmax,a[i]);
		}k--;
		q=mmax-mmin;
		F(i,1,n){
			a[i]=mmax-a[i];
		}if(k%2==0){
			F(i,1,n)cout<<a[i]<<' ';
		}else{
			F(i,1,n)cout<<q-a[i]<<' ';
		}cout<<endl;
	}
    return 0;
}