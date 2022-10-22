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
}
ll n,cnt,t1,t2,mmin[1000002],dp[1000002];
pair<ll,ll>x[1000002];
ll pos[1000002];
int main(){//memset(mmin,0x3f,sizeof(mmin));
    cin>>n;
    F(i,1,n){
    	t1=read(),t2=read();
    	x[i]=make_pair(t1-t2,t1+t2);
    	pos[++cnt]=t1+t2;
	}sort(pos+1,pos+cnt+1);
	cnt=unique(pos+1,pos+cnt+1)-pos-1;	
	F(i,1,n){
		mmin[lower_bound(pos+1,pos+cnt,x[i].second)-pos]=max(mmin[lower_bound(pos+1,pos+cnt,x[i].second)-pos],(ll)(upper_bound(pos+1,pos+cnt,x[i].first)-pos));
	}F(i,1,cnt){
		dp[i]=max(dp[i-1],dp[mmin[i]-1]+1);
	}cout<<dp[cnt];
    return 0;
}