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
}ll t,a,b,c,d,e,f,g,ans1,ans2,ans;
inline ll go(ll cc,ll dd){
	ll rt=0,bb;
	if(e<f){
		rt+=min(b/e,cc);
		bb=b-rt*e;
		return rt+min(bb/f,dd);
	}else{
		rt+=min(b/f,dd);
		bb=b-rt*f;
		return rt+min(bb/e,cc);
	}
}
int main(){
    cin>>t;
    while(t--){ans=0;
    	cin>>a>>b>>c>>d>>e>>f;
    	F(i,0,min(c,a/e)){
    		ans1=i;
    		g=a-i*e;
    		ans2=min(g/f,d);
    		ans=max(ans,ans1+ans2+go(c-ans1,d-ans2));
		}cout<<ans<<endl;
	}
    return 0;
}