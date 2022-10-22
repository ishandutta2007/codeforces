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
}int n,a[100002],x,tot,ans[100002];
int main(){
    
    cin>>n;
    F(i,1,n){
    	cin>>a[i];
	}sort(a+1,a+n+1);
	int i=0,j=0,d=(n)/2,u=n-d;
	while(a[d-i]==a[d])i++;
	while(a[d+j+1]==a[d])j++;
	i=1,j=d+1;
	F(ii,1,n){
		if(x){
			ans[ii]=a[i];
			x=0;i++;
		}else{
			ans[ii]=a[j];
			x=1;j++;
		}
	}F(i,2,n-1){
		if(ans[i]<ans[i-1]&&ans[i]<ans[i+1])tot++;
		
	}cout<<tot<<endl;
	F(i,1,n)cout<<ans[i]<<' ';
    return 0;
}