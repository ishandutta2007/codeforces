//#include <bits/c++config.h>
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
}ll t,n,cnt[100002],num[100002],v;
bool cmp(int x,int y){
	return x>y;
}
inline bool check(int dis){
	if((cnt[1]-1)*dis+v<=n)return 1;
	else return 0;
}
int main(){
    cin>>t;
    while(t--){
    	cin>>n;v=0;
    	F(i,1,n)cnt[i]=0;
    	F(i,1,n)cnt[read()]++;
    	int l=0,r=n,mid;sort(cnt+1,cnt+n+1,cmp);
    	cnt[0]=cnt[1];
    	F(i,1,n)if(cnt[i]==cnt[i-1])v=i;else break;
    	while(l<r){
    		mid=(l+r)>>1;
    		mid++;
    		if(check(mid))l=mid;
    		else r=mid-1;
		}cout<<l-1<<endl;
	}
    return 0;
}