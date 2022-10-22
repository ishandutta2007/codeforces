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
#define mod 998244353ll;
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
int t,n,a[100002],c[100002],lp,rp,mmax;
int main(){
    cin>>t;c[0]=INT_MAX;
    while(t--){mmax=INT_MAX;
    	cin>>n;
    	F(i,1,n){
    		a[i]=read();
		}F(i,1,n){
			if(a[i]-a[i-1]<c[i-1]){
				c[i]=max(a[i]-a[i-1],0);
				a[i]-=c[i];
			}else{
				a[i]-=c[i-1];
				c[i]=c[i-1];
			}
		}bool x=0;F(i,1,n-1){
			if(a[i]>a[i+1]){
				printf("NO\n");
				x=1;
				break;
			}
		}if(!x)printf("YES\n");
//		F(i,1,n)cout<<c[i]<<' ';
//		cout<<endl;
	}
    return 0;
}