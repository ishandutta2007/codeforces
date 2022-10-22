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
inline ll read() {
	ll x=0;
	bool fu=0;
	char ch=0;
	while(ch>'9'||ch<'0') {
		ch=getchar();
		if(ch=='-')fu=1;
	}
	while(ch<='9'&&ch>='0') x=(x*10-48+ch),ch=getchar();
	return fu?-x:x;
}ll n,a[100002],qwq;
int main(){
    cin>>n;
    if(n==1){qwq=read();
    	cout<<1<<' '<<1<<endl;
    	cout<<0<<endl;
    		cout<<1<<' '<<1<<endl;
    	cout<<0<<endl;
    		cout<<1<<' '<<1<<endl;
    	cout<<-qwq<<endl;return 0;
	}
    qwq=(LLONG_MAX/4/n)*n;
    F(i,1,n)cin>>a[i];
    cout<<1<<' '<<n-1<<endl;
    F(i,1,n-1){
    	cout<<(a[i]+qwq)%n*(n-1)<<' ';
    	a[i]+=(a[i]+qwq)%n*(n-1);
	}cout<<endl<<n<<' '<<n<<endl;
	cout<<-a[n]<<endl;
	cout<<1<<' '<<n<<endl;
	F(i,1,n-1){
		cout<<-a[i]<<' ';
	}cout<<0<<' ';
    return 0;
}
/*
1
-1000000000000000009
*/