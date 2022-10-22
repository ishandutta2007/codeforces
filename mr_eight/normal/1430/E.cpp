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
#define int ll
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
}int c[200002],n,now[200002],ans;
string s;
char cc;
inline int low(int x){
	return -x&x;
}inline void add(int pos,int v){
	while(pos<=n){
		c[pos]+=v;
		pos+=low(pos);
	}
}inline ll query(itn pos){ll rt=0;
	while(pos){
		rt+=c[pos];
		pos-=low(pos);
	}return rt;
}
signed main(){
    cin>>n>>s;
    s.insert(0,"#");
    F(i,1,n){
    	add(i,1);
	}UF(i,s.size()-1,1){
		cc=s[i];
		while(s[now[cc]]!=cc)now[cc]++;
		ans+=query(now[cc])-s.size()+i;
		add(1,1);
		add(now[cc],-1);
		now[cc]++;
	}cout<<ans;
    return 0;
}