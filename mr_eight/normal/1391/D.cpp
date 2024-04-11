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
}int n,m;
string s1,s2,s3;
int go(int type){int cnt=0;
	F(i,0,m-1){
		type=!type;
		if((s1[i]-'0'+s2[i]-'0')%2!=type)cnt++;
	}return cnt;
}int g(int t1,int t2){
	int cnt=0;
	F(i,0,m-1){
		t1=!t1,t2=!t2;
		if((s1[i]-'0'+s2[i]-'0')%2!=t1)cnt++;
		else if((s3[i]-'0'+s2[i]-'0')%2!=t2)cnt++;
	}return cnt;
}
int main(){
    cin>>n>>m;
    if(n>=4&&m>=4){
    	cout<<-1;
    	return 0;
	}if(n==1){
		cout<<0;
		return 0;
	}if(n==2){
		cin>>s1>>s2;
		cout<<min(go(1),go(0));
		return 0;
	}if(n==3){
		cin>>s1>>s2>>s3;
		ri ans=1000000002;
		ans=min(ans,g(1,1));
		ans=min(ans,g(1,0));
		ans=min(ans,g(0,1));
		ans=min(ans,g(0,0));
		cout<<ans;
	}
    return 0;
}