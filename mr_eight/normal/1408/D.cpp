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
#define pii pair<int,int>
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
}int n,m,q[2000002],pos,ans=INT_MAX;
pii rb[2002],x[2002];
int main(){
    cin>>n>>m;
    F(i,1,n){
    	rb[i]=make_pair(read(),read());
	}F(j,1,m){
		x[j]=make_pair(read(),read());
	}
	F(i,1,n){
		F(j,1,m){
			if(rb[i].first<=x[j].first&&rb[i].second<=x[j].second){
				q[-rb[i].first+x[j].first]=max(q[-rb[i].first+x[j].first],-rb[i].second+x[j].second+1);
			}
		}
	}
	UF(i,1000000,0){
		pos=max(pos,q[i]);
		ans=min(ans,i+pos);
		
	}cout<<ans;
    return 0;
}